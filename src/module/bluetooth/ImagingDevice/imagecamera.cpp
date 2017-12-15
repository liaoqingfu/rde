#include "imagecamera.h"
ImageCamera::ImageCamera(const QBluetoothDeviceInfo &info,QObject *parent):ImagingDevice(info,"camera-photo",parent)
{
}