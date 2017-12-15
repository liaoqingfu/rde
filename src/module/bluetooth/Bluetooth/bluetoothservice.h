#ifndef BLUETOOTHSERVICE_H
#define BLUETOOTHSERVICE_H
/*                                                                                               */
#include "service.h"
#include "bluetoothdevicemodel.h"
#include "bluetoothservicemodel.h"
#include "scanner.h"
#include <QBluetoothLocalDevice>
/*                                                                                               */
class BluetoothService : public Service
{
    Q_OBJECT
    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)

public:
    static BluetoothService *instance();
    bool configure(QSettings &settings);
    bool active()const;
    void setActive(const bool &active);

public slots:
    void scan();

private:
    BluetoothService();
    static BluetoothService *m_instance;
    QBluetoothLocalDevice *m_localDevice;

private slots:
    void error(QBluetoothLocalDevice::Error error);
    void hostModeStateChanged(QBluetoothLocalDevice::HostMode mode);
    void deviceConnected(const QBluetoothAddress &address);
    void deviceDisconnected(const QBluetoothAddress &address);
    void pairingDisplayConfirmation(const QBluetoothAddress &address,const QString &string);
    void pairingDisplayPinCode(const QBluetoothAddress &address,const QString &string);
    void pairingFinished(const QBluetoothAddress &address,QBluetoothLocalDevice::Pairing pairing);
signals:
    //void deviceHasConnected();
    //void deviceHasDisconnected();
    void activeChanged();
};
/*                                                                                               */
#endif