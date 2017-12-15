#include "healthbloodpressuremonitor.h"
HealthBloodPressureMonitor::HealthBloodPressureMonitor(const QBluetoothDeviceInfo &info,QObject *parent):HealthDevice(info,"battery",parent)
{
}