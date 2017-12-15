#ifndef MODMODEL_H
#define MODMODEL_H
/*                                                                                               */
#include "Model.h"
#include "mod.h"
#include <QDir>
/*                                                                                               */
class ModModel : public Model
{
    Q_OBJECT
public:
    explicit ModModel();

private:
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return Mod::mods.count();}
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
};
/*                                                                                               */
#endif