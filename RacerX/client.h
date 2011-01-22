#ifndef CLIENT_H
#define CLIENT_H

// files needed for networking, opencv and multithreading
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <fcntl.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "client.h"
#include "data.h"
#include "image.h"

#include <QImage>

class Client
{
public:
    Client();

    pthread_t thread_s;
    pthread_t thread_c;

    int connect(void);
    int disconnect(void);

    void streamThread(void);
    void controlThread(void);
    static void* startStream(void* args);
    static void* startControl(void* args);

};

#endif // CLIENT_H
