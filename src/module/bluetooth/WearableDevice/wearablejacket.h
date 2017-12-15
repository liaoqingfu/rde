#ifndef WEARABLEJACKET_H
#define WEARABLEJACKET_H
#include "wearabledevice.h"
class WearableJacket : public WearableDevice
{
    Q_OBJECT
public:
    explicit WearableJacket(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif