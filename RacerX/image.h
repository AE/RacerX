#ifndef IMAGE_H
#define IMAGE_H

// default width and height (do not change without modifying server)
#define WIDTH 640
#define HEIGHT 480

#include <QImage>
#include <opencv/cv.h>
#include <opencv/highgui.h>

class Image
{
public:
    Image();

    IplImage* img;
    int imageWidth, imageHeight;
    QImage* temp;
    void cvToQt(void);
};

#endif // IMAGE_H
