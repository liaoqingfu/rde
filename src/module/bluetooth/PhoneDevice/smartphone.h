#ifndef SMARTPHONE_H
#define SMARTPHONE_H
#include "phonedevice.h"
class SmartPhone : public PhoneDevice
{
    Q_OBJECT
public:
    explicit SmartPhone(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif