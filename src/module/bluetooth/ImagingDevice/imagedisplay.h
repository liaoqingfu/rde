#ifndef IMAGEDISPLAY_H
#define IMAGEDISPLAY_H
#include "imagingdevice.h"
class ImageDisplay : public ImagingDevice
{
    Q_OBJECT
public:
    explicit ImageDisplay(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif