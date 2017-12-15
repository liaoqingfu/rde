#ifndef TOYDEVICE_H
#define TOYDEVICE_H
#include "device.h"
class ToyDevice : public Device
{
    Q_OBJECT
public:
    explicit ToyDevice(const QBluetoothDeviceInfo &info,const QString iconName,QObject *parent = 0);
};
#endif