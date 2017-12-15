#ifndef WEARABLEPAGER_H
#define WEARABLEPAGER_H
#include "wearabledevice.h"
class WearablePager : public WearableDevice
{
    Q_OBJECT
public:
    explicit WearablePager(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif