#include "keyboardwithpointingdeviceperipheral.h"
KeyboardWithPointingDevicePeripheral::KeyboardWithPointingDevicePeripheral(const QBluetoothDeviceInfo &info,QObject *parent):PeripheralDevice(info,"battery",parent)
{
}