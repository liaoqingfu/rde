#ifndef CELLULARPHONE_H
#define CELLULARPHONE_H
#include "phonedevice.h"
class CellularPhone : public PhoneDevice
{
    Q_OBJECT
public:
    explicit CellularPhone(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif