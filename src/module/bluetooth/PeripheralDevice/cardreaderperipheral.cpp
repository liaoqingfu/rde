#include "cardreaderperipheral.h"
CardReaderPeripheral::CardReaderPeripheral(const QBluetoothDeviceInfo &info,QObject *parent):PeripheralDevice(info,"battery",parent)
{
}