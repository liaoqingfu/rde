#ifndef WEARABLEHELMET_H
#define WEARABLEHELMET_H
#include "wearabledevice.h"
class WearableHelmet : public WearableDevice
{
    Q_OBJECT
public:
    explicit WearableHelmet(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif