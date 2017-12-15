#include "fightermanager.h"
/*                                                                                               */
FighterManager::FighterManager()
{
    scan();
}
/*                                                                                               */
void FighterManager::scan()
{
    m_watcher=new QFutureWatcher<QStringList>(this);
    connect(m_watcher,SIGNAL(finished()),this,SLOT(scanFinished()));
    m_watcher->setFuture(QtConcurrent::run(this,&FighterManager::scanThread));
}
/*                                                                                               */
extern QStringList FighterManager::scanThread()
{
    QSettings settings;
    settings.beginGroup("Spright");
    m_path=settings.value("Path").toString();
    settings.endGroup();


    QDir dir(m_path,"*.zip");

    //QDir dir(m_path);
    //dir.setFilter(QDir::Dirs|QDir::Files|QDir::NoDotAndDotDot);
    //dir.setNameFilters(QStringList("*.zip"));
    foreach(QString info,dir.entryList()){

        //Fighter::fighters.append(new Fighter);


        qDebug() << "Found " << info;

        //QFileInfo i(m_path+"/"+info+"/"+info+".qml");
        //QFileInfo i(m_path+"/"+info+"/"+info+".txt");
        //if(i.isReadable())
            //l << info;
        //m_list << info;
        //qDebug() << "Sprite " << info << " found";
        //else
            //qDebug() << i.absoluteFilePath() << " is not readable";
    }

    QStringList l;
    return l;
}
/*                                                                                               */
void FighterManager::scanFinished()
{
    qDebug() << "Finished scanning fighters";
}
/*                                                                                               */
FighterManager *FighterManager::m_instance;
FighterManager *FighterManager::instance(){if(!m_instance)m_instance=new FighterManager();return m_instance;}