/*
 RacerX Client
 Abhinay Evani

 MainWindow.h
 This class contains all the members and methods
 used by the application.
 The methods that lie inside ui_mainwindow.h
 were generated by QT Creator and should not be modified.
 */


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "client.h"
#include "data.h"

class QFile;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int key;
    int distance;
    int degrees;
    int distanceUnits;
    int connected;
    int speedValue;
    QString width;
    QString height;
    QString rate;
    IplImage* img;
    Client clientobj;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setSpeed(int value);
    void setPosition(int value);
    void setOrientation(int value);
    void setLaser(int value);
    void showVideoFrame(IplImage* image);
    void connectActions();
    void loadCommandlist(QString fileName);
    void updateInS(void);

public slots:
    void openCommandList(void);
    void camera1(void);
    void camera2(void);
    void setResolution(void);
    void setRate(void);
    void about(void);
    void moveBuggy(void);
    void turnBuggy(void);
    void setBuggySpeed(void);
    void setSpeedUnits(void);
    void connectToServer(void);
    void showLocation(void);
    void zoomMap(void);


private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
