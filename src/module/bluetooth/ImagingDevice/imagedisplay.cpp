#include "imagedisplay.h"
ImageDisplay::ImageDisplay(const QBluetoothDeviceInfo &info,QObject *parent):ImagingDevice(info,"video-display",parent)
{
}