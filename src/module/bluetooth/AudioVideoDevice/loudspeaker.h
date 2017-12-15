#ifndef LOUDSPEAKER_H
#define LOUDSPEAKER_H
#include "audiovideodevice.h"
class Loudspeaker : public AudioVideoDevice
{
    Q_OBJECT
public:
    explicit Loudspeaker(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif