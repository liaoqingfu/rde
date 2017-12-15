#include "smartphone.h"
SmartPhone::SmartPhone(const QBluetoothDeviceInfo &info,QObject *parent):PhoneDevice(info,"smartphone",parent)
{
}