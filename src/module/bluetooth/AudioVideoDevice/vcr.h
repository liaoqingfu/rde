#ifndef VCR_H
#define VCR_H
#include "audiovideodevice.h"
class VCR : public AudioVideoDevice
{
    Q_OBJECT
public:
    explicit VCR(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif