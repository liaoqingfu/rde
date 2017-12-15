#ifndef BLUETOOTH_H
#define BLUETOOTH_H
/*                                                                                               */
#include "bluetooth_global.h"
#include "/development/rde/src/core/Module/ModuleInterface.h"
#include <QBluetoothLocalDevice>
/*                                                                                               */
class Bluetooth:public QObject,public ModuleInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Bluetooth" FILE "metadata.json")
    Q_INTERFACES(ModuleInterface)

private:
    bool initialize();
    Type type(){return Configure;}
    QBluetoothLocalDevice *m_localDevice;

private slots:
    void error(QBluetoothLocalDevice::Error error);
    void hostModeStateChanged(QBluetoothLocalDevice::HostMode mode);
    void deviceConnected(const QBluetoothAddress &address);
    void deviceDisconnected(const QBluetoothAddress &address);
    void pairingDisplayConfirmation(const QBluetoothAddress &address,const QString &string);
    void pairingDisplayPinCode(const QBluetoothAddress &address,const QString &string);
    void pairingFinished(const QBluetoothAddress &address,QBluetoothLocalDevice::Pairing pairing);
};
/*                                                                                               */
#endif
