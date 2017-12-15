#include "videomonitor.h"
VideoMonitor::VideoMonitor(const QBluetoothDeviceInfo &info,QObject *parent):AudioVideoDevice(info,"video-television",parent)
{
}