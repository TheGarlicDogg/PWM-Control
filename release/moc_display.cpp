/****************************************************************************
** Meta object code from reading C++ file 'display.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../display.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Display_t {
    QByteArrayData data[17];
    char stringdata0[318];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Display_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Display_t qt_meta_stringdata_Display = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Display"
QT_MOC_LITERAL(1, 8, 21), // "on_PlayButton_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 21), // "on_StopButton_clicked"
QT_MOC_LITERAL(4, 53, 25), // "on_MoveLeftButton_clicked"
QT_MOC_LITERAL(5, 79, 12), // "PlaybackStep"
QT_MOC_LITERAL(6, 92, 26), // "on_MoveRightButton_clicked"
QT_MOC_LITERAL(7, 119, 10), // "mouseWheel"
QT_MOC_LITERAL(8, 130, 12), // "QWheelEvent*"
QT_MOC_LITERAL(9, 143, 5), // "event"
QT_MOC_LITERAL(10, 149, 25), // "on_timeSlider_sliderMoved"
QT_MOC_LITERAL(11, 175, 8), // "position"
QT_MOC_LITERAL(12, 184, 27), // "on_addSignalsButton_clicked"
QT_MOC_LITERAL(13, 212, 30), // "on_removeSignalsButton_clicked"
QT_MOC_LITERAL(14, 243, 30), // "on_submitSignalsButton_clicked"
QT_MOC_LITERAL(15, 274, 21), // "on_ZoomButton_clicked"
QT_MOC_LITERAL(16, 296, 21) // "on_pushButton_clicked"

    },
    "Display\0on_PlayButton_clicked\0\0"
    "on_StopButton_clicked\0on_MoveLeftButton_clicked\0"
    "PlaybackStep\0on_MoveRightButton_clicked\0"
    "mouseWheel\0QWheelEvent*\0event\0"
    "on_timeSlider_sliderMoved\0position\0"
    "on_addSignalsButton_clicked\0"
    "on_removeSignalsButton_clicked\0"
    "on_submitSignalsButton_clicked\0"
    "on_ZoomButton_clicked\0on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Display[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    1,   79,    2, 0x08 /* Private */,
      10,    1,   82,    2, 0x08 /* Private */,
      12,    0,   85,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    0,   87,    2, 0x08 /* Private */,
      15,    0,   88,    2, 0x08 /* Private */,
      16,    0,   89,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Display::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Display *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_PlayButton_clicked(); break;
        case 1: _t->on_StopButton_clicked(); break;
        case 2: _t->on_MoveLeftButton_clicked(); break;
        case 3: _t->PlaybackStep(); break;
        case 4: _t->on_MoveRightButton_clicked(); break;
        case 5: _t->mouseWheel((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 6: _t->on_timeSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_addSignalsButton_clicked(); break;
        case 8: _t->on_removeSignalsButton_clicked(); break;
        case 9: _t->on_submitSignalsButton_clicked(); break;
        case 10: _t->on_ZoomButton_clicked(); break;
        case 11: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Display::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Display.data,
    qt_meta_data_Display,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Display::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Display::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Display.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Display::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
