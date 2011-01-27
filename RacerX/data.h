#ifndef DATA_H
#define DATA_H
#include <QImage>
#include "image.h"

class Data
{
public:
    Data();
    int isDataReady;
    int isCommandReady;
    int isReplyReady;
    Image imgobj;
    char commandBuffer[50][20];
    char reply[100];
    double telemetry[4];
};

#endif // DATA_H
