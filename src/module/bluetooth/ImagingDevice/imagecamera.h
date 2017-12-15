#ifndef IMAGECAMERA_H
#define IMAGECAMERA_H
#include "imagingdevice.h"
class ImageCamera : public ImagingDevice
{
    Q_OBJECT
public:
    explicit ImageCamera(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif