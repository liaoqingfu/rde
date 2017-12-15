#include "caraudio.h"
CarAudio::CarAudio(const QBluetoothDeviceInfo &info,QObject *parent):AudioVideoDevice(info,"battery",parent)
{
}