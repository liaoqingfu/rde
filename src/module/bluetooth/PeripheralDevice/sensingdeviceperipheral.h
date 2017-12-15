#ifndef SENSINGDEVICEPERIPHERAL_H
#define SENSINGDEVICEPERIPHERAL_H
#include "peripheraldevice.h"
class SensingDevicePeripheral : public PeripheralDevice
{
    Q_OBJECT
public:
    explicit SensingDevicePeripheral(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif