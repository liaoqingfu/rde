#ifndef BLUETOOTHSERVICEMODEL_H
#define BLUETOOTHSERVICEMODEL_H
/*                                                                                               */
#include "Model.h"
#include <QBluetoothServiceDiscoveryAgent>
/*                                                                                               */
class BluetoothServiceModel : public Model
{
    Q_OBJECT
public:
    explicit BluetoothServiceModel();

private:
    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return 1/*m_devices.count()*/;}

    QBluetoothServiceDiscoveryAgent *m_agent;

private slots:
    void serviceDiscovered(const QBluetoothServiceInfo &info);
    void finished();
    void error(QBluetoothServiceDiscoveryAgent::Error error);
};
/*                                                                                               */
#endif