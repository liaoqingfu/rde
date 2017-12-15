#include "digitizertabletperipheral.h"
DigitizerTabletPeripheral::DigitizerTabletPeripheral(const QBluetoothDeviceInfo &info,QObject *parent):PeripheralDevice(info,"input-tablet",parent)
{
}