#ifndef DESKTOPCOMPUTER_H
#define DESKTOPCOMPUTER_H
#include "computerdevice.h"
class DesktopComputer : public ComputerDevice
{
    Q_OBJECT
public:
    explicit DesktopComputer(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif