#include "healthpulseoximeter.h"
HealthPulseOximeter::HealthPulseOximeter(const QBluetoothDeviceInfo &info,QObject *parent):HealthDevice(info,"battery",parent)
{
}