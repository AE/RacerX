/**
 * racerX_server.c:
 *
 * Author  Abhinay Evani
 *
 */

#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "alarm.h"
#include "control.h"
#include "image.h"

#define PORT 8888               // video out port

CvCapture*	capture;         // required to interact with the camera using opencv
IplImage*	img0;
IplImage*	img1;
CvMat*          compmat;
int	is_data_ready = 0;       // informs the stream server that the data is ready
int     is_info_ready = 0;       // informs the stream server that the telemetry info is ready
int     new_set_of_commands = 0; // informs the controller that a new set of commands have arrived
int	serversock, clientsock, commandsock, commandclient; // corresponding sockets
int     camnum = 0;              // stores the camera number and can me manipulated as required
                                 // it is not possible for the client to switch to another camera mid-stream yet
char    commandBuffer[50][20];   // stores upto a 49 commands where each of them are of 20 characters length
                                 // commandbuffer[0] should always be set to the number of commands
char    replyBuffer[100];         // buffer to store replies
extern double  telemetry[4];

// defined in control.h for command list queue
COMMAND_DATA *command_list_head = NULL;
COMMAND_DATA *command_list_tail = NULL;

// locks to ensure thread safe operations
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;      
pthread_mutex_t mutex_c = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_cr = PTHREAD_MUTEX_INITIALIZER;

void* streamServer(void* arg);          
void* commandServer(void* arg);
void* controller(void* arg);
void  command_list_manager(void);
void  quit(char* msg, int retval);

int main(int argc, char** argv)
{
        (void) signal(SIGALRM, command_list_manager);
        
        pthread_t 	thread_s, thread_c, thread_cr;
	char	key;

	if (argc == 2) {
		capture = cvCaptureFromFile(argv[1]);
	} else {
		capture = cvCaptureFromCAM(camnum);
	}

	if (!capture) {
		quit("cvCapture failed", 1);
	}

	img0 = cvQueryFrame(capture);
        int p[3] = {CV_IMWRITE_JPEG_QUALITY, 80, 0};
        
        cvNamedWindow("stream_server", CV_WINDOW_AUTOSIZE);

	/* run the streaming server as a separate thread */
	if (pthread_create(&thread_s, NULL, streamServer, NULL)) {
		quit("pthread_create failed.", 1);
	}

        /* run the command server as a separate thread */
	if (pthread_create(&thread_c, NULL, commandServer, NULL)) {
		quit("pthread_create failed.", 1);
	}

        /* run the command server as a separate thread */
	if (pthread_create(&thread_cr, NULL, controller, NULL)) {
		quit("pthread_create failed.", 1);
	}

	while(key != 'q') {
		/* get a frame from camera */
		img0 = cvQueryFrame(capture);
		if (!img0) break;

		img0->origin = 0;

		/**
		 * compress the image and copy it to 
		 * the image and telemetry packet (see image.c)
                 * thread safe
		 */
		pthread_mutex_lock(&mutex);
                compmat = compress_image(&img1, img0, p);
                if((img1 == NULL) || (compmat == NULL))
                    quit("Failed to compress image.\n", 1);
                
                // copy Image data into INT_PKT
                if(img1->imageSize < MAX_IMGSIZE)
                {
                    packetData.pkt.imageSize = img1->imageSize;
                    packetData.pkt.imageWidth = img1->width;
                    packetData.pkt.imageHeight = img1->height;
                    packetData.pkt.imageDepth = IMG_TYPE;
                    packetData.pkt.imageChannels = img1->nChannels;

                    int i;
                    for(i = 0; i < img1->imageSize; i++)
                        packetData.pkt.imageData[i] = img1->imageData[i];
                    packetData.pkt.imageData[i] = '\0';
                }
                
		pthread_mutex_unlock(&mutex);

                // release the compressed matrix
                // as we no longer need it
                cvReleaseMat(&compmat);

		/* also display the video here on server */
		cvShowImage("stream_server", img0);
		key = cvWaitKey(30);
	}

	/* user has pressed 'q', terminate the streaming server */
	if (pthread_cancel(thread_s)) {
		quit("pthread_cancel failed.", 1);
	}
        
        if (pthread_cancel(thread_c)) {
		quit("pthread_cancel failed.", 1);
	}

        if (pthread_cancel(thread_cr)) {
		quit("pthread_cancel failed.", 1);
	}
	/* free memory */
	cvDestroyWindow("stream_server");
	quit(NULL, 0);
}

/**
 * stream server
 * this function waits for a client to connect, and sends grayscale images
 **/ 
void* streamServer(void* arg)
{
	// blocking SIGLARM in the streaming thread
        int s;
        sigset_t set;
        sigemptyset(&set);
        sigaddset(&set, SIGALRM);
        s = pthread_sigmask(SIG_BLOCK, &set, NULL);
        if (s != 0) quit("Failed to block signal SIGALRM in streamserver\n", 1);

        struct sockaddr_in server;

	/* make this thread cancellable using pthread_cancel() */
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

        /* open socket */
	if ((serversock = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
		quit("socket() failed", 1);
	}

	/* setup server's IP and port */
	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = INADDR_ANY;
	
	/* bind the socket */
	if (bind(serversock, (const void*)&server, sizeof(server)) == -1) {
		quit("bind() failed", 1);
	}

        /* wait for connection */
	if (listen(serversock, 10) == -1) {
		quit("listen() failed.", 1);
	}

	/* accept a client */
	if ((clientsock = accept(serversock, NULL, NULL)) == -1) {
		quit("accept() failed", 1);
	}

	/* the size of the data to be sent */
	int packetsize = sizeof(INT_PKT);
	int bytes, i;
        //UDP_INT_PKT packet_buffer[ceil(num_udp_pkts_ratio)];

	/* start sending images */
	while(1) 
	{
		pthread_mutex_lock(&mutex);
                // copy telemetry data into INT_PKT (see image.c)
                if(is_info_ready)
                {
                    packetData.pkt.telemetry[0] = telemetry[0];
                    packetData.pkt.telemetry[1] = telemetry[1];
	    	    packetData.pkt.telemetry[2] = telemetry[2];
                    packetData.pkt.telemetry[3] = telemetry[3];
                    
                }

                bytes = send(clientsock, packetData.bytes, packetsize, 0);
		pthread_mutex_unlock(&mutex);
                         
		/* if something went wrong, restart the connection */
		if (bytes != packetsize) {
			fprintf(stderr, "Connection on stream server closed.\n");
			close(clientsock);

			if ((clientsock = accept(serversock, NULL, NULL)) == -1) {
				quit("accept() failed", 1);
			}
		} 
 
		/* have we terminated yet? */
		pthread_testcancel();

		/* no, take a rest for a while */
		usleep(1000);
	}
}

/**
 * command server
 * this function accepts commands from the client, and sends out replies as necessary
 **/ 
void* commandServer(void* arg)
{	
        struct sockaddr_in server;

	/* make this thread cancellable using pthread_cancel() */
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

	/* open socket */
	if ((commandsock = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
		quit("socket() failed", 1);
	}

	/* setup server's IP and port */
	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT + 1024);
	server.sin_addr.s_addr = INADDR_ANY;
	
	/* bind the socket */
	if (bind(commandsock, (const void*)&server, sizeof(server)) == -1) {
		quit("bind() failed", 1);
	}

	/* wait for connection */
	if (listen(commandsock, 10) == -1) {
		quit("listen() failed.", 1);
	}

	/* accept a client */
	if ((commandclient = accept(commandsock, NULL, NULL)) == -1) {
		quit("accept() failed", 1);
	}

	/* the size of the data to be sent */
	int buffersize = (int) sizeof commandBuffer;
	int bytes1, bytes2, i, j, k;
        char buffer[50][20];
	
        /* wait for commands */
	while(1) 
	{          
            bytes1 = recv(commandclient, buffer, buffersize, 0);
        
            if(bytes1 == buffersize) 
            {
                /* copy the set of commands received */
                pthread_mutex_lock(&mutex_c);
                
                k = 0;        
                for(i = 0; i < 50; i++)
                {
                    for(j = 0; j <20; j++)
                    {
                        commandBuffer[i][j] = buffer[i][j];
                    }
                }
                new_set_of_commands = 1;
                pthread_mutex_unlock(&mutex_c);

                raise(SIGALRM);
                bytes2 = send(commandclient, replyBuffer, (int) (sizeof replyBuffer), 0);

            }
            else
            {
                fprintf(stderr, "Connection on command server closed.\n");
			close(commandclient);

			if ((commandclient = accept(commandsock, NULL, NULL)) == -1) {
				quit("accept() failed", 1);
			}
            }
	    /* have we terminated yet? */
	    pthread_testcancel();

	    /* no, take a rest for a while */
	    usleep(1000);
	}
}

/**
 * controller
 * this function controls the buggy according to the commands received
 **/ 
void* controller(void* arg)
{
    
    
    while(1) 
    {   
        char cmd;
        int param1;
        double param2;
        long int time_usec = 0;
        int done = 1;

        pthread_mutex_lock(&mutex);
        get_telemetry_info();
        is_info_ready = 1;
        pthread_mutex_unlock(&mutex);
        
        pthread_mutex_lock(&mutex_cr);
        // execute current command
        if(command_list_head != NULL)
        {
            cmd = command_list_head->command;
            param1 = command_list_head->param1;
            param2 = command_list_head->param2;
            done   = command_list_head->done;
            time_usec = command_list_head->time_usec;

            if(!done) command_list_head->done = 1;
        }        
        pthread_mutex_unlock(&mutex_cr);

        if(command_list_head != NULL)
        {

            execute_command(cmd, param1, param2);
            if(!done)
                alarm_hires(time_usec);
        }
                                  
	/* have we terminated yet? */
	pthread_testcancel();

	/* no, take a rest for a while */
	usleep(1000);
    }        
}


/**
 * command_list_manager
 * this function modifies the command list used by the controller according
 * to the commands received
 **/ 
void command_list_manager(void)
{
    if(new_set_of_commands)
    {
        // signal raised by command server
        new_set_of_commands = 0;
        // add new commands to list    
        int i, j;
        pthread_mutex_lock(&mutex_c);
        j = commandBuffer[0][0] - '0';
        pthread_mutex_unlock(&mutex_c);

        for(i = 1; i <= j ; i++) 
        {
            // add command to the command list
            int res;
            COMMAND_DATA *newcommand;
            if((newcommand = malloc(sizeof(COMMAND_DATA))) == NULL) 
            {
                quit("Out of memory", 1);
            }
            newcommand->next = NULL;
            newcommand->done = 0;
            pthread_mutex_lock(&mutex_c);
            res = command_parser(newcommand, commandBuffer[i]);
            pthread_mutex_unlock(&mutex_c);

            if (res != 21)
            {
                free(newcommand);
                sprintf(replyBuffer, "Error: Line %d, char %d.", i, res);
                return;
            }
            else if (i == j)
            {
                sprintf(replyBuffer, " %d command(s) successfully added to the command list queue.", j);
            }

            pthread_mutex_lock(&mutex_cr);
            if(!command_list_head)
            {
                command_list_head = newcommand;
                command_list_tail = newcommand;
            }
            else
            {
                command_list_tail->next = newcommand;
                command_list_tail = newcommand;
            }
            pthread_mutex_unlock(&mutex_cr);
        }

    }
    else
    {
        // signal raised by controller
        // current command has expired move to next
        pthread_mutex_lock(&mutex_cr);
        
        if(command_list_head == command_list_tail)
        {
            command_list_tail = NULL;
        }
        COMMAND_DATA *expired_command;
        expired_command = command_list_head;
        command_list_head = command_list_head->next;
        free(expired_command);

        pthread_mutex_unlock(&mutex_cr);

    }

}

/**
 * this function provides a way to exit nicely from the system
 */
void quit(char* msg, int retval)
{
	if (retval == 0) {
		fprintf(stdout, (msg == NULL ? "" : msg));
		fprintf(stdout, "\n");
	} else {
		fprintf(stderr, (msg == NULL ? "" : msg));
		fprintf(stderr, "\n");
	}

	if (clientsock) close(clientsock);
	if (serversock) close(serversock);
        if (commandsock) close(commandsock);
	if (commandclient) close(commandclient);

	if (capture) cvReleaseCapture(&capture);

	pthread_mutex_destroy(&mutex);
        pthread_mutex_destroy(&mutex_c);
        pthread_mutex_destroy(&mutex_cr);

	exit(retval);
}

