/****************************************************************************
** Resource object code
**
** Created: Fri Aug 20 15:59:34 2010
**      by: The Resource Compiler for Qt version 4.6.3
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtCore/qglobal.h>

static const unsigned char qt_resource_data[] = {
  // /home/abhinay/Work/RacerX/cfg/server.cfg
  0x0,0x0,0x0,0x1b,
  0x73,
  0x65,0x72,0x76,0x65,0x72,0x2e,0x63,0x66,0x67,0xa,0xa,0x31,0x32,0x37,0x2e,0x30,
  0x2e,0x30,0x2e,0x31,0x20,0x35,0x30,0x30,0x31,0xa,
  
};

static const unsigned char qt_resource_name[] = {
  // RacerX
  0x0,0x6,
  0x5,0x87,0x9c,0x78,
  0x0,0x52,
  0x0,0x61,0x0,0x63,0x0,0x65,0x0,0x72,0x0,0x58,
    // cfg
  0x0,0x3,
  0x0,0x0,0x69,0xc7,
  0x0,0x63,
  0x0,0x66,0x0,0x67,
    // server.cfg
  0x0,0xa,
  0xc,0xca,0x70,0xe7,
  0x0,0x73,
  0x0,0x65,0x0,0x72,0x0,0x76,0x0,0x65,0x0,0x72,0x0,0x2e,0x0,0x63,0x0,0x66,0x0,0x67,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
  // :/RacerX
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
  // :/RacerX/cfg
  0x0,0x0,0x0,0x12,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x3,
  // :/RacerX/cfg/server.cfg
  0x0,0x0,0x0,0x1e,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,

};

QT_BEGIN_NAMESPACE

extern Q_CORE_EXPORT bool qRegisterResourceData
    (int, const unsigned char *, const unsigned char *, const unsigned char *);

extern Q_CORE_EXPORT bool qUnregisterResourceData
    (int, const unsigned char *, const unsigned char *, const unsigned char *);

QT_END_NAMESPACE


int QT_MANGLE_NAMESPACE(qInitResources_fileResource)()
{
    QT_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_fileResource))

int QT_MANGLE_NAMESPACE(qCleanupResources_fileResource)()
{
    QT_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

Q_DESTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qCleanupResources_fileResource))

