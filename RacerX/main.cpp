/*
 RacerX Client
 Abhinay Evani

 Main.cpp
 This file is used to setup the UI and
 to initialize the MainWindow of the application.
 */


#include <QtGui/QApplication>
#include "mainwindow.h"
#include "pthread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
