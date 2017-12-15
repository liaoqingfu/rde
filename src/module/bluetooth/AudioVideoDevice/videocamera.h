#ifndef VIDEOCAMERA_H
#define VIDEOCAMERA_H
#include "audiovideodevice.h"
class VideoCamera : public AudioVideoDevice
{
    Q_OBJECT
public:
    explicit VideoCamera(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif