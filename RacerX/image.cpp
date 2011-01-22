#include "image.h"
#include <QImage>
#include <opencv/cv.h>
#include <opencv/highgui.h>

Image::Image()
{
    // set width and height
    imageWidth = WIDTH;
    imageHeight = HEIGHT;

    img = cvCreateImage(cvSize(imageWidth, imageHeight), IPL_DEPTH_8U, 1);
    cvZero(img);
    temp = new QImage(img->width, img->height, QImage::Format_RGB32);
}

void Image::cvToQt(void) {
    int cvIndex = 0, cvLineStart = 0;

//    QImage temp(img->width, img->height, QImage::Format_RGB32);
    for (int y = 0; y < img->height; y++) {
        unsigned char red,green,blue;
        cvIndex = cvLineStart;
        for (int x = 0; x < img->width; x++) {
            // Set rgb channels of the qt image
            // as required.

            /* Uncomment when img has 3 channels
            red = img->imageData[cvIndex+2];
            green = img->imageData[cvIndex+1];
            blue = img->imageData[cvIndex+0];
            */

            /* Uncomment when img has 1 channel */
            red = img->imageData[cvIndex];
            green = img->imageData[cvIndex];
            blue = img->imageData[cvIndex];


            temp->setPixel(x,y,qRgb(red, green, blue));
            //Same as above for 3 channels
            //cvIndex += 3;
            //Same as above for 1 channel
            cvIndex++;
        }
        cvLineStart += img->widthStep;
    }

//    ui->videoFrame->setPixmap(QPixmap::fromImage(temp));
//    return temp;
}
