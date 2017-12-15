#ifndef CAMCORDER_H
#define CAMCORDER_H
#include "audiovideodevice.h"
class Camcorder : public AudioVideoDevice
{
    Q_OBJECT
public:
    explicit Camcorder(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif