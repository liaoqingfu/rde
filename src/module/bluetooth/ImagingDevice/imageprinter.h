#ifndef IMAGEPRINTER_H
#define IMAGEPRINTER_H
#include "imagingdevice.h"
class ImagePrinter : public ImagingDevice
{
    Q_OBJECT
public:
    explicit ImagePrinter(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif