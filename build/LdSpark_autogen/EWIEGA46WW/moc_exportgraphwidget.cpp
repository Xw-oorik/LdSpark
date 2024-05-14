/****************************************************************************
** Meta object code from reading C++ file 'exportgraphwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../exportgraphwidget.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'exportgraphwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSExportGraphWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSExportGraphWidgetENDCLASS = QtMocHelpers::stringData(
    "ExportGraphWidget",
    "exportPNGSignal",
    "",
    "id",
    "start",
    "end",
    "QList<bool>",
    "_ifchecked",
    "combIndexChanged",
    "index",
    "exportClicked",
    "selectAllToggled",
    "checked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSExportGraphWidgetENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[18];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[3];
    char stringdata4[6];
    char stringdata5[4];
    char stringdata6[12];
    char stringdata7[11];
    char stringdata8[17];
    char stringdata9[6];
    char stringdata10[14];
    char stringdata11[17];
    char stringdata12[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSExportGraphWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSExportGraphWidgetENDCLASS_t qt_meta_stringdata_CLASSExportGraphWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 17),  // "ExportGraphWidget"
        QT_MOC_LITERAL(18, 15),  // "exportPNGSignal"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 2),  // "id"
        QT_MOC_LITERAL(38, 5),  // "start"
        QT_MOC_LITERAL(44, 3),  // "end"
        QT_MOC_LITERAL(48, 11),  // "QList<bool>"
        QT_MOC_LITERAL(60, 10),  // "_ifchecked"
        QT_MOC_LITERAL(71, 16),  // "combIndexChanged"
        QT_MOC_LITERAL(88, 5),  // "index"
        QT_MOC_LITERAL(94, 13),  // "exportClicked"
        QT_MOC_LITERAL(108, 16),  // "selectAllToggled"
        QT_MOC_LITERAL(125, 7)   // "checked"
    },
    "ExportGraphWidget",
    "exportPNGSignal",
    "",
    "id",
    "start",
    "end",
    "QList<bool>",
    "_ifchecked",
    "combIndexChanged",
    "index",
    "exportClicked",
    "selectAllToggled",
    "checked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSExportGraphWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    4,   38,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   47,    2, 0x08,    6 /* Private */,
      10,    0,   50,    2, 0x08,    8 /* Private */,
      11,    1,   51,    2, 0x08,    9 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QDateTime, QMetaType::QDateTime, 0x80000000 | 6,    3,    4,    5,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,

       0        // eod
};

Q_CONSTINIT const QMetaObject ExportGraphWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSExportGraphWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSExportGraphWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSExportGraphWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ExportGraphWidget, std::true_type>,
        // method 'exportPNGSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDateTime, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDateTime, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<bool>, std::false_type>,
        // method 'combIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'exportClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'selectAllToggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void ExportGraphWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ExportGraphWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->exportPNGSignal((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QList<bool>>>(_a[4]))); break;
        case 1: _t->combIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->exportClicked(); break;
        case 3: _t->selectAllToggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 3:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<bool> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ExportGraphWidget::*)(int , QDateTime , QDateTime , QList<bool> );
            if (_t _q_method = &ExportGraphWidget::exportPNGSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *ExportGraphWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExportGraphWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSExportGraphWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ExportGraphWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ExportGraphWidget::exportPNGSignal(int _t1, QDateTime _t2, QDateTime _t3, QList<bool> _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
