#include "server.h"

Server::Server(QObject *parent):QObject(parent)
{
    serv=new QBluetoothServer(QBluetoothServiceInfo::RfcommProtocol,this);
    connect(serv,SIGNAL(error(QBluetoothServer::Error)),this,SLOT(error(QBluetoothServer::Error)));
    connect(serv,SIGNAL(newConnection()),this,SLOT(newConnection()));
    //    QBluetoothUuid uuid=new QBluetoothUuid();
    //    if(serv->listen(uuid,"Fucker"))
    qDebug() << "Bluetooth Server is running";
}

void Server::newConnection()
{
    qDebug() << "New Bluetooth connection!!";
}

void Server::error(QBluetoothServer::Error error)
{
    switch(error){
    case QBluetoothServer::NoError:
        qDebug() << "Bluetooth Error: None";
        break;
    case QBluetoothServer::UnknownError:
        qDebug() << "Bluetooth Error: Unknown";
        break;
    case QBluetoothServer::PoweredOffError:
        qDebug() << "Bluetooth Error: Powered Off";
        break;
    case QBluetoothServer::InputOutputError:
        qDebug() << "Bluetooth Error: I/O";
        break;
    case QBluetoothServer::ServiceAlreadyRegisteredError:
        qDebug() << "Bluetooth Error: Service Already Registered";
        break;
    case QBluetoothServer::UnsupportedProtocolError:
        qDebug() << "Bluetooth Error: Unsupported Protocol";
        break;
    }
}