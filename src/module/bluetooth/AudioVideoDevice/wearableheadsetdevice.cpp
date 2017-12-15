#include "wearableheadsetdevice.h"
WearableHeadsetDevice::WearableHeadsetDevice(const QBluetoothDeviceInfo &info,QObject *parent):AudioVideoDevice(info,"audio-headphones",parent)
{
}