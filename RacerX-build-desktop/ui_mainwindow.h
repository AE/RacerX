/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Jan 16 00:17:42 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionServerConfig_2;
    QAction *actionCamera_3;
    QAction *actionCamera_4;
    QAction *actionAbout_2;
    QAction *actionSet_Resolution;
    QAction *actionSet_Rate;
    QAction *actionQuit;
    QAction *actionFullScreen;
    QAction *actionNormal;
    QAction *actionSend_Command_list;
    QWidget *centralWidget;
    QWidget *mainWidget;
    QVBoxLayout *mainLayout;
    QWidget *telemetryWidget;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *speed;
    QPushButton *speedButton;
    QFrame *line_7;
    QLCDNumber *position;
    QLCDNumber *position_2;
    QPushButton *positionButton;
    QFrame *line_8;
    QLCDNumber *orientation;
    QPushButton *orientationButton;
    QFrame *line;
    QWidget *videoWidget;
    QVBoxLayout *videoLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *videoFrame;
    QWidget *tab_2;
    QLabel *videoFrame_2;
    QWidget *tab_3;
    QLabel *laserFrame;
    QWidget *tab_4;
    QWidget *mapsWidget;
    QHBoxLayout *mapsLayout;
    QSpacerItem *horizontalSpacer_7;
    QWebView *webView;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *mapsControlLayout;
    QHBoxLayout *zoomLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QSlider *mapSlider;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *locateLayout;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *locationValue;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *locateButton;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line_2;
    QWidget *navWidget;
    QVBoxLayout *navigationLayout;
    QWidget *mntWidget;
    QHBoxLayout *horizontalLayout_6;
    QWidget *moveWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *moveButton;
    QRadioButton *fwdButton;
    QRadioButton *revButton;
    QLabel *distLabel;
    QLineEdit *distance;
    QFrame *line_4;
    QWidget *turnWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *turnButton;
    QRadioButton *leftButton;
    QRadioButton *rightButton;
    QLabel *degLabel;
    QLineEdit *degrees;
    QWidget *speedWidget;
    QHBoxLayout *sndLayout;
    QWidget *speedWidget2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *setSpeedLabel;
    QSlider *speedValue;
    QLCDNumber *speedLCD;
    QWidget *speedWidget1;
    QHBoxLayout *horizontalLayout_5;
    QFrame *line_3;
    QLabel *setDistLabel;
    QRadioButton *mpsec;
    QRadioButton *fpsec;
    QRadioButton *kmph;
    QWidget *startWidget_2;
    QHBoxLayout *startWidget;
    QLabel *IPLabel;
    QLineEdit *IP;
    QFrame *line_6;
    QLabel *PortLabel;
    QLineEdit *Port;
    QFrame *line_9;
    QPushButton *connectButton;
    QFrame *line_5;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuCamera;
    QMenu *menuAbout;
    QMenu *menuView;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1042, 828);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/RacerX/Images/small.gif"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(true);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionServerConfig_2 = new QAction(MainWindow);
        actionServerConfig_2->setObjectName(QString::fromUtf8("actionServerConfig_2"));
        actionCamera_3 = new QAction(MainWindow);
        actionCamera_3->setObjectName(QString::fromUtf8("actionCamera_3"));
        actionCamera_4 = new QAction(MainWindow);
        actionCamera_4->setObjectName(QString::fromUtf8("actionCamera_4"));
        actionAbout_2 = new QAction(MainWindow);
        actionAbout_2->setObjectName(QString::fromUtf8("actionAbout_2"));
        actionSet_Resolution = new QAction(MainWindow);
        actionSet_Resolution->setObjectName(QString::fromUtf8("actionSet_Resolution"));
        actionSet_Rate = new QAction(MainWindow);
        actionSet_Rate->setObjectName(QString::fromUtf8("actionSet_Rate"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionFullScreen = new QAction(MainWindow);
        actionFullScreen->setObjectName(QString::fromUtf8("actionFullScreen"));
        actionNormal = new QAction(MainWindow);
        actionNormal->setObjectName(QString::fromUtf8("actionNormal"));
        actionSend_Command_list = new QAction(MainWindow);
        actionSend_Command_list->setObjectName(QString::fromUtf8("actionSend_Command_list"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        mainWidget = new QWidget(centralWidget);
        mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
        mainWidget->setGeometry(QRect(0, 0, 1024, 748));
        sizePolicy1.setHeightForWidth(mainWidget->sizePolicy().hasHeightForWidth());
        mainWidget->setSizePolicy(sizePolicy1);
        mainLayout = new QVBoxLayout(mainWidget);
        mainLayout->setSpacing(6);
        mainLayout->setContentsMargins(11, 11, 11, 11);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        telemetryWidget = new QWidget(mainWidget);
        telemetryWidget->setObjectName(QString::fromUtf8("telemetryWidget"));
        sizePolicy1.setHeightForWidth(telemetryWidget->sizePolicy().hasHeightForWidth());
        telemetryWidget->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(telemetryWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        speed = new QLCDNumber(telemetryWidget);
        speed->setObjectName(QString::fromUtf8("speed"));
        speed->setSmallDecimalPoint(true);
        speed->setSegmentStyle(QLCDNumber::Flat);
        speed->setProperty("value", QVariant(0));
        speed->setProperty("intValue", QVariant(0));

        horizontalLayout->addWidget(speed);

        speedButton = new QPushButton(telemetryWidget);
        speedButton->setObjectName(QString::fromUtf8("speedButton"));

        horizontalLayout->addWidget(speedButton);

        line_7 = new QFrame(telemetryWidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_7);

        position = new QLCDNumber(telemetryWidget);
        position->setObjectName(QString::fromUtf8("position"));
        position->setSmallDecimalPoint(true);
        position->setSegmentStyle(QLCDNumber::Flat);
        position->setProperty("value", QVariant(0));

        horizontalLayout->addWidget(position);

        position_2 = new QLCDNumber(telemetryWidget);
        position_2->setObjectName(QString::fromUtf8("position_2"));
        position_2->setSmallDecimalPoint(true);
        position_2->setSegmentStyle(QLCDNumber::Flat);
        position_2->setProperty("value", QVariant(0));

        horizontalLayout->addWidget(position_2);

        positionButton = new QPushButton(telemetryWidget);
        positionButton->setObjectName(QString::fromUtf8("positionButton"));

        horizontalLayout->addWidget(positionButton);

        line_8 = new QFrame(telemetryWidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_8);

        orientation = new QLCDNumber(telemetryWidget);
        orientation->setObjectName(QString::fromUtf8("orientation"));
        orientation->setSmallDecimalPoint(true);
        orientation->setSegmentStyle(QLCDNumber::Flat);
        orientation->setProperty("value", QVariant(0));

        horizontalLayout->addWidget(orientation);

        orientationButton = new QPushButton(telemetryWidget);
        orientationButton->setObjectName(QString::fromUtf8("orientationButton"));

        horizontalLayout->addWidget(orientationButton);


        mainLayout->addWidget(telemetryWidget);

        line = new QFrame(mainWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        mainLayout->addWidget(line);

        videoWidget = new QWidget(mainWidget);
        videoWidget->setObjectName(QString::fromUtf8("videoWidget"));
        sizePolicy1.setHeightForWidth(videoWidget->sizePolicy().hasHeightForWidth());
        videoWidget->setSizePolicy(sizePolicy1);
        videoWidget->setMinimumSize(QSize(700, 520));
        videoWidget->setLayoutDirection(Qt::LeftToRight);
        videoWidget->setStyleSheet(QString::fromUtf8(""));
        videoLayout = new QVBoxLayout(videoWidget);
        videoLayout->setSpacing(6);
        videoLayout->setContentsMargins(11, 11, 11, 11);
        videoLayout->setObjectName(QString::fromUtf8("videoLayout"));
        videoLayout->setContentsMargins(0, 9, 9, 9);
        tabWidget = new QTabWidget(videoWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(700, 520));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        videoFrame = new QLabel(tab);
        videoFrame->setObjectName(QString::fromUtf8("videoFrame"));
        videoFrame->setGeometry(QRect(0, 10, 640, 480));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(videoFrame->sizePolicy().hasHeightForWidth());
        videoFrame->setSizePolicy(sizePolicy2);
        videoFrame->setMinimumSize(QSize(640, 480));
        videoFrame->setMaximumSize(QSize(640, 480));
        videoFrame->setLayoutDirection(Qt::LeftToRight);
        videoFrame->setAutoFillBackground(false);
        videoFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"image: url(:/RacerX/Images/big.gif);\n"
""));
        videoFrame->setFrameShape(QFrame::NoFrame);
        videoFrame->setScaledContents(true);
        videoFrame->setAlignment(Qt::AlignCenter);
        videoFrame->setWordWrap(false);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        videoFrame_2 = new QLabel(tab_2);
        videoFrame_2->setObjectName(QString::fromUtf8("videoFrame_2"));
        videoFrame_2->setGeometry(QRect(0, 10, 640, 480));
        sizePolicy2.setHeightForWidth(videoFrame_2->sizePolicy().hasHeightForWidth());
        videoFrame_2->setSizePolicy(sizePolicy2);
        videoFrame_2->setMinimumSize(QSize(640, 480));
        videoFrame_2->setMaximumSize(QSize(640, 480));
        videoFrame_2->setLayoutDirection(Qt::LeftToRight);
        videoFrame_2->setAutoFillBackground(false);
        videoFrame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"image: url(:/RacerX/Images/big.gif);\n"
""));
        videoFrame_2->setFrameShape(QFrame::NoFrame);
        videoFrame_2->setScaledContents(true);
        videoFrame_2->setAlignment(Qt::AlignCenter);
        videoFrame_2->setWordWrap(false);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        laserFrame = new QLabel(tab_3);
        laserFrame->setObjectName(QString::fromUtf8("laserFrame"));
        laserFrame->setGeometry(QRect(0, 10, 640, 480));
        sizePolicy2.setHeightForWidth(laserFrame->sizePolicy().hasHeightForWidth());
        laserFrame->setSizePolicy(sizePolicy2);
        laserFrame->setMinimumSize(QSize(640, 480));
        laserFrame->setMaximumSize(QSize(640, 480));
        laserFrame->setLayoutDirection(Qt::LeftToRight);
        laserFrame->setAutoFillBackground(false);
        laserFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"image: url(:/RacerX/Images/big.gif);\n"
""));
        laserFrame->setFrameShape(QFrame::NoFrame);
        laserFrame->setScaledContents(true);
        laserFrame->setAlignment(Qt::AlignCenter);
        laserFrame->setWordWrap(false);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        mapsWidget = new QWidget(tab_4);
        mapsWidget->setObjectName(QString::fromUtf8("mapsWidget"));
        mapsWidget->setEnabled(true);
        mapsWidget->setGeometry(QRect(0, 0, 991, 491));
        mapsLayout = new QHBoxLayout(mapsWidget);
        mapsLayout->setSpacing(6);
        mapsLayout->setContentsMargins(11, 11, 11, 11);
        mapsLayout->setObjectName(QString::fromUtf8("mapsLayout"));
        mapsLayout->setContentsMargins(0, 2, 0, 2);
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        mapsLayout->addItem(horizontalSpacer_7);

        webView = new QWebView(mapsWidget);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setEnabled(false);
        sizePolicy2.setHeightForWidth(webView->sizePolicy().hasHeightForWidth());
        webView->setSizePolicy(sizePolicy2);
        webView->setMinimumSize(QSize(640, 480));
        webView->setMaximumSize(QSize(640, 480));
        webView->setUrl(QUrl("about:blank"));

        mapsLayout->addWidget(webView);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        mapsLayout->addItem(horizontalSpacer_8);

        mapsControlLayout = new QVBoxLayout();
        mapsControlLayout->setSpacing(6);
        mapsControlLayout->setObjectName(QString::fromUtf8("mapsControlLayout"));
        zoomLayout = new QHBoxLayout();
        zoomLayout->setSpacing(6);
        zoomLayout->setObjectName(QString::fromUtf8("zoomLayout"));
        zoomLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zoomLayout->addItem(horizontalSpacer);

        label = new QLabel(mapsWidget);
        label->setObjectName(QString::fromUtf8("label"));

        zoomLayout->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zoomLayout->addItem(horizontalSpacer_4);

        mapSlider = new QSlider(mapsWidget);
        mapSlider->setObjectName(QString::fromUtf8("mapSlider"));
        mapSlider->setMaximumSize(QSize(200, 200));
        mapSlider->setMinimum(10);
        mapSlider->setMaximum(22);
        mapSlider->setOrientation(Qt::Vertical);

        zoomLayout->addWidget(mapSlider);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        zoomLayout->addItem(horizontalSpacer_3);


        mapsControlLayout->addLayout(zoomLayout);

        locateLayout = new QHBoxLayout();
        locateLayout->setSpacing(6);
        locateLayout->setObjectName(QString::fromUtf8("locateLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        locateLayout->addItem(horizontalSpacer_5);

        locationValue = new QLineEdit(mapsWidget);
        locationValue->setObjectName(QString::fromUtf8("locationValue"));

        locateLayout->addWidget(locationValue);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        locateLayout->addItem(horizontalSpacer_6);

        locateButton = new QPushButton(mapsWidget);
        locateButton->setObjectName(QString::fromUtf8("locateButton"));

        locateLayout->addWidget(locateButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        locateLayout->addItem(horizontalSpacer_2);


        mapsControlLayout->addLayout(locateLayout);


        mapsLayout->addLayout(mapsControlLayout);

        tabWidget->addTab(tab_4, QString());

        videoLayout->addWidget(tabWidget);


        mainLayout->addWidget(videoWidget);

        line_2 = new QFrame(mainWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        mainLayout->addWidget(line_2);

        navWidget = new QWidget(mainWidget);
        navWidget->setObjectName(QString::fromUtf8("navWidget"));
        sizePolicy2.setHeightForWidth(navWidget->sizePolicy().hasHeightForWidth());
        navWidget->setSizePolicy(sizePolicy2);
        navWidget->setMinimumSize(QSize(0, 0));
        navigationLayout = new QVBoxLayout(navWidget);
        navigationLayout->setSpacing(6);
        navigationLayout->setContentsMargins(2, 2, 2, 2);
        navigationLayout->setObjectName(QString::fromUtf8("navigationLayout"));
        mntWidget = new QWidget(navWidget);
        mntWidget->setObjectName(QString::fromUtf8("mntWidget"));
        sizePolicy1.setHeightForWidth(mntWidget->sizePolicy().hasHeightForWidth());
        mntWidget->setSizePolicy(sizePolicy1);
        horizontalLayout_6 = new QHBoxLayout(mntWidget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        moveWidget = new QWidget(mntWidget);
        moveWidget->setObjectName(QString::fromUtf8("moveWidget"));
        sizePolicy1.setHeightForWidth(moveWidget->sizePolicy().hasHeightForWidth());
        moveWidget->setSizePolicy(sizePolicy1);
        horizontalLayout_2 = new QHBoxLayout(moveWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        moveButton = new QPushButton(moveWidget);
        moveButton->setObjectName(QString::fromUtf8("moveButton"));

        horizontalLayout_2->addWidget(moveButton);

        fwdButton = new QRadioButton(moveWidget);
        fwdButton->setObjectName(QString::fromUtf8("fwdButton"));

        horizontalLayout_2->addWidget(fwdButton);

        revButton = new QRadioButton(moveWidget);
        revButton->setObjectName(QString::fromUtf8("revButton"));

        horizontalLayout_2->addWidget(revButton);

        distLabel = new QLabel(moveWidget);
        distLabel->setObjectName(QString::fromUtf8("distLabel"));

        horizontalLayout_2->addWidget(distLabel);

        distance = new QLineEdit(moveWidget);
        distance->setObjectName(QString::fromUtf8("distance"));

        horizontalLayout_2->addWidget(distance);


        horizontalLayout_6->addWidget(moveWidget);

        line_4 = new QFrame(mntWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_6->addWidget(line_4);

        turnWidget = new QWidget(mntWidget);
        turnWidget->setObjectName(QString::fromUtf8("turnWidget"));
        sizePolicy1.setHeightForWidth(turnWidget->sizePolicy().hasHeightForWidth());
        turnWidget->setSizePolicy(sizePolicy1);
        horizontalLayout_3 = new QHBoxLayout(turnWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        turnButton = new QPushButton(turnWidget);
        turnButton->setObjectName(QString::fromUtf8("turnButton"));

        horizontalLayout_3->addWidget(turnButton);

        leftButton = new QRadioButton(turnWidget);
        leftButton->setObjectName(QString::fromUtf8("leftButton"));

        horizontalLayout_3->addWidget(leftButton);

        rightButton = new QRadioButton(turnWidget);
        rightButton->setObjectName(QString::fromUtf8("rightButton"));

        horizontalLayout_3->addWidget(rightButton);

        degLabel = new QLabel(turnWidget);
        degLabel->setObjectName(QString::fromUtf8("degLabel"));

        horizontalLayout_3->addWidget(degLabel);

        degrees = new QLineEdit(turnWidget);
        degrees->setObjectName(QString::fromUtf8("degrees"));

        horizontalLayout_3->addWidget(degrees);


        horizontalLayout_6->addWidget(turnWidget);


        navigationLayout->addWidget(mntWidget);

        speedWidget = new QWidget(navWidget);
        speedWidget->setObjectName(QString::fromUtf8("speedWidget"));
        sizePolicy1.setHeightForWidth(speedWidget->sizePolicy().hasHeightForWidth());
        speedWidget->setSizePolicy(sizePolicy1);
        sndLayout = new QHBoxLayout(speedWidget);
        sndLayout->setSpacing(6);
        sndLayout->setContentsMargins(2, 2, 2, 2);
        sndLayout->setObjectName(QString::fromUtf8("sndLayout"));
        speedWidget2 = new QWidget(speedWidget);
        speedWidget2->setObjectName(QString::fromUtf8("speedWidget2"));
        sizePolicy1.setHeightForWidth(speedWidget2->sizePolicy().hasHeightForWidth());
        speedWidget2->setSizePolicy(sizePolicy1);
        horizontalLayout_4 = new QHBoxLayout(speedWidget2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        setSpeedLabel = new QLabel(speedWidget2);
        setSpeedLabel->setObjectName(QString::fromUtf8("setSpeedLabel"));

        horizontalLayout_4->addWidget(setSpeedLabel);

        speedValue = new QSlider(speedWidget2);
        speedValue->setObjectName(QString::fromUtf8("speedValue"));
        speedValue->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(speedValue);

        speedLCD = new QLCDNumber(speedWidget2);
        speedLCD->setObjectName(QString::fromUtf8("speedLCD"));
        speedLCD->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_4->addWidget(speedLCD);


        sndLayout->addWidget(speedWidget2);

        speedWidget1 = new QWidget(speedWidget);
        speedWidget1->setObjectName(QString::fromUtf8("speedWidget1"));
        sizePolicy1.setHeightForWidth(speedWidget1->sizePolicy().hasHeightForWidth());
        speedWidget1->setSizePolicy(sizePolicy1);
        horizontalLayout_5 = new QHBoxLayout(speedWidget1);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        line_3 = new QFrame(speedWidget1);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line_3);

        setDistLabel = new QLabel(speedWidget1);
        setDistLabel->setObjectName(QString::fromUtf8("setDistLabel"));

        horizontalLayout_5->addWidget(setDistLabel);

        mpsec = new QRadioButton(speedWidget1);
        mpsec->setObjectName(QString::fromUtf8("mpsec"));

        horizontalLayout_5->addWidget(mpsec);

        fpsec = new QRadioButton(speedWidget1);
        fpsec->setObjectName(QString::fromUtf8("fpsec"));

        horizontalLayout_5->addWidget(fpsec);

        kmph = new QRadioButton(speedWidget1);
        kmph->setObjectName(QString::fromUtf8("kmph"));

        horizontalLayout_5->addWidget(kmph);


        sndLayout->addWidget(speedWidget1);


        navigationLayout->addWidget(speedWidget);

        startWidget_2 = new QWidget(navWidget);
        startWidget_2->setObjectName(QString::fromUtf8("startWidget_2"));
        startWidget = new QHBoxLayout(startWidget_2);
        startWidget->setSpacing(6);
        startWidget->setContentsMargins(2, 2, 2, 2);
        startWidget->setObjectName(QString::fromUtf8("startWidget"));
        IPLabel = new QLabel(startWidget_2);
        IPLabel->setObjectName(QString::fromUtf8("IPLabel"));
        IPLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        startWidget->addWidget(IPLabel);

        IP = new QLineEdit(startWidget_2);
        IP->setObjectName(QString::fromUtf8("IP"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(IP->sizePolicy().hasHeightForWidth());
        IP->setSizePolicy(sizePolicy3);
        IP->setMaxLength(15);

        startWidget->addWidget(IP);

        line_6 = new QFrame(startWidget_2);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        startWidget->addWidget(line_6);

        PortLabel = new QLabel(startWidget_2);
        PortLabel->setObjectName(QString::fromUtf8("PortLabel"));
        PortLabel->setAlignment(Qt::AlignCenter);

        startWidget->addWidget(PortLabel);

        Port = new QLineEdit(startWidget_2);
        Port->setObjectName(QString::fromUtf8("Port"));
        sizePolicy3.setHeightForWidth(Port->sizePolicy().hasHeightForWidth());
        Port->setSizePolicy(sizePolicy3);
        Port->setMaxLength(4);

        startWidget->addWidget(Port);

        line_9 = new QFrame(startWidget_2);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);

        startWidget->addWidget(line_9);

        connectButton = new QPushButton(startWidget_2);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(connectButton->sizePolicy().hasHeightForWidth());
        connectButton->setSizePolicy(sizePolicy4);

        startWidget->addWidget(connectButton);


        navigationLayout->addWidget(startWidget_2);


        mainLayout->addWidget(navWidget);

        line_5 = new QFrame(mainWidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        mainLayout->addWidget(line_5);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1042, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuCamera = new QMenu(menuEdit);
        menuCamera->setObjectName(QString::fromUtf8("menuCamera"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuEdit->addAction(menuCamera->menuAction());
        menuEdit->addAction(actionSend_Command_list);
        menuCamera->addAction(actionCamera_3);
        menuCamera->addAction(actionCamera_4);
        menuCamera->addAction(actionSet_Resolution);
        menuCamera->addAction(actionSet_Rate);
        menuAbout->addAction(actionAbout_2);
        menuView->addAction(actionFullScreen);
        menuView->addAction(actionNormal);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(activated()), MainWindow, SLOT(close()));
        QObject::connect(actionFullScreen, SIGNAL(activated()), MainWindow, SLOT(showFullScreen()));
        QObject::connect(speedValue, SIGNAL(valueChanged(int)), speedLCD, SLOT(display(int)));
        QObject::connect(actionNormal, SIGNAL(activated()), MainWindow, SLOT(showNormal()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "RacerX Client", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionServerConfig_2->setText(QApplication::translate("MainWindow", "ServerConfig", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionServerConfig_2->setToolTip(QApplication::translate("MainWindow", "Server Configuration", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionCamera_3->setText(QApplication::translate("MainWindow", "Camera 1", 0, QApplication::UnicodeUTF8));
        actionCamera_4->setText(QApplication::translate("MainWindow", "Camera 2", 0, QApplication::UnicodeUTF8));
        actionAbout_2->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionSet_Resolution->setText(QApplication::translate("MainWindow", "Set Resolution", 0, QApplication::UnicodeUTF8));
        actionSet_Rate->setText(QApplication::translate("MainWindow", "Set Rate", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionFullScreen->setText(QApplication::translate("MainWindow", "FullScreen", 0, QApplication::UnicodeUTF8));
        actionNormal->setText(QApplication::translate("MainWindow", "Normal", 0, QApplication::UnicodeUTF8));
        actionSend_Command_list->setText(QApplication::translate("MainWindow", "Send Command list", 0, QApplication::UnicodeUTF8));
        speedButton->setText(QApplication::translate("MainWindow", "Speed", 0, QApplication::UnicodeUTF8));
        positionButton->setText(QApplication::translate("MainWindow", "Position", 0, QApplication::UnicodeUTF8));
        orientationButton->setText(QApplication::translate("MainWindow", "Orientation", 0, QApplication::UnicodeUTF8));
        videoFrame->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Camera 1", 0, QApplication::UnicodeUTF8));
        videoFrame_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Camera 2", 0, QApplication::UnicodeUTF8));
        laserFrame->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Laser", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Zoom", 0, QApplication::UnicodeUTF8));
        locateButton->setText(QApplication::translate("MainWindow", "Locate", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Maps", 0, QApplication::UnicodeUTF8));
        moveButton->setText(QApplication::translate("MainWindow", "Move", 0, QApplication::UnicodeUTF8));
        fwdButton->setText(QApplication::translate("MainWindow", "Forward", 0, QApplication::UnicodeUTF8));
        revButton->setText(QApplication::translate("MainWindow", "Reverse", 0, QApplication::UnicodeUTF8));
        distLabel->setText(QApplication::translate("MainWindow", "Distance", 0, QApplication::UnicodeUTF8));
        turnButton->setText(QApplication::translate("MainWindow", "Turn", 0, QApplication::UnicodeUTF8));
        leftButton->setText(QApplication::translate("MainWindow", "Left", 0, QApplication::UnicodeUTF8));
        rightButton->setText(QApplication::translate("MainWindow", "Right", 0, QApplication::UnicodeUTF8));
        degLabel->setText(QApplication::translate("MainWindow", "Degrees", 0, QApplication::UnicodeUTF8));
        setSpeedLabel->setText(QApplication::translate("MainWindow", "Set Speed", 0, QApplication::UnicodeUTF8));
        setDistLabel->setText(QApplication::translate("MainWindow", "Set Speed Units", 0, QApplication::UnicodeUTF8));
        mpsec->setText(QApplication::translate("MainWindow", "MPSec", 0, QApplication::UnicodeUTF8));
        fpsec->setText(QApplication::translate("MainWindow", "FPSec", 0, QApplication::UnicodeUTF8));
        kmph->setText(QApplication::translate("MainWindow", "KMPH", 0, QApplication::UnicodeUTF8));
        IPLabel->setText(QApplication::translate("MainWindow", "IP", 0, QApplication::UnicodeUTF8));
        PortLabel->setText(QApplication::translate("MainWindow", "Port ", 0, QApplication::UnicodeUTF8));
        connectButton->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuCamera->setTitle(QApplication::translate("MainWindow", "Camera", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
