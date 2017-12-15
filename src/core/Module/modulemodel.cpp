#include "modulemodel.h"
/*                                                                                               */
ModuleModel::ModuleModel():Model()
{
    m_currentIndex=0;
}
/*                                                                                               */
QHash<int, QByteArray> ModuleModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="IID";
    hash[1]="IconName";
    hash[2]="Loaded";
    hash[3]="Type";
    return hash;
}
/*                                                                                               */
QVariant ModuleModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        switch(Roles(role)){
        case IID:return Module::vector.at(index.row())->iid();
        case IconName:return Module::vector.at(index.row())->icon();
        case Loaded:return Module::vector.at(index.row())->isLoaded();
        case Type:return "yes";//{
            //switch(Module::vector.at(index.row()))
        //}
            //return Module::vector.at(index.row())->isLoaded();
        }
    }
    return QVariant();
}
/*                                                                                               */
void ModuleModel::setCurrentIndex(const int &index)
{
    m_currentIndex=index;

    emit descriptionChanged();
    emit versionChanged();
}
/*                                                                                               */
void ModuleModel::toggle(const int &index)
{
    if(Module::vector.at(index)->isLoaded())
        Module::vector.at(index)->unload();
    else
        Module::vector.at(index)->load();
}
/*                                                                                               */