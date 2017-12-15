#include "pointingdeviceperipheral.h"
PointingDevicePeripheral::PointingDevicePeripheral(const QBluetoothDeviceInfo &info,QObject *parent):PeripheralDevice(info,"input-mouse",parent)
{
}