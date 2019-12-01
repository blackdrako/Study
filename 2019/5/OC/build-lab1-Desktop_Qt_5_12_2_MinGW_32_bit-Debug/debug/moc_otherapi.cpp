/****************************************************************************
** Meta object code from reading C++ file 'otherapi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lab1/otherapi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'otherapi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OtherAPI_t {
    QByteArrayData data[15];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OtherAPI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OtherAPI_t qt_meta_stringdata_OtherAPI = {
    {
QT_MOC_LITERAL(0, 0, 8), // "OtherAPI"
QT_MOC_LITERAL(1, 9, 20), // "signalSetLastErrCode"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "code"
QT_MOC_LITERAL(4, 36, 19), // "signalSetLastErrMsg"
QT_MOC_LITERAL(5, 56, 7), // "message"
QT_MOC_LITERAL(6, 64, 17), // "signalSetCurrency"
QT_MOC_LITERAL(7, 82, 5), // "value"
QT_MOC_LITERAL(8, 88, 12), // "oemToCharOut"
QT_MOC_LITERAL(9, 101, 3), // "str"
QT_MOC_LITERAL(10, 105, 11), // "updateError"
QT_MOC_LITERAL(11, 117, 14), // "updateCurrency"
QT_MOC_LITERAL(12, 132, 12), // "switchKBNext"
QT_MOC_LITERAL(13, 145, 12), // "switchKBPrev"
QT_MOC_LITERAL(14, 158, 11) // "oemToCharIn"

    },
    "OtherAPI\0signalSetLastErrCode\0\0code\0"
    "signalSetLastErrMsg\0message\0"
    "signalSetCurrency\0value\0oemToCharOut\0"
    "str\0updateError\0updateCurrency\0"
    "switchKBNext\0switchKBPrev\0oemToCharIn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OtherAPI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       6,    1,   65,    2, 0x06 /* Public */,
       8,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   71,    2, 0x0a /* Public */,
      11,    1,   72,    2, 0x0a /* Public */,
      12,    0,   75,    2, 0x0a /* Public */,
      13,    0,   76,    2, 0x0a /* Public */,
      14,    1,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void OtherAPI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OtherAPI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalSetLastErrCode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->signalSetLastErrMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->signalSetCurrency((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->oemToCharOut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->updateError(); break;
        case 5: _t->updateCurrency((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->switchKBNext(); break;
        case 7: _t->switchKBPrev(); break;
        case 8: _t->oemToCharIn((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OtherAPI::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OtherAPI::signalSetLastErrCode)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (OtherAPI::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OtherAPI::signalSetLastErrMsg)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (OtherAPI::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OtherAPI::signalSetCurrency)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (OtherAPI::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OtherAPI::oemToCharOut)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OtherAPI::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_OtherAPI.data,
    qt_meta_data_OtherAPI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OtherAPI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OtherAPI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OtherAPI.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int OtherAPI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void OtherAPI::signalSetLastErrCode(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OtherAPI::signalSetLastErrMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void OtherAPI::signalSetCurrency(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void OtherAPI::oemToCharOut(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
