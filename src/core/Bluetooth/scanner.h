#ifndef SCANNER_H
#define SCANNER_H
/*                                                                                               */
//#include <QBluetoothDeviceDiscoveryAgent>
#include <QVector>
/*                                                                                               */
class Scanner : public QObject
{
    Q_OBJECT
public:
    static Scanner *instance();
    void scan();
    static QVector<QBluetoothDeviceInfo> devices;

private:
    static Scanner *m_instance;
    Scanner();
    QBluetoothDeviceDiscoveryAgent *m_agent;

private slots:
    void deviceDiscovered(const QBluetoothDeviceInfo &info);
    void deviceDiscoveryFinished();
    void deviceDiscoveryError(QBluetoothDeviceDiscoveryAgent::Error error);

signals:
    void finished();
};
/*                                                                                               */
#endif