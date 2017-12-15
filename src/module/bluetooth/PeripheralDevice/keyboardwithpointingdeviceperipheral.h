#ifndef KEYBOARDWITHPOINTINGDEVICEPERIPHERAL_H
#define KEYBOARDWITHPOINTINGDEVICEPERIPHERAL_H
#include "peripheraldevice.h"
class KeyboardWithPointingDevicePeripheral:public PeripheralDevice
{
    Q_OBJECT
public:
    explicit KeyboardWithPointingDevicePeripheral(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif