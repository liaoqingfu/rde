#ifndef JOYSTICKPERIPHERAL_H
#define JOYSTICKPERIPHERAL_H
#include "peripheraldevice.h"
class JoystickPeripheral: public PeripheralDevice
{
public:
    JoystickPeripheral(const QBluetoothDeviceInfo &info,QObject *parent);
};
#endif