/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SocialForceQT/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[326];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "on_showForces_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 7), // "checked"
QT_MOC_LITERAL(4, 42, 24), // "on_showDirection_clicked"
QT_MOC_LITERAL(5, 67, 24), // "on_showWayPoints_clicked"
QT_MOC_LITERAL(6, 92, 28), // "on_destForceCoe_valueChanged"
QT_MOC_LITERAL(7, 121, 4), // "arg1"
QT_MOC_LITERAL(8, 126, 32), // "on_obstacleForceCoe_valueChanged"
QT_MOC_LITERAL(9, 159, 30), // "on_agentsForceCoe_valueChanged"
QT_MOC_LITERAL(10, 190, 24), // "on_loadScenarioB_clicked"
QT_MOC_LITERAL(11, 215, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(12, 248, 5), // "value"
QT_MOC_LITERAL(13, 254, 19), // "on_restartB_clicked"
QT_MOC_LITERAL(14, 274, 21), // "on_startStopB_clicked"
QT_MOC_LITERAL(15, 296, 29) // "on_resetCoefficientsB_clicked"

    },
    "MainWindow\0on_showForces_clicked\0\0"
    "checked\0on_showDirection_clicked\0"
    "on_showWayPoints_clicked\0"
    "on_destForceCoe_valueChanged\0arg1\0"
    "on_obstacleForceCoe_valueChanged\0"
    "on_agentsForceCoe_valueChanged\0"
    "on_loadScenarioB_clicked\0"
    "on_horizontalSlider_valueChanged\0value\0"
    "on_restartB_clicked\0on_startStopB_clicked\0"
    "on_resetCoefficientsB_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08 /* Private */,
       4,    1,   72,    2, 0x08 /* Private */,
       5,    1,   75,    2, 0x08 /* Private */,
       6,    1,   78,    2, 0x08 /* Private */,
       8,    1,   81,    2, 0x08 /* Private */,
       9,    1,   84,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    1,   88,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_showForces_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_showDirection_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_showWayPoints_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_destForceCoe_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->on_obstacleForceCoe_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->on_agentsForceCoe_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->on_loadScenarioB_clicked(); break;
        case 7: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_restartB_clicked(); break;
        case 9: _t->on_startStopB_clicked(); break;
        case 10: _t->on_resetCoefficientsB_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
