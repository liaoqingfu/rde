#include "displayservice.h"
/*                                                                                               */
DisplayService::DisplayService():Service("Display")
{

    //DisplayInterface::surface=Desktop::instance()->contentItem();
    m_path=QStandardPaths::standardLocations(QStandardPaths::AppLocalDataLocation).at(0)+"/module/display";

    Service::engine->rootContext()->setContextProperty("Display",this);

    QSettings settings;
    settings.beginGroup("Display");
    QString module=settings.value("Module").toString();
    settings.endGroup();

    //DisplayPlugin *currentPlugin=new DisplayPlugin(m_path+"/libdisplay_"+module+".so");
    //currentPlugin->activate();




    QDir dir(m_path);
    if(dir.isReadable()){
        m_watcher=new QFileSystemWatcher(this);
        connect(m_watcher,SIGNAL(directoryChanged(QString)),this,SLOT(directoryChanged(QString)));
        m_watcher->addPath(m_path);
        directoryChanged(m_path);
    }
    else
        qDebug() << "Module path:" << m_path << " does not exist!";
}
/*                                                                                               */
void DisplayService::directoryChanged(QString path)
{
//    QDir dir(path);
//    if(dir.isReadable()){
//        foreach(QFileInfo info,dir.entryInfoList(QStringList("*.so"),QDir::Files,QDir::Name))
//            new DisplayPlugin(info.absoluteFilePath());
//    }
}
/*                                                                                               */
void DisplayService::suspend()
{
    //if(DisplayPlugin::activePlugin)
        //DisplayPlugin::activePlugin->interface()->suspend();
}
/*                                                                                               */
void DisplayService::resume()
{
    //if(DisplayPlugin::activePlugin)
        //DisplayPlugin::activePlugin->interface()->resume();
}
/*                                                                                               */
DisplayService* DisplayService::m_instance;
DisplayService* DisplayService::instance(){if(!m_instance)m_instance=new DisplayService;return m_instance;}