#include "videocamera.h"
VideoCamera::VideoCamera(const QBluetoothDeviceInfo &info,QObject *parent):AudioVideoDevice(info,"battery",parent)
{
}