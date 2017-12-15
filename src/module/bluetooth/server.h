#ifndef SERVER_H
#define SERVER_H
#include <QBluetoothServer>
#include <QBluetoothUuid>
#include <QDebug>
class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);

private:
    QBluetoothServer *serv;

private slots:
    void error(QBluetoothServer::Error error);
    void newConnection();
};
#endif