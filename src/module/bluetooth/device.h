#ifndef DEVICE_H
#define DEVICE_H
/*                                                                                               */
#include <QBluetoothDeviceInfo>
#include <QBluetoothServiceInfo>
#include <QBluetoothSocket>
#include <QDebug>
/*                                                                                               */
class Device : public QObject
{
    Q_OBJECT
public:
    explicit Device(const QBluetoothDeviceInfo &info,const QString iconName,QObject *parent = 0);

    QString name()const{return m_info.name();}
    QString iconName()const{return m_iconName;}
    QString address()const{return m_info.address().toString();}

    bool startConnection();
    bool startDisconnection();
    bool isConnected();
    void serviceDiscovered(const QBluetoothServiceInfo &info);

private:
    QBluetoothDeviceInfo m_info;
    QBluetoothSocket *socket;
    QString m_iconName;
    QVector<QBluetoothServiceInfo> services;

private slots:
    void socketConnected();
    void socketDisconnected();
    void socketError(QBluetoothSocket::SocketError error);
    void socketStateChanged(QBluetoothSocket::SocketState state);
};
/*                                                                                               */
#endif