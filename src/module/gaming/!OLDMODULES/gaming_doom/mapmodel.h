#ifndef MAPMODEL_H
#define MAPMODEL_H
/*                                                                                               */
#include "Model.h"
#include "map.h"
#include <QDir>
/*                                                                                               */
class MapModel : public Model
{
    Q_OBJECT
public:
    explicit MapModel();

private:
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return Map::maps.count();}
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
};
/*                                                                                               */
#endif