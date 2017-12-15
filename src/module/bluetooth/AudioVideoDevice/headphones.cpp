#include "headphones.h"
Headphones::Headphones(const QBluetoothDeviceInfo &info,QObject *parent):AudioVideoDevice(info,"audio-headphones",parent)
{
}