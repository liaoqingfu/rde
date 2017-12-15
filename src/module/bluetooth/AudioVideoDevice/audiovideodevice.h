#ifndef AUDIOVIDEODEVICE_H
#define AUDIOVIDEODEVICE_H
#include "device.h"
class AudioVideoDevice : public Device
{
    Q_OBJECT
public:
    explicit AudioVideoDevice(const QBluetoothDeviceInfo &info,const QString iconName,QObject *parent = 0);
};
#endif