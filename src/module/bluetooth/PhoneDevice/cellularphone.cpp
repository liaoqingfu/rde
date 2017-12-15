#include "cellularphone.h"
CellularPhone::CellularPhone(const QBluetoothDeviceInfo &info,QObject *parent):PhoneDevice(info,"phone",parent)
{
}