#ifndef GAMEPADPERIPHERAL_H
#define GAMEPADPERIPHERAL_H
#include "peripheraldevice.h"
#include <QBluetoothDeviceInfo>
class GamepadPeripheral : public PeripheralDevice
{
    Q_OBJECT
public:
    //explicit GamepadPeripheral(const QString name,QObject *parent = 0);
    explicit GamepadPeripheral(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif