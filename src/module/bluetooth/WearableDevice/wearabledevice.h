#ifndef WEARABLEDEVICE_H
#define WEARABLEDEVICE_H
#include "device.h"
class WearableDevice : public Device
{
    Q_OBJECT
public:
    explicit WearableDevice(const QBluetoothDeviceInfo &info,const QString iconName,QObject *parent = 0);
};
#endif