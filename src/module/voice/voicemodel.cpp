#include "voicemodel.h"
/*                                                                                               */
VoiceModel::VoiceModel():Model()
{
}
/*                                                                                               */
QHash<int, QByteArray> VoiceModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="Voice";
    hash[1]="Name";
    hash[2]="Gender";
    hash[3]="Age";
    return hash;
}
/*                                                                                               */
QVariant VoiceModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        switch(Roles(role)){
        //case Voice:return voices.at(index.row());
        case Name:return voices.at(index.row()).name();
        case Gender:return voices.at(index.row()).gender();
        case Age:return voices.at(index.row()).age();
        }
    }
    return QVariant();
}
/*                                                                                               */
void VoiceModel::setCurrentIndex(const int &index)
{
    m_currentIndex=index;
}
/*                                                                                               */
QVector<QVoice> VoiceModel::voices;