#include "screenmodel.h"
/*                                                                                               */
ScreenModel::ScreenModel():Model()
{
    startScan();
}
/*                                                                                               */
QHash<int, QByteArray> ScreenModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="Name";
    hash[1]="ModelName";
    hash[2]="Manufacturer";
    return hash;
}
/*                                                                                               */
QVariant ScreenModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        switch(Roles(role)){
        case Name:return m_screens.at(index.row())->name();
        case ModelName:return m_screens.at(index.row())->model();
        case Manufacturer:return m_screens.at(index.row())->manufacturer();
        }
    }
    return QVariant();
}
/*                                                                                               */
void ScreenModel::setCurrentIndex(const int &index)
{
}
/*                                                                                               */
void ScreenModel::startScan()
{
    m_watcher=new QFutureWatcher<QList<QScreen*> >(this);
    connect(m_watcher,SIGNAL(finished()),this,SLOT(scanFinished()));
    m_watcher->setFuture(QtConcurrent::run(this,&ScreenModel::scan));
}
/*                                                                                               */
extern QList<QScreen*> ScreenModel::scan()
{
    return qGuiApp->screens();
}
/*                                                                                               */
void ScreenModel::scanFinished()
{
    beginResetModel();
    m_screens=m_watcher->result();
    endResetModel();
    m_watcher->deleteLater();
}
/*                                                                                               */