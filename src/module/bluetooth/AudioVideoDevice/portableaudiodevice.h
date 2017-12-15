#ifndef PORTABLEAUDIODEVICE_H
#define PORTABLEAUDIODEVICE_H
#include "audiovideodevice.h"
class PortableAudioDevice : public AudioVideoDevice
{
    Q_OBJECT
public:
    explicit PortableAudioDevice(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif