/****************************************************************************
** Meta object code from reading C++ file 'contextmenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Visualvers/contextmenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contextmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ContextMenu_t {
    QByteArrayData data[5];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ContextMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ContextMenu_t qt_meta_stringdata_ContextMenu = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ContextMenu"
QT_MOC_LITERAL(1, 12, 29), // "on_switchToNodeButton_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 31), // "on_pullFromCommitButton_clicked"
QT_MOC_LITERAL(4, 75, 29) // "on_diffWithNodeButton_clicked"

    },
    "ContextMenu\0on_switchToNodeButton_clicked\0"
    "\0on_pullFromCommitButton_clicked\0"
    "on_diffWithNodeButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ContextMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    0,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ContextMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ContextMenu *_t = static_cast<ContextMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_switchToNodeButton_clicked(); break;
        case 1: _t->on_pullFromCommitButton_clicked(); break;
        case 2: _t->on_diffWithNodeButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ContextMenu::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ContextMenu.data,
      qt_meta_data_ContextMenu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ContextMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ContextMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ContextMenu.stringdata0))
        return static_cast<void*>(const_cast< ContextMenu*>(this));
    return QDialog::qt_metacast(_clname);
}

int ContextMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
