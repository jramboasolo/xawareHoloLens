/****************************************************************************
** Meta object code from reading C++ file 'servertcp.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/servertcp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'servertcp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ServerTcp[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      30,   10,   10,   10, 0x08,
      72,   50,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ServerTcp[] = {
    "ServerTcp\0\0AddNewConnection()\0"
    "deconnexionClient()\0_angleTheta,_anglePhi\0"
    "sendDataSlot(int,int)\0"
};

void ServerTcp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ServerTcp *_t = static_cast<ServerTcp *>(_o);
        switch (_id) {
        case 0: _t->AddNewConnection(); break;
        case 1: _t->deconnexionClient(); break;
        case 2: _t->sendDataSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ServerTcp::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ServerTcp::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_ServerTcp,
      qt_meta_data_ServerTcp, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ServerTcp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ServerTcp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ServerTcp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ServerTcp))
        return static_cast<void*>(const_cast< ServerTcp*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int ServerTcp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
