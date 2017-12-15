#include "gamepadperipheral.h"
GamepadPeripheral::GamepadPeripheral(const QBluetoothDeviceInfo &info,QObject *parent):PeripheralDevice(info,"input-gaming",parent)
{
}