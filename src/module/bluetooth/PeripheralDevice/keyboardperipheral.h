#ifndef KEYBOARDPERIPHERAL_H
#define KEYBOARDPERIPHERAL_H
#include "peripheraldevice.h"
class KeyboardPeripheral : public PeripheralDevice
{
    Q_OBJECT
public:
    explicit KeyboardPeripheral(const QBluetoothDeviceInfo &info,QObject *parent = 0);
};
#endif