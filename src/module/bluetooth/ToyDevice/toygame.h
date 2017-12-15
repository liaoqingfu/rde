#ifndef TOYGAME_H
#define TOYGAME_H
#include "toydevice.h"
class ToyGame : public ToyDevice
{
    Q_OBJECT
public:
    explicit ToyGame(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif