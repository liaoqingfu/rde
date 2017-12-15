#include "messagemodel.h"
/*                                                                                               */
MessageModel::MessageModel()
{
    m_currentIndex=0;
    m_file="";
}
/*                                                                                               */
QHash<int, QByteArray> MessageModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="Content";
    hash[1]="IconName";
    return hash;
}
/*                                                                                               */
QVariant MessageModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        switch(Roles(role)){
        case Content:return Message::messages.at(index.row())->content();
        case IconName:return Message::messages.at(index.row())->iconName();
        }
    }
    return QVariant();
}
/*                                                                                               */
void MessageModel::addMessage(Message *msg)
{
    QModelIndex index;
    beginInsertRows(index,Message::messages.size(),Message::messages.size());
    //m_messages.append(message);

    endInsertRows();
}
/*                                                                                               */
void MessageModel::setCurrentIndex(const int &index)
{
    m_currentIndex=index;
    if(!Message::messages.isEmpty()){
        m_file=Message::messages.at(index)->file();
        emit fileChanged();
    }
}
/*                                                                                               */