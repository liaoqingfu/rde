#ifndef WEARABLECOMPUTER_H
#define WEARABLECOMPUTER_H
#include "computerdevice.h"
class WearableComputer : public ComputerDevice
{
    Q_OBJECT
public:
    explicit WearableComputer(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif