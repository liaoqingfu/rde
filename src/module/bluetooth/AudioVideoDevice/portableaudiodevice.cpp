#include "portableaudiodevice.h"
PortableAudioDevice::PortableAudioDevice(const QBluetoothDeviceInfo &info,QObject *parent):AudioVideoDevice(info,"multimedia-player",parent)
{
}