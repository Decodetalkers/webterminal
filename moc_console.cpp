/****************************************************************************
** Meta object code from reading C++ file 'console.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "widgets/console.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'console.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_console_t {
    QByteArrayData data[11];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_console_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_console_t qt_meta_stringdata_console = {
    {
QT_MOC_LITERAL(0, 0, 7), // "console"
QT_MOC_LITERAL(1, 8, 11), // "get_the_url"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 5), // "check"
QT_MOC_LITERAL(4, 27, 8), // "give_url"
QT_MOC_LITERAL(5, 36, 5), // "close"
QT_MOC_LITERAL(6, 42, 19), // "change_the_location"
QT_MOC_LITERAL(7, 62, 16), // "change_the_title"
QT_MOC_LITERAL(8, 79, 8), // "QWidget*"
QT_MOC_LITERAL(9, 88, 6), // "parent"
QT_MOC_LITERAL(10, 95, 3) // "Url"

    },
    "console\0get_the_url\0\0check\0give_url\0"
    "close\0change_the_location\0change_the_title\0"
    "QWidget*\0parent\0Url"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_console[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       3,   61, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   48,    2, 0x0a /* Public */,
       5,    0,   49,    2, 0x08 /* Private */,
       6,    0,   50,    2, 0x08 /* Private */,
       7,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::QString, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // constructors: parameters
    0x80000000 | 2, 0x80000000 | 8, QMetaType::QString,    9,   10,
    0x80000000 | 2, 0x80000000 | 8,    9,
    0x80000000 | 2,

 // constructors: name, argc, parameters, tag, flags
       0,    2,   52,    2, 0x0e /* Public */,
       0,    1,   57,    2, 0x2e /* Public | MethodCloned */,
       0,    0,   60,    2, 0x2e /* Public | MethodCloned */,

       0        // eod
};

void console::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { console *_r = new console((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        case 1: { console *_r = new console((*reinterpret_cast< QWidget*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        case 2: { console *_r = new console();
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    } else if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<console *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->get_the_url((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->check(); break;
        case 2: _t->give_url(); break;
        case 3: _t->close(); break;
        case 4: _t->change_the_location(); break;
        case 5: _t->change_the_title(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = QString (console::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&console::get_the_url)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (console::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&console::check)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject console::staticMetaObject = { {
    QMetaObject::SuperData::link<Item::staticMetaObject>(),
    qt_meta_stringdata_console.data,
    qt_meta_data_console,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *console::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *console::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_console.stringdata0))
        return static_cast<void*>(this);
    return Item::qt_metacast(_clname);
}

int console::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Item::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
QString console::get_the_url(QString _t1)
{
    QString _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
void console::check()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
