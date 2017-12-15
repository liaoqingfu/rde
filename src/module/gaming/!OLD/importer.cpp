#include "importer.h"
/*                                                                                               */
Importer::Importer(QVector<Module*> modules,QObject *parent):QObject(parent)
{
    m_index=0;
    if(!modules.isEmpty()){
        m_modules=modules;
        m_importWatcher=new QFutureWatcher<QStringList>(this);
        connect(m_importWatcher,SIGNAL(finished()),this,SLOT(finished()));
        m_importWatcher->setFuture(QtConcurrent::run(this,&Importer::import));
    }
}
/*                                                                                               */
extern QStringList Importer::import()
{
    QSqlDatabase db=QSqlDatabase::database("Games");
    if(db.open()){
        QSqlQuery q(db);
        if(q.prepare("CREATE TABLE IF NOT EXISTS "+m_modules.at(m_index)->iid()+TableString)){
            if(q.exec())
                return m_modules.at(m_index)->interface()->getData();
        }
    }
    else
        qWarning() << "Db not open!!" << db.lastError().text();
}
/*                                                                                               */
void Importer::finished()
{
    QStringList result=m_importWatcher->result();
    if(result.size()>0){
        QSqlDatabase db=QSqlDatabase::database("Games");
        if(db.transaction()){
            QSqlQuery q(db);
            foreach(const QString &line,result){
                if(q.prepare("INSERT INTO "+m_modules.at(m_index)->iid()+" VALUES"+line)){
                    if(q.exec()){
                        //qDebug() << "Game Inserted:" << q.executedQuery();
                    }
                    else{
                        qWarning() << "Failed to insert:" << q.executedQuery();
                        qWarning() << q.lastError();
                    }
                }
                else{
                    qWarning() << "Failed to prepare:" << q.executedQuery();
                    qWarning() << q.lastError();
                }
            }
            if(db.commit()){
                if(q.prepare("CREATE INDEX '"+m_modules.at(m_index)->iid()+"Index' ON "+m_modules.at(m_index)->iid()+" ('title')")){
                    if(q.exec()){
                    }
                }
            }
            else
                qWarning() << "Failed to commit:" << db.lastError().text();
        }
        else
            qWarning() << "No transaction possible?" << db.lastError().text();
    }
    else
        qWarning() << "No results returned";

    m_index++;
    if(m_index<m_modules.count()){
        m_importWatcher->setFuture(QtConcurrent::run(this,&Importer::import));
    }
    else
        deleteLater();
}
/*                                                                                               */