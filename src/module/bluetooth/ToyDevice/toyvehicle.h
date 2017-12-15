#ifndef TOYVEHICLE_H
#define TOYVEHICLE_H
#include "toydevice.h"
class ToyVehicle : public ToyDevice
{
    Q_OBJECT
public:
    explicit ToyVehicle(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif