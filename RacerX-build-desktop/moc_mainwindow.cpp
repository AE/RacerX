/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Jan 27 06:49:12 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../RacerX/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      30,   11,   11,   11, 0x0a,
      40,   11,   11,   11, 0x0a,
      50,   11,   11,   11, 0x0a,
      66,   11,   11,   11, 0x0a,
      76,   11,   11,   11, 0x0a,
      84,   11,   11,   11, 0x0a,
      96,   11,   11,   11, 0x0a,
     108,   11,   11,   11, 0x0a,
     124,   11,   11,   11, 0x0a,
     140,   11,   11,   11, 0x0a,
     158,   11,   11,   11, 0x0a,
     173,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0openCommandList()\0camera1()\0"
    "camera2()\0setResolution()\0setRate()\0"
    "about()\0moveBuggy()\0turnBuggy()\0"
    "setBuggySpeed()\0setSpeedUnits()\0"
    "connectToServer()\0showLocation()\0"
    "zoomMap()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openCommandList(); break;
        case 1: camera1(); break;
        case 2: camera2(); break;
        case 3: setResolution(); break;
        case 4: setRate(); break;
        case 5: about(); break;
        case 6: moveBuggy(); break;
        case 7: turnBuggy(); break;
        case 8: setBuggySpeed(); break;
        case 9: setSpeedUnits(); break;
        case 10: connectToServer(); break;
        case 11: showLocation(); break;
        case 12: zoomMap(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
