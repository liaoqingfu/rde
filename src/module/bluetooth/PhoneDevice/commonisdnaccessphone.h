#ifndef COMMONISDNACCESSPHONE_H
#define COMMONISDNACCESSPHONE_H
#include "phonedevice.h"
class CommonIsdnAccessPhone : public PhoneDevice
{
    Q_OBJECT
public:
    explicit CommonIsdnAccessPhone(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif