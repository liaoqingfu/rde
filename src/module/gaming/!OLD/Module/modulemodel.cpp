#include "modulemodel.h"
/*                                                                                               */
ModuleModel::ModuleModel()
{
    m_allowDeleteData=false;
    m_currentIndex=0;
}
/*                                                                                               */
void ModuleModel::setCurrentIndex(const int &index)
{
    m_currentIndex=index;
    if(currentModule()->tableExists() && currentModule()->rowCount()>0)
        m_allowDeleteData=true;
    else
        m_allowDeleteData=false;

    emit allowDeleteDataChanged();
    emit currentRowCountChanged();
}
/*                                                                                               */
QHash<int, QByteArray> ModuleModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="IID";
    hash[1]="Description";
    hash[2]="IconName";
    hash[3]="Version";
    hash[4]="Imported";
    return hash;
}
/*                                                                                               */
QVariant ModuleModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        switch(Roles(role)){
        case IID:return Module::modules.at(index.row())->iid();
        case Description:return Module::modules.at(index.row())->description();
        case IconName:return Module::modules.at(index.row())->icon();
        case Version:return Module::modules.at(index.row())->version();
        case Imported:return true;
        }
    }
    return QVariant();
}
/*                                                                                               */
void ModuleModel::importModuleData(int index)
{
    m_currentIndex=index;
    connect(currentModule(),SIGNAL(importBusy()),this,SIGNAL(importBusy()));
    connect(currentModule(),SIGNAL(importReady()),this,SIGNAL(importReady()));
    currentModule()->importData();
}
/*                                                                                               */