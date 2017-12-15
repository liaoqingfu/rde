#ifndef HEADPHONES_H
#define HEADPHONES_H
#include "audiovideodevice.h"
class Headphones : public AudioVideoDevice
{
    Q_OBJECT
public:
    explicit Headphones(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif