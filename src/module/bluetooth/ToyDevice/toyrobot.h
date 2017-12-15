#ifndef TOYROBOT_H
#define TOYROBOT_H
#include "toydevice.h"
class ToyRobot : public ToyDevice
{
    Q_OBJECT
public:
    explicit ToyRobot(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif