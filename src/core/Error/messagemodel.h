#ifndef MESSAGEMODEL_H
/*                                                                                               */
#define MESSAGEMODEL_H
/*                                                                                               */
#include "Model.h"
#include <QQmlError>
#include <QVector>
#include "message.h"
/*                                                                                               */
class MessageModel : public Model
{
    Q_OBJECT
    Q_PROPERTY(QString file READ file NOTIFY fileChanged)

public:
    explicit MessageModel();
    void addMessage(Message *msg);
    QString file()const{return m_file;}

private:
    enum Roles{Content,IconName};
    QHash<int, QByteArray> roleNames() const;
    int rowCount(const QModelIndex &parent) const{Q_UNUSED(parent);return Message::messages.size();}
    QVariant data(const QModelIndex &index,int role)const;
    void setCurrentIndex(const int &index);
    QString m_file;

signals:
    void fileChanged();
};
/*                                                                                               */
#endif