/****************************************************************************
** Meta object code from reading C++ file 'WorkerClass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../kinect_app/WorkerClass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WorkerClass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WorkerClass_t {
    QByteArrayData data[9];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WorkerClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WorkerClass_t qt_meta_stringdata_WorkerClass = {
    {
QT_MOC_LITERAL(0, 0, 11), // "WorkerClass"
QT_MOC_LITERAL(1, 12, 12), // "processReady"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 17), // "JointOrientation*"
QT_MOC_LITERAL(4, 44, 6), // "joints"
QT_MOC_LITERAL(5, 51, 6), // "Joint*"
QT_MOC_LITERAL(6, 58, 8), // "jointPos"
QT_MOC_LITERAL(7, 67, 4), // "size"
QT_MOC_LITERAL(8, 72, 13) // "recieveRender"

    },
    "WorkerClass\0processReady\0\0JointOrientation*\0"
    "joints\0Joint*\0jointPos\0size\0recieveRender"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WorkerClass[] = {

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
       1,    3,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   31,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, QMetaType::Int,    4,    6,    7,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void WorkerClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WorkerClass *_t = static_cast<WorkerClass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->processReady((*reinterpret_cast< JointOrientation*(*)>(_a[1])),(*reinterpret_cast< Joint*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->recieveRender(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WorkerClass::*_t)(JointOrientation * , Joint * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkerClass::processReady)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject WorkerClass::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_WorkerClass.data,
      qt_meta_data_WorkerClass,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WorkerClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorkerClass::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WorkerClass.stringdata0))
        return static_cast<void*>(const_cast< WorkerClass*>(this));
    return QThread::qt_metacast(_clname);
}

int WorkerClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void WorkerClass::processReady(JointOrientation * _t1, Joint * _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
