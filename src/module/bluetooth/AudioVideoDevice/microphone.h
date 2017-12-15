#ifndef MICROPHONE_H
#define MICROPHONE_H
#include "audiovideodevice.h"
class Microphone : public AudioVideoDevice
{
    Q_OBJECT
public:
    explicit Microphone(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif