#include "healthglucosemeter.h"
HealthGlucoseMeter::HealthGlucoseMeter(const QBluetoothDeviceInfo &info,QObject *parent):HealthDevice(info,"battery",parent)
{
}