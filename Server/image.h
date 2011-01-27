#include "cv.h"
#include "highgui.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_IMGSIZE 99942
#define IMG_TYPE IPL_DEPTH_8U
#define MIN_MTU 576
#define DATA_CHUNK_SIZE (MIN_MTU - (2* sizeof(int)))
typedef struct int_packet INT_PKT; // Image and Telemetry Packet
typedef struct udp_int_packet UDP_INT_PKT; // packet containg chunks of INT_PKT
                                           // for transmission over UDP
struct int_packet {
    double telemetry[4];
    int imageSize;
    int imageWidth;
    int imageHeight;
    int imageDepth;
    int imageChannels;
    char imageData[MAX_IMGSIZE];
};

struct udp_int_packet {
  int frame;
  int sequence;
  char data[DATA_CHUNK_SIZE];  // total size of this struct should be no more than 576
};

union {
  UDP_INT_PKT pkt;
  unsigned char bytes[sizeof(UDP_INT_PKT)];
} udppacketdata;

union {
    INT_PKT pkt;
    unsigned char bytes[sizeof(INT_PKT)];
} packetData;

float num_udp_pkts_ratio = (double) sizeof(INT_PKT) / DATA_CHUNK_SIZE;

// function to compress 3 channel color IplImages
// returns CvMat that needs to be released by the calling function
CvMat* compress_image(IplImage **dst_img, IplImage *src_img, int p[3])
{
    // create a compressed matrix cvmat
    CvMat *imgcmp = cvEncodeImage(".jpeg", src_img, &p);
    if(imgcmp == NULL)
        return NULL;
     
    // cvmat to IplImage
    IplImage iplstub;
    *dst_img = cvGetImage(imgcmp, &iplstub);
    if (*dst_img == NULL)
        return NULL;

    return imgcmp;  
}

// function to decompress 3 channel color IplImages
// returns IplImage that needs to be released by the calling function
CvMat* decompress_image(IplImage **dst_img, IplImage *src_img)
{
    // convert IplImage to CvMat
    CvMat matstub, *iplmat;
    iplmat = cvGetMat(src_img, &matstub, 0, 0);
    if(iplmat == NULL)
        return NULL;

    // decompress the image
    *dst_img = cvDecodeImage(iplmat, CV_LOAD_IMAGE_COLOR);
    
    return iplmat;
}
