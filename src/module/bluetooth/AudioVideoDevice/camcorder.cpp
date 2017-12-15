#include "camcorder.h"
Camcorder::Camcorder(const QBluetoothDeviceInfo &info,QObject *parent):AudioVideoDevice(info,"camera-photo",parent)
{
}