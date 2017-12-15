#ifndef IMAGESCANNER_H
#define IMAGESCANNER_H
#include "imagingdevice.h"
class ImageScanner : public ImagingDevice
{
    Q_OBJECT
public:
    explicit ImageScanner(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif