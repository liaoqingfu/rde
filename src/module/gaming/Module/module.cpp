#include "module.h"
/*                                                                                               */
Module::Module(const QString &program):QObject()
{
    m_program=new Program(program,this);
    modules.append(this);
    iidMap.insert(program,this);
}
/*                                                                                               */
void Module::startImporting()
{
    m_watcher=new QFutureWatcher<QStringList>(this);
    connect(m_watcher,SIGNAL(finished()),this,SLOT(importFinished()));
    m_watcher->setFuture(QtConcurrent::run(this,&Module::importThread));
}
/*                                                                                               */
extern QStringList Module::importThread(){return importData();}
/*                                                                                               */
void Module::importFinished()
{
    QStringList result=m_watcher->result();
    m_watcher->deleteLater();
    if(result.size()>0){
        QSqlDatabase db=QSqlDatabase::database("Games");
        if(db.transaction()){
            QSqlQuery q(db);
            foreach(const QString &line,result){
                if(q.prepare("INSERT INTO games VALUES"+line)){
                    if(q.exec()){

                    }
                }
                //                else{
                //                    qDebug() << "Failed prep " << line;
                //                    qDebug() << q.lastError().text();
                //                }
            }
            if(db.commit()){
                //index
                qDebug() << "Commit OK!!";
            }
            //                    if(q.prepare("CREATE INDEX '"+m_modules.at(m_index)->iid()+"Index' ON "+m_modules.at(m_index)->iid()+" ('title')")){
            //                        if(q.exec()){
            //                        }
            //                    }
            //                }
        }
    }
}
/*                                                                                               */
QVector<Module*> Module::modules;
QMap<QString,Module*> Module::iidMap;
Module *Module::byIID(const QString &IID){return iidMap.value(IID);}



//            if(db.transaction()){
//                QSqlQuery q(db);
//                foreach(const QString &line,result){
//                    if(q.prepare("INSERT INTO "+m_modules.at(m_index)->iid()+" VALUES"+line)){
//                        if(q.exec()){
//                            //qDebug() << "Game Inserted:" << q.executedQuery();
//                        }
//                        else{
//                            qWarning() << "Failed to insert:" << q.executedQuery();
//                            qWarning() << q.lastError();
//                        }
//                    }
//                    else{
//                        qWarning() << "Failed to prepare:" << q.executedQuery();
//                        qWarning() << q.lastError();
//                    }
//                }

//                else
//                    qWarning() << "Failed to commit:" << db.lastError().text();
//            }
//            else
//                qWarning() << "No transaction possible?" << db.lastError().text();
//        }
//        else
//            qWarning() << "No results returned";

//        m_index++;
//        if(m_index<m_modules.count()){
//            m_importWatcher->setFuture(QtConcurrent::run(this,&Importer::import));
//        }
//        else
//            deleteLater();