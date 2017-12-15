#include "videoconferencing.h"
VideoConferencing::VideoConferencing(const QBluetoothDeviceInfo &info,QObject *parent):AudioVideoDevice(info,"battery",parent)
{
}