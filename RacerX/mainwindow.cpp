/*
 RacerX Client
 Abhinay Evani

 See : mainWindow.h
 */

// files needed for QT
#include "mainwindow.h"
#include <stdio.h>
#include <stdlib.h>
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QFile>
#include <QUrl>

// for networking
#include "pthread.h"

// classes for data and client
#include "data.h"
#include "client.h"

// global variables for maps
QUrl currentUrl;
char* baseUrl;
int zoom;

// global variables for locks, data and sockets
pthread_mutex_t mutex_s =  PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_c =  PTHREAD_MUTEX_INITIALIZER;
Data clientData;
int sock, sockfd;
char serverIP[15];
int commandPort;
int streamPort;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // connect the input widgets to their
    // functions.
    MainWindow::connectActions();

    key = 0;

    pthread_mutex_init(&mutex_s, NULL);
//        pthread_mutex_init(&mutex_c, NULL);

    currentUrl = "http://maps.google.com/maps/api/staticmap?";
    zoom = 14;
    currentUrl.addQueryItem(QString("size"), "640x480");
    currentUrl.addQueryItem(QString("sensor"), "true");
    QString zoomValue;
    currentUrl.addQueryItem(QString("zoom"), zoomValue.setNum(zoom));
}

MainWindow::~MainWindow()
{
/*    if(sock) ::close(sock);
    if(sockfd) ::close(sockfd);
    if(img) cvReleaseImage(&img);

    pthread_mutex_destroy(&mutex_s);
    pthread_mutex_destroy(&mutex_c);
*/
    delete ui;
}

void MainWindow::connectActions()
{
    QObject::connect(ui->actionCamera_3, SIGNAL(triggered()), this, SLOT(camera1()));
    QObject::connect(ui->actionCamera_4, SIGNAL(triggered()), this, SLOT(camera2()));
    QObject::connect(ui->actionSet_Resolution, SIGNAL(triggered()), this, SLOT(setResolution()));
    QObject::connect(ui->actionSet_Rate, SIGNAL(triggered()), this, SLOT(setRate()));
    QObject::connect(ui->actionAbout_2, SIGNAL(triggered()), this, SLOT(about()));
    QObject::connect(ui->moveButton, SIGNAL(clicked()), this, SLOT(moveBuggy()));
    QObject::connect(ui->turnButton, SIGNAL(clicked()), this, SLOT(turnBuggy()));
    QObject::connect(ui->speedValue, SIGNAL(sliderReleased()), this, SLOT(setBuggySpeed()));
    QObject::connect(ui->mpsec, SIGNAL(toggled(bool)), this, SLOT(setSpeedUnits()));
    QObject::connect(ui->fpsec, SIGNAL(toggled(bool)), this, SLOT(setSpeedUnits()));
    QObject::connect(ui->kmph, SIGNAL(toggled(bool)), this, SLOT(setSpeedUnits()));
    QObject::connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(connectToServer()));
    QObject::connect(ui->locateButton, SIGNAL(clicked()), this, SLOT(showLocation()));
    QObject::connect(ui->mapSlider, SIGNAL(sliderReleased()), SLOT(zoomMap()));
    QObject::connect(ui->actionSend_Command_list, SIGNAL(triggered()), SLOT(openCommandList()));
}

void MainWindow::setSpeed(int value)
{
    ui->speed->setProperty("value", QVariant(value));
}
void MainWindow::setPosition(int value)
{
    ui->position->setProperty("value", QVariant(value));
}
void MainWindow::setOrientation(int value)
{
    ui->orientation->setProperty("value", QVariant(value));
}
void MainWindow::moveBuggy()
{
    int distance = ui->distance->text().toInt();
    bool forward = ui->fwdButton->isChecked();
    bool reverse = ui->revButton->isChecked();

    if(!distance)
    {
        QMessageBox::critical(this, tr("RacerX Client"),
                     tr("<p>Error: (Move) The field \"Distance\" cannot be empty. </p>"));
        return;
    }

    if(!forward && !reverse)
    {
        QMessageBox::critical(this, tr("RacerX Client"),
                     tr("<p>Error: (Move) Must select Forward/Reverse. </p>"));
        return;
    }

    //move the Buggy
}
void MainWindow::turnBuggy()
{
    int degrees = ui->degrees->text().toInt();
    bool left   = ui->leftButton->isChecked();
    bool right  = ui->rightButton->isChecked();

    if(!degrees)
    {
        QMessageBox::critical(this, tr("RacerX Client"),
                     tr("<p>Error: (Turn) The field \"Degrees\" cannot be empty. </p>"));
        return;
    }

    if(!left && !right)
    {
        QMessageBox::critical(this, tr("RacerX Client"),
                     tr("<p>Error: (Turn) Must select Left/Right. </p>"));
        return;
    }

    //turn the Buggy
}
void MainWindow::setBuggySpeed()
{
    int speed = ui->speedValue->value();
    bool mpsec = ui->mpsec->isChecked();
    bool fpsec = ui->fpsec->isChecked();
    bool kmph  = ui->kmph->isChecked();
    if(!mpsec && !fpsec && !kmph)
    {
        QMessageBox::critical(this, tr("RacerX Client"),
                     tr("<p>Error: (Set Speed) Must select MPSec/FPSec/KMPH. </p>"));
        ui->speedValue->setValue(speedValue);
        return;
    }

    //setBuggySpeed

}
void MainWindow::setSpeedUnits()
{
   bool mpsec = ui->mpsec->isChecked();
   bool fpsec = ui->fpsec->isChecked();
   bool kmph  = ui->kmph->isChecked();
   //setSpeedUnits
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About RacerX Client"),
                 tr("<p>RacerX Client </p>"
                    "<p>Abhinay Evani</p>"
                    ));

}
void MainWindow::openCommandList()
{
    if(connected == 1)
    {
        QString fileName = QFileDialog::getOpenFileName(this,
                                             tr("Open File"), QDir::currentPath());
        if (fileName.isEmpty()) {
                     return;
        }
        MainWindow::loadCommandlist(fileName);
    }
    else
    {
        QMessageBox::critical(this, tr("Send Command List"), tr("<p>Error: Not connected to server.</p>"));
        return;
    }

}
void MainWindow::loadCommandlist(QString fileName)
{
    QFile configFile(fileName);

    if(configFile.exists() && configFile.open(QIODevice::ReadOnly | QIODevice::Text));
    else
    {
        QMessageBox::critical(this, tr("Send Command List"), tr("<p>Error: Unable to load command list file.</p>"));
        return;
    }

    int i = 1;
    char tempBuffer[50][20];

    while(!configFile.atEnd() && i < 50)
    {
        // each command needs to be separated by the newline character
        QByteArray line = configFile.readLine();

        // commands longer than 20 characters are ignored
        int length = line.length();

        if (length <= 20)
            strcpy(tempBuffer[i], line.data());
        if (length < 20)
            tempBuffer[i][length] = '\0';
        i++;
    }
    if(i < 50) tempBuffer[i][0] = '\0';
    tempBuffer[0][0] = i - 1 + '0';
    tempBuffer[0][1] = '\n';
    tempBuffer[0][2] = '\0';

    pthread_mutex_lock(&mutex_c);

    memcpy(clientData.commandBuffer, tempBuffer, sizeof tempBuffer);
    clientData.isCommandReady = 1;

    pthread_mutex_unlock(&mutex_c);
    configFile.close();
}

void MainWindow::setResolution()
{
    bool ok;
    QString width = QInputDialog::getText(this, tr("Set Resolution"),
                                              tr("Enter the width of a frame"), QLineEdit::Normal,
                                              this->width, &ok);

    if(!ok || width.isEmpty() || !width.toInt())
    {
        QMessageBox::critical(this, tr("Set Resolution"),
                     tr("<p>Error: (Set Resolution) Invalid entry for width of a frame. </p>"));
        return;
    }

    QString height = QInputDialog::getText(this, tr("Set Resolution"),
                                              tr("Enter the height of a frame"), QLineEdit::Normal,
                                              this->height, &ok);
    if(!ok || height.isEmpty() || !height.toInt())
    {
        QMessageBox::critical(this, tr("Set Resolution"),
                     tr("<p>Error: (Set Resolution) Invalid entry for height of a frame. </p>"));
        return;
    }
    //Set Resolution

    this->width = width;
    this->height = height;
}
void MainWindow::camera1()
{
    //Switch to camera1
}
void MainWindow::camera2()
{
    //Switch to camera2
}
void MainWindow::setRate()
{
    bool ok;
    QString rate = QInputDialog::getText(this, tr("Set Rate"),
                                              tr("Enter the required frame rate"), QLineEdit::Normal,
                                              this->rate, &ok);

    if(!ok || rate.isEmpty() || !rate.toInt())
    {
        QMessageBox::critical(this, tr("Set Rate"),
                     tr("<p>Error: (Set Rate) Invalid entry for width of a frame. </p>"));
        return;
    }
    this->rate = rate;
    //Set Rate
}
void MainWindow::showLocation(void)
{
    QString location = ui->locationValue->text();
    QString markers = "color:green|" + location;


    currentUrl.removeQueryItem("center");
    currentUrl.removeQueryItem("markers");


    currentUrl.addQueryItem(QString("center"), location);
    currentUrl.addQueryItem(QString("markers"), markers);

    ui->webView->setUrl(currentUrl);

}
void MainWindow::zoomMap(void)
{
    zoom = ui->mapSlider->value();
    QString zoomValue;

    currentUrl.removeQueryItem("zoom");
    currentUrl.addQueryItem("zoom", zoomValue.setNum(zoom));

    ui->webView->setUrl(currentUrl);
}

void MainWindow::connectToServer()
{
    //Disconnect
    if(connected == 1)
    {
        //Stop updating Image and status
        key = 'q';
        //Clear Image
        ui->videoFrame->clear();

        clientobj.disconnect();

        connected = 0;
        ui->connectButton->setText(QString("Connect"));

        return;
    }
    //Connect
    else
    {

        key = 0;
        bool ok;
        QString ipaddr = ui->IP->text();
        QByteArray ipBytes = ipaddr.toAscii();
        strcpy(serverIP, ipBytes.data());
        int   port   = ui->Port->text().toInt(&ok, 10);
        commandPort = port + 1024;
        streamPort = port;

        if(ipaddr.isEmpty() || !port)
        {
            QMessageBox::critical(this, tr("RacerX Client"),
                         tr("<p>Error: (Connect) Invalid entry for IPAddress and/or Port Number. </p>"));
            return;
        }

        clientobj.connect();

        connected = 1;
        ui->connectButton->setText(QString("Disconnect"));

        while(key != 'q')
        {
            updateInS();
            cvWaitKey(30);
        }

        return;
    }
}

void MainWindow::updateInS(void)
{
    /**
    * Display the received image, make it thread safe
    * by enclosing it using pthread_mutex_lock
    */

    if(clientData.isImageReady)
    {
        pthread_mutex_lock(&mutex_s);
        QImage* temp = clientData.imgobj.temp;
        ui->videoFrame->setPixmap(QPixmap::fromImage(*temp));
        clientData.isImageReady = 0;
        pthread_mutex_unlock(&mutex_s);
    }
    if(clientData.isInfoReady)
    {
        clientData.isInfoReady = 0;
        pthread_mutex_lock(&mutex_s);
        ui->speed->setProperty("value", QVariant(clientData.telemetry[0]));
        ui->position->setProperty("value", QVariant(clientData.telemetry[1]));
        ui->position_2->setProperty("value", QVariant(clientData.telemetry[2]));
        ui->orientation->setProperty("value", QVariant(clientData.telemetry[3]));
        pthread_mutex_unlock(&mutex_s);
    }


    if(clientData.isReplyReady)
    {
        pthread_mutex_lock(&mutex_c);
        ui->statusBar->showMessage(clientData.reply, 5000);
        clientData.isReplyReady = 0;
        clientData.reply[0] = '\0';
        pthread_mutex_unlock(&mutex_c);
    }
}
