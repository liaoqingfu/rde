#include "enginemodel.h"
/*                                                                                               */
EngineModel::EngineModel():Model()
{
    m_engines=QTextToSpeech::availableEngines();
}
/*                                                                                               */
QHash<int, QByteArray> EngineModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="Name";
    return hash;
}
/*                                                                                               */
QVariant EngineModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid())
        return m_engines.at(index.row());
    return QVariant();
}
/*                                                                                               */
void EngineModel::setCurrentIndex(const int &index)
{
}
/*                                                                                               */