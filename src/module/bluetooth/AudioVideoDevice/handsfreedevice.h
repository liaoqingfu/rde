#ifndef HANDSFREEDEVICE_H
#define HANDSFREEDEVICE_H
#include "audiovideodevice.h"
class HandsFreeDevice : public AudioVideoDevice
{
    Q_OBJECT
public:
    explicit HandsFreeDevice(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif