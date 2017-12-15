#include "videodisplayandloudspeaker.h"
VideoDisplayAndLoudspeaker::VideoDisplayAndLoudspeaker(const QBluetoothDeviceInfo &info,QObject *parent):AudioVideoDevice(info,"battery",parent)
{
}