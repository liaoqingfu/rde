#include "traymodel.h"
/*                                                                                               */
TrayModel::TrayModel()
{
    _instance=this;
}
/*                                                                                               */
QHash<int, QByteArray> TrayModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="IID";
    hash[1]="IconName";
    hash[2]="Context";
    return hash;
}
/*                                                                                               */
QVariant TrayModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        switch(Roles(role)){
        case IID:return _list.at(index.row())->iid();
        case IconName:return _list.at(index.row())->icon();
        case Context:return QVariant::fromValue<QQmlContext *>(_list.at(index.row())->context());
        }
    }
    return QVariant();
}
/*                                                                                               */
void TrayModel::addIcon(Module *module)
{
    //_instance->beginResetModel();
    _list.append(module);
    //_instance->endResetModel();
}
/*                                                                                               */
QVector<Module*> TrayModel::_list;
TrayModel *TrayModel::_instance;