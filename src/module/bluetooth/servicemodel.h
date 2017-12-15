#ifndef SERVICEMODEL_H
/*                                                                                               */
#define SERVICEMODEL_H
/*                                                                                               */
#include "Model.h"
#include <QBluetoothServiceDiscoveryAgent>
/*                                                                                               */
class ServiceModel : public Model
{
    Q_OBJECT
public:
    explicit ServiceModel(QObject *parent = 0);

private:
    enum Roles{Name=257,Description=258,UUID=259};
    QList<QBluetoothServiceInfo> list;
    QBluetoothServiceDiscoveryAgent *agent;
    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return list.count();}

private:
    void scan();

private slots:
    void error(QBluetoothServiceDiscoveryAgent::Error error);
    void serviceDiscovered(const QBluetoothServiceInfo &info);
    void scanFinished();
    void scanCanceled();
};
/*                                                                                               */
#endif