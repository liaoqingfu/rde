#ifndef POINTINGDEVICEPERIPHERAL_H
#define POINTINGDEVICEPERIPHERAL_H
#include "peripheraldevice.h"
class PointingDevicePeripheral : public PeripheralDevice
{
    Q_OBJECT
public:
    explicit PointingDevicePeripheral(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif