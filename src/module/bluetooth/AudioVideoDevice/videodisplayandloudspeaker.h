#ifndef VIDEODISPLAYANDLOUDSPEAKER_H
#define VIDEODISPLAYANDLOUDSPEAKER_H
#include "audiovideodevice.h"
class VideoDisplayAndLoudspeaker : public AudioVideoDevice
{
    Q_OBJECT
public:
    explicit VideoDisplayAndLoudspeaker(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif