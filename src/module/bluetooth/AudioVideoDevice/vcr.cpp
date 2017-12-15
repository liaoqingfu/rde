#include "vcr.h"
VCR::VCR(const QBluetoothDeviceInfo &info,QObject *parent):AudioVideoDevice(info,"battery",parent)
{
}