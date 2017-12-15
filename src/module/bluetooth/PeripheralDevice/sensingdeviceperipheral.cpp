#include "sensingdeviceperipheral.h"
SensingDevicePeripheral::SensingDevicePeripheral(const QBluetoothDeviceInfo &info,QObject *parent):PeripheralDevice(info,"battery",parent)
{
}