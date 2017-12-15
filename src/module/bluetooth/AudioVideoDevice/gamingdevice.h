#ifndef GAMINGDEVICE_H
#define GAMINGDEVICE_H
#include "audiovideodevice.h"
class GamingDevice : public AudioVideoDevice
{
    Q_OBJECT
public:
    explicit GamingDevice(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif