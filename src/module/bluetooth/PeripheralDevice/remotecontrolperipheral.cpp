#include "remotecontrolperipheral.h"
RemoteControlPeripheral::RemoteControlPeripheral(const QBluetoothDeviceInfo &info,QObject *parent):PeripheralDevice(info,"battery",parent)
{
}