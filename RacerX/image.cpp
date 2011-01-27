#include "image.h"
#include <QImage>
#include <opencv/cv.h>
#include <opencv/highgui.h>

Image::Image()
{


}

void Image::cvToQt(int frameNumber) {
    if (!img) return;
    int cvIndex = 0, cvLineStart = 0;
    if(temp) delete temp;
    temp = new QImage(img->width, img->height, QImage::Format_RGB32);
    for (int y = 0; y < img->height; y++) {
        unsigned char red,green,blue;
        cvIndex = cvLineStart;
        for (int x = 0; x < img->width; x++) {
            // Set rgb channels of the qt image
            // as required.

            /* Uncomment when img has 3 channels */
            red = img->imageData[cvIndex+2];
            green = img->imageData[cvIndex+1];
            blue = img->imageData[cvIndex+0];


            /* Uncomment when img has 1 channel
            red = img->imageData[cvIndex];
            green = img->imageData[cvIndex];
            blue = img->imageData[cvIndex];*/


            temp->setPixel(x,y,qRgb(red, green, blue));
            //Same as above for 3 channels
            cvIndex += 3;
            //Same as above for 1 channel
            //cvIndex++;
        }
        cvLineStart += img->widthStep;
    }

return;
}

void Image::freeIplImage(void)
{
    cvReleaseImage(&img);
}

// function to compress 3 channel color IplImages
// returns CvMat that needs to be released by the calling function
CvMat* Image::compress_image(IplImage** dst_img, IplImage* src_img, int p[3])
{
    // create a compressed matrix cvmat
    CvMat *imgcmp = cvEncodeImage(".jpeg", src_img, p);
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
CvMat* Image::decompress_image(IplImage** dst_img, IplImage* src_img)
{
    // convert IplImage to CvMat
    CvMat matstub, *iplmat;
    iplmat = cvGetMat(src_img, &matstub, 0, 0);
    if(iplmat == NULL)
        return NULL;

    // decompress the image and add it to dst_img
    *dst_img = cvDecodeImage(iplmat, CV_LOAD_IMAGE_COLOR);
    return iplmat;
}
