#include "joystickperipheral.h"
JoystickPeripheral::JoystickPeripheral(const QBluetoothDeviceInfo &info,QObject *parent):PeripheralDevice(info,"battery",parent)
{
}