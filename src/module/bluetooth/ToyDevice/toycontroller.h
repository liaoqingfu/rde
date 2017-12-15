#ifndef TOYCONTROLLER_H
#define TOYCONTROLLER_H
#include "toydevice.h"
class ToyController : public ToyDevice
{
    Q_OBJECT
public:
    explicit ToyController(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif