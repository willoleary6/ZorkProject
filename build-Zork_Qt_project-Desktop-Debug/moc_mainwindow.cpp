/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Zork_Qt_project/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[403];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 8), // "showTime"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 24), // "on_actionClose_triggered"
QT_MOC_LITERAL(4, 46, 27), // "on_actionSettings_triggered"
QT_MOC_LITERAL(5, 74, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(6, 99, 22), // "on_northButton_clicked"
QT_MOC_LITERAL(7, 122, 25), // "on_upstairsButton_clicked"
QT_MOC_LITERAL(8, 148, 27), // "on_downstairsButton_clicked"
QT_MOC_LITERAL(9, 176, 21), // "on_westButton_clicked"
QT_MOC_LITERAL(10, 198, 21), // "on_eastButton_clicked"
QT_MOC_LITERAL(11, 220, 22), // "on_southButton_clicked"
QT_MOC_LITERAL(12, 243, 24), // "on_roomItems_itemClicked"
QT_MOC_LITERAL(13, 268, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(14, 285, 4), // "item"
QT_MOC_LITERAL(15, 290, 6), // "column"
QT_MOC_LITERAL(16, 297, 24), // "on_inventory_itemClicked"
QT_MOC_LITERAL(17, 322, 23), // "on_escapeButton_clicked"
QT_MOC_LITERAL(18, 346, 27), // "on_actionNew_Game_triggered"
QT_MOC_LITERAL(19, 374, 28) // "on_actionQuit_Game_triggered"

    },
    "MainWindow\0showTime\0\0on_actionClose_triggered\0"
    "on_actionSettings_triggered\0"
    "on_actionAbout_triggered\0"
    "on_northButton_clicked\0on_upstairsButton_clicked\0"
    "on_downstairsButton_clicked\0"
    "on_westButton_clicked\0on_eastButton_clicked\0"
    "on_southButton_clicked\0on_roomItems_itemClicked\0"
    "QTreeWidgetItem*\0item\0column\0"
    "on_inventory_itemClicked\0"
    "on_escapeButton_clicked\0"
    "on_actionNew_Game_triggered\0"
    "on_actionQuit_Game_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    2,   99,    2, 0x08 /* Private */,
      16,    2,  104,    2, 0x08 /* Private */,
      17,    0,  109,    2, 0x08 /* Private */,
      18,    0,  110,    2, 0x08 /* Private */,
      19,    0,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int,   14,   15,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int,   14,   15,
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
        case 0: _t->showTime(); break;
        case 1: _t->on_actionClose_triggered(); break;
        case 2: _t->on_actionSettings_triggered(); break;
        case 3: _t->on_actionAbout_triggered(); break;
        case 4: _t->on_northButton_clicked(); break;
        case 5: _t->on_upstairsButton_clicked(); break;
        case 6: _t->on_downstairsButton_clicked(); break;
        case 7: _t->on_westButton_clicked(); break;
        case 8: _t->on_eastButton_clicked(); break;
        case 9: _t->on_southButton_clicked(); break;
        case 10: _t->on_roomItems_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->on_inventory_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->on_escapeButton_clicked(); break;
        case 13: _t->on_actionNew_Game_triggered(); break;
        case 14: _t->on_actionQuit_Game_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
