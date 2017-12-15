#include "keyboardperipheral.h"
KeyboardPeripheral::KeyboardPeripheral(const QBluetoothDeviceInfo &info,QObject *parent):PeripheralDevice(info,"battery",parent)
{
}