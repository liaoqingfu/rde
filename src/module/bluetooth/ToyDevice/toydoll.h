#ifndef TOYDOLL_H
#define TOYDOLL_H
#include "toydevice.h"
class ToyDoll : public ToyDevice
{
    Q_OBJECT
public:
    explicit ToyDoll(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif