#ifndef REMOTECONTROLPERIPHERAL_H
#define REMOTECONTROLPERIPHERAL_H
#include "peripheraldevice.h"
class RemoteControlPeripheral : public PeripheralDevice
{
    Q_OBJECT
public:
    explicit RemoteControlPeripheral(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif