#include "microphone.h"
Microphone::Microphone(const QBluetoothDeviceInfo &info,QObject *parent):AudioVideoDevice(info,"audio-input-microphone",parent)
{
}