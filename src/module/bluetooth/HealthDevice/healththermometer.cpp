#include "healththermometer.h"
HealthThermometer::HealthThermometer(const QBluetoothDeviceInfo &info,QObject *parent):HealthDevice(info,"battery",parent)
{
}