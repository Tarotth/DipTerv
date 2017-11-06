/****************************************************************************
** Meta object code from reading C++ file 'kinect_app.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../kinect_app.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kinect_app.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_kinect_app_t {
    QByteArrayData data[9];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_kinect_app_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_kinect_app_t qt_meta_stringdata_kinect_app = {
    {
QT_MOC_LITERAL(0, 0, 10), // "kinect_app"
QT_MOC_LITERAL(1, 11, 11), // "renderReady"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 14), // "recieveProcess"
QT_MOC_LITERAL(4, 39, 17), // "JointOrientation*"
QT_MOC_LITERAL(5, 57, 6), // "joints"
QT_MOC_LITERAL(6, 64, 6), // "Joint*"
QT_MOC_LITERAL(7, 71, 8), // "jointPos"
QT_MOC_LITERAL(8, 80, 4) // "size"

    },
    "kinect_app\0renderReady\0\0recieveProcess\0"
    "JointOrientation*\0joints\0Joint*\0"
    "jointPos\0size"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_kinect_app[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    3,   25,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6, QMetaType::Int,    5,    7,    8,

       0        // eod
};

void kinect_app::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        kinect_app *_t = static_cast<kinect_app *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->renderReady(); break;
        case 1: _t->recieveProcess((*reinterpret_cast< JointOrientation*(*)>(_a[1])),(*reinterpret_cast< Joint*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (kinect_app::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&kinect_app::renderReady)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject kinect_app::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_kinect_app.data,
      qt_meta_data_kinect_app,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *kinect_app::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *kinect_app::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_kinect_app.stringdata0))
        return static_cast<void*>(const_cast< kinect_app*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int kinect_app::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void kinect_app::renderReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
