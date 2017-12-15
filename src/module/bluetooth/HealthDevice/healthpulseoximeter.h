#ifndef HEALTHPULSEOXIMETER_H
#define HEALTHPULSEOXIMETER_H
#include "healthdevice.h"
class HealthPulseOximeter : public HealthDevice
{
    Q_OBJECT
public:
    explicit HealthPulseOximeter(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif