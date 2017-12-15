#ifndef HEALTHWEIGHTSCALE_H
#define HEALTHWEIGHTSCALE_H
#include "healthdevice.h"
class HealthWeightScale : public HealthDevice
{
    Q_OBJECT
public:
    explicit HealthWeightScale(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif