#ifndef HEALTHDEVICE_H
/*                                                                                               */
#define HEALTHDEVICE_H
#include "device.h"
/*                                                                                               */
class HealthDevice : public Device
{
    Q_OBJECT
public:
    explicit HealthDevice(const QBluetoothDeviceInfo &info,const QString iconName,QObject *parent = 0);
};
/*                                                                                               */
#endif