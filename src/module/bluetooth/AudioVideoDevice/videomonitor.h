#ifndef VIDEOMONITOR_H
#define VIDEOMONITOR_H
#include "audiovideodevice.h"
class VideoMonitor : public AudioVideoDevice
{
    Q_OBJECT
public:
    explicit VideoMonitor(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif