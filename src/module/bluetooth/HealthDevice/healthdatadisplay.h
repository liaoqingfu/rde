#ifndef HEALTHDATADISPLAY_H
#define HEALTHDATADISPLAY_H
#include "healthdevice.h"
class HealthDataDisplay : public HealthDevice
{
    Q_OBJECT
public:
    explicit HealthDataDisplay(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif