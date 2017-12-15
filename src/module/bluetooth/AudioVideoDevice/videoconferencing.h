#ifndef VIDEOCONFERENCING_H
#define VIDEOCONFERENCING_H
#include "audiovideodevice.h"
class VideoConferencing : public AudioVideoDevice
{
    Q_OBJECT
public:
    explicit VideoConferencing(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif