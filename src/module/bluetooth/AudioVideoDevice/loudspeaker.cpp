#include "loudspeaker.h"
Loudspeaker::Loudspeaker(const QBluetoothDeviceInfo &info,QObject *parent):AudioVideoDevice(info,"battery",parent)
{
}