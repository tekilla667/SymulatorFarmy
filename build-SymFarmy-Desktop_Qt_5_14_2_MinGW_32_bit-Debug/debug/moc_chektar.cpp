/****************************************************************************
** Meta object code from reading C++ file 'chektar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../SymFarmy/chektar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chektar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CHektar_t {
    QByteArrayData data[14];
    char stringdata0[226];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CHektar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CHektar_t qt_meta_stringdata_CHektar = {
    {
QT_MOC_LITERAL(0, 0, 7), // "CHektar"
QT_MOC_LITERAL(1, 8, 5), // "urzad"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 5), // "sklep"
QT_MOC_LITERAL(4, 21, 16), // "przegladajHektar"
QT_MOC_LITERAL(5, 38, 13), // "nastepnyDzien"
QT_MOC_LITERAL(6, 52, 11), // "naprawUrsus"
QT_MOC_LITERAL(7, 64, 12), // "naprawUrsusX"
QT_MOC_LITERAL(8, 77, 26), // "on_pushButtonUrzad_clicked"
QT_MOC_LITERAL(9, 104, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(10, 126, 27), // "on_przegladajHektar_clicked"
QT_MOC_LITERAL(11, 154, 24), // "on_nastepnyDzien_clicked"
QT_MOC_LITERAL(12, 179, 22), // "on_naprawUrsus_clicked"
QT_MOC_LITERAL(13, 202, 23) // "on_naprawUrsusX_clicked"

    },
    "CHektar\0urzad\0\0sklep\0przegladajHektar\0"
    "nastepnyDzien\0naprawUrsus\0naprawUrsusX\0"
    "on_pushButtonUrzad_clicked\0"
    "on_pushButton_clicked\0on_przegladajHektar_clicked\0"
    "on_nastepnyDzien_clicked\0"
    "on_naprawUrsus_clicked\0on_naprawUrsusX_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CHektar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    0,   76,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,
       6,    0,   78,    2, 0x06 /* Public */,
       7,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CHektar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CHektar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->urzad(); break;
        case 1: _t->sklep(); break;
        case 2: _t->przegladajHektar(); break;
        case 3: _t->nastepnyDzien(); break;
        case 4: _t->naprawUrsus(); break;
        case 5: _t->naprawUrsusX(); break;
        case 6: _t->on_pushButtonUrzad_clicked(); break;
        case 7: _t->on_pushButton_clicked(); break;
        case 8: _t->on_przegladajHektar_clicked(); break;
        case 9: _t->on_nastepnyDzien_clicked(); break;
        case 10: _t->on_naprawUrsus_clicked(); break;
        case 11: _t->on_naprawUrsusX_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CHektar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CHektar::urzad)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CHektar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CHektar::sklep)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CHektar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CHektar::przegladajHektar)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CHektar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CHektar::nastepnyDzien)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CHektar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CHektar::naprawUrsus)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CHektar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CHektar::naprawUrsusX)) {
                *result = 5;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CHektar::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CHektar.data,
    qt_meta_data_CHektar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CHektar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CHektar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CHektar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CHektar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void CHektar::urzad()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CHektar::sklep()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CHektar::przegladajHektar()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CHektar::nastepnyDzien()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void CHektar::naprawUrsus()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void CHektar::naprawUrsusX()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
