#ifndef HEALTHSTEPCOUNTER_H
#define HEALTHSTEPCOUNTER_H
#include "healthdevice.h"
class HealthStepCounter : public HealthDevice
{
    Q_OBJECT
public:
    explicit HealthStepCounter(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif