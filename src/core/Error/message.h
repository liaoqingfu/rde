#ifndef MESSAGE_H
#define MESSAGE_H
/*                                                                                               */
#include <QString>
#include <QVector>
/*                                                                                               */
class Message
{
public:
    Message(QString iconName,QString file,int line,QString content);
    QString content()const{return m_content;}
    QString file()const{return m_file;}
    QString iconName()const{return m_iconName;}
    int line()const{return m_line;}

    static QVector<Message*> messages;

private:
    QString m_file;
    QString m_content;
    QString m_iconName;
    int m_line;
};
/*                                                                                               */
#endif