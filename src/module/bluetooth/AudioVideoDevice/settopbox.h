#ifndef SETTOPBOX_H
#define SETTOPBOX_H
#include "audiovideodevice.h"
class SetTopBox : public AudioVideoDevice
{
    Q_OBJECT
public:
    explicit SetTopBox(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif