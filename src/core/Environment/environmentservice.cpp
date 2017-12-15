#include "environmentservice.h"
/*                                                                                               */
EnvironmentService::EnvironmentService():Service("Environment")
{
    Service::engine->rootContext()->setContextProperty("Environment",this);



    //if(exists(QStandardPaths::standardLocations(QStandardPaths::FontsLocation)))
    //qDebug() << QStandardPaths::standardLocations(QStandardPaths::FontsLocation) << " exists";

    //    qDebug() << "Fonts: " << QStandardPaths::standardLocations(QStandardPaths::FontsLocation);
    //    qDebug() << "Applications: " << QStandardPaths::standardLocations(QStandardPaths::ApplicationsLocation);
    //    qDebug() << "Temp: " << QStandardPaths::standardLocations(QStandardPaths::TempLocation);

    //    qDebug() << "Data: " << QStandardPaths::standardLocations(QStandardPaths::DataLocation);
    //    qDebug() << "Cache: " << QStandardPaths::standardLocations(QStandardPaths::CacheLocation);
    //    qDebug() << "GenericCache: " << QStandardPaths::standardLocations(QStandardPaths::GenericCacheLocation);
    //    qDebug() << "GenericData: " << QStandardPaths::standardLocations(QStandardPaths::GenericDataLocation);
    //    qDebug() << "Runtime: " << QStandardPaths::standardLocations(QStandardPaths::RuntimeLocation);




    //    qDebug() << "Config: " << QStandardPaths::standardLocations(QStandardPaths::ConfigLocation);
    //    qDebug() << "GenericConfig: " << QStandardPaths::standardLocations(QStandardPaths::GenericConfigLocation);


    //    qDebug() << "AppData: " << QStandardPaths::standardLocations(QStandardPaths::AppDataLocation);
    //    qDebug() << "AppLocalData: " << QStandardPaths::standardLocations(QStandardPaths::AppLocalDataLocation);
    //    qDebug() << "AppConfigLocation: " << QStandardPaths::standardLocations(QStandardPaths::AppConfigLocation);




    //    //These are set in $XDG_CONFIG_HOME/user-dirs.dirs

    //    qDebug() << "Home: " << QStandardPaths::standardLocations(QStandardPaths::HomeLocation);
    //    qDebug() << "Desktop (XDG_DESKTOP_DIR): " << QStandardPaths::standardLocations(QStandardPaths::DesktopLocation);
    //    qDebug() << "Documents (XDG_DOCUMENTS_DIR): " << QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation);
    //    qDebug() << "Download (XDG_DOWNLOAD_DIR): " << QStandardPaths::standardLocations(QStandardPaths::DownloadLocation);
    //    qDebug() << "Music: " << QStandardPaths::standardLocations(QStandardPaths::MusicLocation);
    //    qDebug() << "Pictures: " << QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
    //    qDebug() << "Movies: " << QStandardPaths::standardLocations(QStandardPaths::MoviesLocation);




}
/*                                                                                               */
bool EnvironmentService::exists(QStringList list)
{
    foreach(QString path,list){
        QDir dir(path);
        if(dir.isReadable())
            qDebug() << dir.absolutePath() << " is readable";
        else
            qDebug() << dir.absolutePath() << " is NOT readable";
    }
    return true;
}
/*                                                                                               */
EnvironmentService* EnvironmentService::m_instance;
EnvironmentService* EnvironmentService::instance(){if(!m_instance)m_instance=new EnvironmentService;return m_instance;}