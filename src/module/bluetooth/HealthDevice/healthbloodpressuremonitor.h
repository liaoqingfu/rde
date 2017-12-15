#ifndef HEALTHBLOODPRESSUREMONITOR_H
#define HEALTHBLOODPRESSUREMONITOR_H
#include "healthdevice.h"
class HealthBloodPressureMonitor : public HealthDevice
{
    Q_OBJECT
public:
    explicit HealthBloodPressureMonitor(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif