#ifndef CARAUDIO_H
#define CARAUDIO_H
#include "audiovideodevice.h"
class CarAudio : public AudioVideoDevice
{
    Q_OBJECT
public:
    explicit CarAudio(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif