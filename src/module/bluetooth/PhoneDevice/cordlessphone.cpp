#include "cordlessphone.h"
CordlessPhone::CordlessPhone(const QBluetoothDeviceInfo &info,QObject *parent):PhoneDevice(info,"phone",parent)
{
}