#ifndef NETWORKINTERFACEMODEL_H
#define NETWORKINTERFACEMODEL_H
/*                                                                                               */
#include "Model.h"
#include <QNetworkInterface>
/*                                                                                               */
class NetworkInterfaceModel : public Model
{
    Q_OBJECT
public:
    explicit NetworkInterfaceModel();

private:
    enum Roles{Name,IsUp,IsRunning,MacAddress};
    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return m_list.count();}
    QVector<QNetworkInterface> m_list;
};
/*                                                                                               */
#endif