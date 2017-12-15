#ifndef NETWORKCONFIGURATIONMODEL_H
#define NETWORKCONFIGURATIONMODEL_H
/*                                                                                               */
#include "Model.h"
#include <QNetworkConfigurationManager>
/*                                                                                               */
class NetworkConfigurationModel:public Model
{
    Q_OBJECT
public:
    explicit NetworkConfigurationModel();

private:
    enum Roles{Name,Bearer,IsActive};
    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return m_list.count();}
    QVector<QNetworkConfiguration> m_list;

public slots:
    void select(const int &index);
    void hold(const int &index);
};
/*                                                                                               */
#endif