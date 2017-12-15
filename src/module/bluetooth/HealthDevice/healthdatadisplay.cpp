#include "healthdatadisplay.h"
HealthDataDisplay::HealthDataDisplay(const QBluetoothDeviceInfo &info,QObject *parent):HealthDevice(info,"battery",parent)
{
}