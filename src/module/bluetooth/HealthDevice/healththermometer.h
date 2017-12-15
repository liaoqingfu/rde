#ifndef HEALTHTHERMOMETER_H
#define HEALTHTHERMOMETER_H
#include "healthdevice.h"
class HealthThermometer : public HealthDevice
{
    Q_OBJECT
public:
    explicit HealthThermometer(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif