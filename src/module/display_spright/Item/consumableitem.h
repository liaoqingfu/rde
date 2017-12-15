#ifndef CONSUMABLEITEM_H
#define CONSUMABLEITEM_H
/*                                                                                               */
#include <QObject>
/*                                                                                               */
class ConsumableItem:public QObject
{
    Q_OBJECT
public:
    ConsumableItem();
    //virtual ~Item(){}
    QString name()const{return m_name;}
    QString description()const{return m_description;}

protected:
    QString m_name;
    QString m_description;
};
/*                                                                                               */
#endif