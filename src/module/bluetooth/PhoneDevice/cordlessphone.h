#ifndef CORDLESSPHONE_H
#define CORDLESSPHONE_H
#include "phonedevice.h"
class CordlessPhone : public PhoneDevice
{
    Q_OBJECT
public:
    explicit CordlessPhone(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif