#include "scanner.h"
#include <QDebug>
/*                                                                                               */
Scanner::Scanner()
{
}
/*                                                                                               */
void Scanner::scan()
{
    m_agent=new QBluetoothDeviceDiscoveryAgent(this);
    m_agent->setInquiryType(QBluetoothDeviceDiscoveryAgent::LimitedInquiry);
    connect(m_agent,SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),this,SLOT(deviceDiscovered(QBluetoothDeviceInfo)));
    connect(m_agent,SIGNAL(error(QBluetoothDeviceDiscoveryAgent::Error)),this,SLOT(deviceDiscoveryError(QBluetoothDeviceDiscoveryAgent::Error)));
    connect(m_agent,SIGNAL(finished()),this,SLOT(deviceDiscoveryFinished()));
    m_agent->start();
}
/*                                                                                               */
void Scanner::deviceDiscovered(const QBluetoothDeviceInfo &info)
{
    devices.append(info);
    //qDebug() << "Discovered Bluetooth device " << info.name();
}
/*                                                                                               */
void Scanner::deviceDiscoveryError(QBluetoothDeviceDiscoveryAgent::Error error)
{
    switch(error){
    case QBluetoothDeviceDiscoveryAgent::NoError:
        qDebug() << "Bluetooth device discovery error: No error";
        break;
    case QBluetoothDeviceDiscoveryAgent::PoweredOffError:
        qDebug() << "Bluetooth device discovery error: Powered off ";
        break;
    case QBluetoothDeviceDiscoveryAgent::InputOutputError:
        qDebug() << "Bluetooth device discovery error: I/O";
        break;
    case QBluetoothDeviceDiscoveryAgent::InvalidBluetoothAdapterError:
        qDebug() << "Bluetooth device discovery error: Invalid adapter";
        break;
    case QBluetoothDeviceDiscoveryAgent::UnsupportedPlatformError:
        qDebug() << "Bluetooth device discovery error: Unsupported platform";
        break;
    case QBluetoothDeviceDiscoveryAgent::UnsupportedDiscoveryMethod:
        qDebug() << "Bluetooth device discovery error: unsupported method";
        break;
    case QBluetoothDeviceDiscoveryAgent::UnknownError:
        qDebug() << "Bluetooth device discovery error: unknown";
        break;
    }
}
/*                                                                                               */
void Scanner::deviceDiscoveryFinished()
{
    m_agent->deleteLater();
    qDebug() << "Finished scanning bluetooth devices";
    emit finished();
}
/*                                                                                               */
Scanner* Scanner::m_instance;
Scanner* Scanner::instance(){if(!m_instance)m_instance=new Scanner;return m_instance;}
QVector<QBluetoothDeviceInfo> Scanner::devices;