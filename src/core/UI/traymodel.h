#ifndef TRAYMODEL_H
/*                                                                                               */
#define TRAYMODEL_H
/*                                                                                               */
#include "Model.h"
#include "Module/module.h"
/*                                                                                               */
class Module;
/*                                                                                               */
class TrayModel : public Model
{
    Q_OBJECT
public:
    explicit TrayModel();
    static void addIcon(Module *module);

private:
    enum Roles{IID,IconName,Context};
    QHash<int, QByteArray> roleNames() const;
    int rowCount(const QModelIndex &parent) const{Q_UNUSED(parent);return _list.size();}
    QVariant data(const QModelIndex &index,int role)const;
    static QVector<Module*> _list;
    static TrayModel *_instance;
};
/*                                                                                               */
#endif