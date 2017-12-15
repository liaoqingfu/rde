#ifndef WEARABLEWRISTWATCH_H
#define WEARABLEWRISTWATCH_H
#include "wearabledevice.h"
class WearableWristWatch : public WearableDevice
{
    Q_OBJECT
public:
    explicit WearableWristWatch(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif