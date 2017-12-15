#include "moduleservice.h"
/*                                                                                               */
ModuleService::ModuleService():Service("Module")
{
    qmlRegisterType<ModuleDockItem>("org.rde.core",1,0,"ModuleDockItem");
    qmlRegisterType<ModuleModel>("org.rde.core",1,0,"ModuleModel");

    //    qmlRegisterType<ModuleModel>("org.rde.core",1,0,"CoreModuleModel");

    m_path=QStandardPaths::standardLocations(QStandardPaths::AppLocalDataLocation).at(0)+"/module";
    QDir dir(m_path);
    if(dir.isReadable()){
        m_watcher=new QFileSystemWatcher(this);
        connect(m_watcher,SIGNAL(directoryChanged(QString)),this,SLOT(directoryChanged(QString)));
        m_watcher->addPath(m_path);
    }
    else{
        qDebug() << "Module path:" << m_path << " does not exist!";
        //qWarning() << path << " does not exist!!!";
    }
}
/*                                                                                               */
bool ModuleService::configure(QSettings &settings)
{
    scanModules();
    foreach(QString iid,settings.value("Loaded").toStringList()){
        if(!iid.isEmpty()){
            if(m_map.contains(iid)){
                if(!m_map.value(iid)->isLoaded()){
                    if(m_map.value(iid)->load()){
                        //qDebug() << "Loaded module " << iid;
                    }
                }
            }
        }
    }
    //        if(!iid.isEmpty() && m_map.contains(iid)){
    //                else
    //                    qDebug() << iid << " is already loaded!";
    //        }
    //        else
    //            qDebug() <<"Module " << iid << " does not exist";
    //}
    return true;
}
/*                                                                                               */
void ModuleService::directoryChanged(const QString &dir)
{
}
/*                                                                                               */
void ModuleService::scanModules()
{
    QDir dir(m_path,"*.so");
    if(dir.mkpath(m_path)){
        foreach(QFileInfo info,dir.entryInfoList()){
            Module::vector.append(new Module(info.absoluteFilePath(),this));
            m_map.insert(info.baseName().mid(3),Module::vector.last());
        }
    }
}
/*                                                                                               */
ModuleService* ModuleService::m_instance;
ModuleService* ModuleService::instance(){if(!m_instance)m_instance=new ModuleService;return m_instance;}