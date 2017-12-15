#include "character.h"
/*                                                                                               */
Character::Character(QString id,QObject *parent):QObject(parent)
{
    m_id=id;

    m_watcher=new QFutureWatcher<QString>(this);
    connect(m_watcher,SIGNAL(finished()),this,SLOT(ready()));
    m_watcher->setFuture(QtConcurrent::run(this,&Character::readThread));
}
/*                                                                                               */
extern QString Character::readThread()
{
    QFile f("/games/paintown/data/players/"+m_id+"/"+m_id+".txt");
    if(f.open(QIODevice::ReadOnly))
        return QString(f.readAll()).trimmed().remove("\n");
}
/*                                                                                               */
void Character::ready()
{
    m_txt=m_watcher->result();

    qDebug() << m_txt;




//    int pos=0;

//    while(pos<m_txt.size()){

//        pos++;
//        qDebug() << m_txt.at(pos);
//    }


    //qDebug() << m_txt;
}
/*                                                                                               */
QVector<Character*> Character::m_characters;