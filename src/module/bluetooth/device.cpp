#include "device.h"
/*                                                                                               */
Device::Device(const QBluetoothDeviceInfo &info,const QString iconName,QObject *parent):QObject(parent)
{
    m_info=info;
    m_iconName=iconName;

    //info.conn

    //qDebug() << "info.address().toString();

    //    switch(info.serviceClasses()){
    //    case QBluetoothDeviceInfo::NoService:
    //        qDebug() << "Bluetooth: No Services discovered";
    //        break;
    //    case QBluetoothDeviceInfo::PositioningService:
    //        qDebug() << "Bluetooth: Positioning";
    //        break;
    //    case QBluetoothDeviceInfo::NetworkingService:
    //        qDebug() << "Bluetooth: Networking";
    //        break;
    //    case QBluetoothDeviceInfo::RenderingService:
    //        qDebug() << "Bluetooth: Rendering";
    //        break;
    //    case QBluetoothDeviceInfo::CapturingService:
    //        qDebug() << "Bluetooth: Capturing";
    //        break;
    //    case QBluetoothDeviceInfo::ObjectTransferService:
    //        qDebug() << "Bluetooth: Object transfer";
    //        break;
    //    case QBluetoothDeviceInfo::AudioService:
    //        qDebug() << "Bluetooth: Audio Service";
    //        break;
    //    case QBluetoothDeviceInfo::TelephonyService:
    //        qDebug() << "Bluetooth: Telephony Service";
    //        break;
    //    case QBluetoothDeviceInfo::InformationService:
    //        qDebug() << "Bluetooth: Information Service;";
    //        break;
    //    case QBluetoothDeviceInfo::AllServices:
    //        qDebug() << "Bluetooth: All services";
    //        break;
    //    }
}
/*                                                                                               */
bool Device::startConnection()
{
    qDebug() << "Starting connection";


    QBluetoothServiceInfo info=services.at(0);

    qDebug() << "Device: " << info.device().name();
    qDebug() << "Service Name:" << info.serviceName();
    qDebug() << "Service Provider:" << info.serviceProvider();
    qDebug() << "Info Is complete?" << info.isComplete();
    qDebug() << "Info Is registered?" << info.isRegistered();
    qDebug() << "Info is valid?" << info.isValid();

    //qDebug() << "Services ::" << services;
    //QBluetoothServiceInfo serviceInfo;
    //serviceInfo.setDevice(deviceInfo);


    //qDebug() << serviceInfo.ServiceName





    socket=new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol,this);
    //socket=new QBluetoothSocket(QBluetoothServiceInfo::L2capProtocol,this);
    connect(socket,SIGNAL(connected()),this,SLOT(socketConnected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(socketDisconnected()));
    connect(socket,SIGNAL(error(QBluetoothSocket::SocketError)),this,SLOT(socketError(QBluetoothSocket::SocketError)));
    connect(socket,SIGNAL(stateChanged(QBluetoothSocket::SocketState)),this,SLOT(socketStateChanged(QBluetoothSocket::SocketState)));



    //socket->connectToService(serviceInfo,deviceInfo.deviceUuid(),QIODevice::ReadOnly);

    //socket->connectToService(services.at(0),services.at(0).serviceUuid(),QIODevice::ReadOnly);

    //socket->connectToService(deviceInfo.address(),services.at(0).serviceUuid());



    //socket->connectToService(deviceInfo.address(),1,QIODevice::ReadOnly);
    //socket->connectToService(deviceInfo.address(),deviceInfo.deviceUuid(),QIODevice::ReadOnly);
    //qDebug() << "Attr for " << deviceInfo.name() << ": " << serviceInfo.attributes();
    //qDebug() << "Registered?" << serviceInfo.isRegistered();
    //qDebug() << "Valid?" << serviceInfo.isValid();
    //qDebug() << "Complete?" << serviceInfo.isComplete();
    //    if(serviceInfo.isComplete()){
    //    //if(serviceInfo.isValid()){
    //        qDebug() << "Service info appears to be complete";
    //    }
    //    else
    //        qDebug() << "Service info not valid?...";
    return true;
}
/*                                                                                               */
bool Device::startDisconnection()
{
    qDebug() << "Disconnecting device " << m_info.name();
    return true;
}
/*                                                                                               */
void Device::socketConnected()
{
    qDebug() << "BT: Socket connected!";
}
/*                                                                                               */
void Device::socketDisconnected()
{
    qDebug() << "BT:Socket disconnected!";
}
/*                                                                                               */
void Device::socketStateChanged(QBluetoothSocket::SocketState state)
{
    switch(state){
    case QBluetoothSocket::UnconnectedState:
        qDebug() << "Socket is not connected.";
        break;
    case QBluetoothSocket::ServiceLookupState:
        qDebug() << "Socket is querying connection parameters.";
        break;
    case QBluetoothSocket::ConnectingState:
        qDebug() << "Socket is attempting to connect to a device.";
        break;
    case QBluetoothSocket::ConnectedState:
        qDebug() << "Socket is connected to a device.";
        break;
    case QBluetoothSocket::BoundState:
        qDebug() << "Socket is bound to a local address and port.";
        break;
    case QBluetoothSocket::ClosingState:
        qDebug() << "Socket is connected and will be closed once all pending data is written to the socket.";
        break;
    case QBluetoothSocket::ListeningState:
        qDebug() << "Socket is listening for incoming connections.";
        break;
    }
}
/*                                                                                               */
void Device::socketError(QBluetoothSocket::SocketError error)
{
    switch(error){
    case QBluetoothSocket::UnknownSocketError:
        qDebug() << "Bluetooth Error: Unknown Socket";
        qDebug() << "Error:" << socket->errorString();
        break;
    case QBluetoothSocket::NoSocketError:
        qDebug() << "Bluetooth Error: No Socket";
        qDebug() << "Error:" << socket->errorString();
        break;
    case QBluetoothSocket::HostNotFoundError:
        qDebug() << "Bluetooth Error: Host Not Found";
        qDebug() << "Error:" << socket->errorString();
        break;
    case QBluetoothSocket::ServiceNotFoundError:
        qDebug() << "Bluetooth Error: Service Not Found";
        qDebug() << "Error:" << socket->errorString();
        break;
    case QBluetoothSocket::NetworkError:
        qDebug() << "Bluetooth Error: Network Error";
        qDebug() << "Error:" << socket->errorString();
        break;
    case QBluetoothSocket::UnsupportedProtocolError:
        qDebug() << "Bluetooth Error: Unsupported Protocol";
        qDebug() << "Error:" << socket->errorString();
        break;
    case QBluetoothSocket::OperationError:
        qDebug() << "Bluetooth Error: Operation Error";
        qDebug() << "Error:" << socket->errorString();
        break;
    }
}
/*                                                                                               */
void Device::serviceDiscovered(const QBluetoothServiceInfo &info)
{
    qDebug() << "Device: Service discovered:" << info.serviceName();
    services.append(info);
}
/*                                                                                               */