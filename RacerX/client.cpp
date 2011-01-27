/* * * * *Current Issues* * * */
/*
/*  QImage will be lost
/*
/*
* * * * * * * * * * * * * * * */

#include "client.h"
#include <opencv/cv.h>

// see mainwindow.cpp
extern pthread_mutex_t mutex_s;
extern pthread_mutex_t mutex_c;
extern Data clientData;
extern int sock, sockfd;

extern char serverIP[15];
extern int commandPort;
extern int streamPort;

// number of udp packets to receive for one frame of
// image and telemetry data
float num_udp_pkts_ratio = (double) sizeof(INT_PKT) / DATA_CHUNK_SIZE;

Client::Client()
{

}

int Client::connect(void)
{

    //Initialize stream and control threads.
    if(pthread_create(&thread_s, NULL, startStream, NULL))
    {
        return -1;
    }

    if(pthread_create(&thread_c, NULL, startControl, NULL))
    {

        return -1;
    }

    return 0;
}

int Client::disconnect(void)
{

        //Cancel stream and control threads.
        if(pthread_cancel(thread_s))
        {
            return -1;
        }

        if(pthread_cancel(thread_c))
        {
            return -1;
        }

        if(sock) ::close(sock);
        if(sockfd) ::close(sockfd);

        cvWaitKey(30);

        return 0;
}

void Client::streamThread(void)
{
    struct sockaddr_in connection;

    /* Make this thread cancellable using pthread_cancel(). */
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

    /* create socket */
    if ((sock = ::socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        //quit("socket() failed.", 1);
    }

    /* Setup server parameters. */
    memset(&connection, 0, sizeof(connection));
    connection.sin_family = AF_INET;
    connection.sin_addr.s_addr = htonl(INADDR_ANY);
    connection.sin_port = htons(streamPort);

    /* connect to server */
    if (::connect(sock, (struct sockaddr*)&connection, sizeof(connection)) < 0) {
//    quit("connect() failed.", 1);
    }

    int packetSize = sizeof(INT_PKT);
    char sockData[packetSize];
    int i, j, k, bytes;

    /* Start receiving images */
    while(1)
    {

        for(i = 0; i < packetSize; i = i + bytes )
        {
            if((bytes = ::recv(sock, sockData + i, packetSize - i, 0)) == -1)
            {
                break;
            }

        }

        // copy packet data into the packetData structure in client's image object
        for(i = 0; i < packetSize; i++)
            clientData.imgobj.packetData.bytes[i] = sockData[i];
        if(i < packetSize) clientData.imgobj.packetData.bytes[i] = '\0';

        // create a new image to store the compressed image data
        IplImage *compImage;
        compImage = cvCreateImage(cvSize(clientData.imgobj.packetData.pkt.imageWidth, clientData.imgobj.packetData.pkt.imageHeight),
                                         clientData.imgobj.packetData.pkt.imageDepth, clientData.imgobj.packetData.pkt.imageChannels);
        cvZero(compImage);

        // copy the data received into the newly created image
        for (i = 0, k = 0; i < compImage->height; i++) {
           for (j = 0; j < compImage->width; j++) {
              ((uchar*)(compImage->imageData + i * compImage->widthStep))[j] = clientData.imgobj.packetData.pkt.imageData[k++];
           }
        }

        // create a new image to store the decompressed image data
        IplImage *decompImage = NULL;
        CvMat* compmat;

        /*thread safe. */
        pthread_mutex_lock(&mutex_s);

        // decompress the image data received and store it in decompImage
        // compmat only stores return value of the compressed CvMat type
        // it does not have any memory allocated and should not be released
        if((compmat = clientData.imgobj.decompress_image(&decompImage, compImage)) != NULL)
        {
            // if img already has memory allocated release it
            if(clientData.imgobj.img) clientData.imgobj.freeIplImage();
            // reallocate memory for img and clone the new image into img
            clientData.imgobj.img = cvCloneImage(decompImage);
        }
        // convert the decompressed IplImage into QT's QImage format
        clientData.imgobj.cvToQt(0);

        clientData.telemetry[0] = clientData.imgobj.packetData.pkt.telemetry[0];
        clientData.telemetry[1] = clientData.imgobj.packetData.pkt.telemetry[1];
        clientData.telemetry[2] = clientData.imgobj.packetData.pkt.telemetry[2];
        clientData.telemetry[3] = clientData.imgobj.packetData.pkt.telemetry[3];
        clientData.isDataReady = 1;

        pthread_mutex_unlock(&mutex_s);

        // release the images created
        if(compImage) cvReleaseImage(&compImage);
        if(decompImage) cvReleaseImage(&decompImage);

        /* Have we terminated yet? */
        pthread_testcancel();

        /* No. Sleep */
        usleep(3000);
   }
}

void* Client::startStream(void *arg)
{
    static_cast<Client*>(arg)->streamThread();
}

void Client::controlThread(void)
{
    int i, bytes;
    struct sockaddr_in connection;

    /* Make this thread cancellable using pthread_cancel(). */
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

    /* Initialize parameters for command socket */
    sockfd = ::socket(PF_INET, SOCK_STREAM, 0);

    memset(&connection, 0, sizeof(connection));
    connection.sin_family = AF_INET;
    connection.sin_addr.s_addr = htonl(INADDR_ANY);
    connection.sin_port = htons(streamPort+1024);

    ::connect(sockfd, (struct sockaddr*)&connection, sizeof(connection));

    int commandsize = (int) (sizeof clientData.commandBuffer);
    int replysize   = (int) (sizeof clientData.reply);

    /* Send out commands when available and retrieve replies from the server */
    while(1)
    {
        if(clientData.isCommandReady)
        {
            pthread_mutex_lock(&mutex_c);

            bytes = 0;


            if(bytes = ::send(sockfd, clientData.commandBuffer,  commandsize, 0) == -1)
            {
                break;
            }

            clientData.isCommandReady = 0;

            bytes = 0;
            for(i = 0; i < replysize; i = i + bytes)
            {
                if((bytes = ::recv(sockfd, clientData.reply, replysize, 0)) == -1)
                {
                    break;
                }
            }
            clientData.isReplyReady = 1;
            pthread_mutex_unlock(&mutex_c);
        }
        /* Have we terminated yet? */
        pthread_testcancel();

        /* No. Sleep */
        usleep(3000);
    }
}

void* Client::startControl(void *arg)
{
   static_cast<Client*>(arg)->controlThread();
}
