#include "imagescanner.h"
ImageScanner::ImageScanner(const QBluetoothDeviceInfo &info,QObject *parent):ImagingDevice(info,"scanner",parent)
{
}