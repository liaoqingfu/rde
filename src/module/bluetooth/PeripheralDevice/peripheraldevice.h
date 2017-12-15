#ifndef PERIPHERALDEVICE_H
#define PERIPHERALDEVICE_H
#include "device.h"
class PeripheralDevice : public Device
{
    Q_OBJECT
public:
    explicit PeripheralDevice(const QBluetoothDeviceInfo &info,const QString iconName,QObject *parent = 0);
};
#endif