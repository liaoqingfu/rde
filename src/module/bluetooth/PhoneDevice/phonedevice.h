#ifndef PHONEDEVICE_H
#define PHONEDEVICE_H
#include "device.h"
class PhoneDevice : public Device
{
    Q_OBJECT
public:
    explicit PhoneDevice(const QBluetoothDeviceInfo &info,const QString iconName,QObject *parent = 0);
};
#endif