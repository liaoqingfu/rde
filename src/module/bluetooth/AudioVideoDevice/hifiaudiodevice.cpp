#include "hifiaudiodevice.h"
HiFiAudioDevice::HiFiAudioDevice(const QBluetoothDeviceInfo &info,QObject *parent):AudioVideoDevice(info,"battery",parent)
{
}