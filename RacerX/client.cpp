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

    int imageSize = clientData.imgobj.img->imageSize;
    double telemetry[4];
    int arraysize = (int) (sizeof telemetry);
    char sockData[imageSize];
    int i, j, k, bytes;

    /* Start receiving images */
    while(1)
    {

        for(i = 0; i < imageSize; i = i + bytes )
        {
            if((bytes = ::recv(sock, sockData + i, imageSize - i, 0)) == -1)
            {
                break;
            }

        }

        ::recv(sock, telemetry, arraysize, 0);

       /*thread safe. */
       pthread_mutex_lock(&mutex_s);

        /* Convert the received data to OpenCV's IplImage form */
       for (i = 0, k = 0; i < clientData.imgobj.img->height; i++) {
           for (j = 0; j < clientData.imgobj.img->width; j++) {
              ((uchar*)(clientData.imgobj.img->imageData + i * clientData.imgobj.img->widthStep))[j] = sockData[k++];
           }
       }

       clientData.imgobj.cvToQt();
       clientData.isImageReady = 1;

       clientData.telemetry[0] = telemetry[0];
       clientData.telemetry[1] = telemetry[1];
       clientData.telemetry[2] = telemetry[2];
       clientData.telemetry[3] = telemetry[3];
       clientData.isInfoReady = 1;

       pthread_mutex_unlock(&mutex_s);

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
