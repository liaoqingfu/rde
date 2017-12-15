#ifndef HEALTHGLUCOSEMETER_H
#define HEALTHGLUCOSEMETER_H
#include "healthdevice.h"
class HealthGlucoseMeter : public HealthDevice
{
    Q_OBJECT
public:
    explicit HealthGlucoseMeter(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif