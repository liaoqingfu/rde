#include "healthstepcounter.h"
HealthStepCounter::HealthStepCounter(const QBluetoothDeviceInfo &info,QObject *parent):HealthDevice(info,"battery",parent)
{
}