#-------------------------------------------------
#
# RacerX - Client
# Abhinay Evani
#
#-------------------------------------------------

QT       += core gui webkit

TARGET = RacerX
TEMPLATE = app
LIBS += -lcv -lhighgui -lcxcore -lpthread


SOURCES += main.cpp\
        mainwindow.cpp \
    client.cpp \
    image.cpp \
    data.cpp

HEADERS  += mainwindow.h \
    client.h \
    image.h \
    data.h

FORMS    += mainwindow.ui

RESOURCES += \
    imageResource.qrc \
    fileResource.qrc
