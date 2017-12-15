#ifndef WEARABLEGLASSES_H
#define WEARABLEGLASSES_H
#include "wearabledevice.h"
class WearableGlasses : public WearableDevice
{
    Q_OBJECT
public:
    explicit WearableGlasses(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif