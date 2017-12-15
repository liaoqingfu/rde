#ifndef WEARABLEHEADSETDEVICE_H
#define WEARABLEHEADSETDEVICE_H
#include "audiovideodevice.h"
class WearableHeadsetDevice : public AudioVideoDevice
{
    Q_OBJECT
public:
    explicit WearableHeadsetDevice(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif