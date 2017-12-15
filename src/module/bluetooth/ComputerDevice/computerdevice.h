#ifndef COMPUTERDEVICE_H
#define COMPUTERDEVICE_H
#include "device.h"
class ComputerDevice : public Device
{
    Q_OBJECT
public:
    explicit ComputerDevice(const QBluetoothDeviceInfo &info,const QString iconName,QObject *parent = 0);
};
#endif