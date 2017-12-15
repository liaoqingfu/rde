#ifndef HIFIAUDIODEVICE_H
#define HIFIAUDIODEVICE_H
#include "audiovideodevice.h"
class HiFiAudioDevice : public AudioVideoDevice
{
    Q_OBJECT
public:
    explicit HiFiAudioDevice(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif