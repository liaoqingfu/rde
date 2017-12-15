#include "uiservice.h"
/*                                                                                               */
UIService::UIService():Service("UI")
{
    QDir iconDir(QStandardPaths::standardLocations(QStandardPaths::GenericDataLocation).at(0)+"/icons");
    if(iconDir.isReadable()){
        QSettings settings;
        settings.beginGroup("UI");
        QIcon::setThemeSearchPaths(QStringList(iconDir.absolutePath()));
        QIcon::setThemeName(settings.value("IconTheme",QIcon::themeName()).toString());
        settings.endGroup();
    }

    engine->addImageProvider("Icon",new IconProvider);
    engine->addImageProvider("MimeIcon",new MimeIconProvider);

    Compositor::instance();

    m_dock=Dock::instance();
    m_dock->setGeometry(0,0,primaryScreen->geometry().width()/8,primaryScreen->geometry().height());

    m_mainWindow=MainWindow::instance();
    m_mainWindow->setGeometry(m_dock->width(),0,primaryScreen->geometry().width()-m_dock->width(),primaryScreen->availableGeometry().height());

    qmlRegisterType<Surface>("org.rde.core",1,0,"Surface");
    qmlRegisterType<TrayModel>("org.rde.core",1,0,"TrayModel");
}
/*                                                                                               */
bool UIService::configure(QSettings &settings)
{
    //m_desktop->showNormal();
    m_dock->showNormal();
    //m_mainWindow->showNormal();
    //    //qDebug() << "Configuring user interface!";
    //    QIcon::setThemeName(settings.value("IconTheme","oxygen").toString());
    //    return true;
    return true;
}
/*                                                                                               */
void UIService::availableGeometryChanged(QRect geometry)
{
    //qDebug() << "Screen geometry changed to " << geometry;
}
/*                                                                                               */
UIService* UIService::m_instance;
UIService* UIService::instance(){if(!m_instance)m_instance=new UIService;return m_instance;}
/*                                                                                               */
//bool ServiceUserInterface::initializeiconTheme()
//{
//    QDir dir(QStandardPaths::standardLocations(QStandardPaths::GenericDataLocation).at(0)+"/icons/");
//    if(dir.isReadable()){
//        QStringList iconPaths;
//        iconPaths << dir.absolutePath();
//        QIcon::setThemeSearchPaths(iconPaths);
//    }
//    else
//        qDebug() << "Icon dir " << dir.absolutePath() << " is not readable!";
//    return true;
//}
//qDebug() << "Icon theme search paths: " << QIcon::themeSearchPaths();

//m_compositor=new Compositor(this);
//engine->rootContext()->setContextProperty("Compositor",m_compositor);
//QIcon::setThemeName(settings.value("IconTheme","oxygen").toString());
//QIcon::setThemeName("oxygen");





// Register shared elements

//    initializeiconTheme();

//    m_desktopWidget=new DesktopWidget(qApp->desktop());
//    m_dockWidget=new DockWidget(qApp->desktop());
//    m_window=new MainWindow();

//    engine->rootContext()->setContextProperty("DesktopRoot",m_desktopWidget->rootObject());
//    engine->addImageProvider("Icon",new IconProvider);

//    m_dockWidget->show();



//connect(primaryScreen,SIGNAL(availableGeometryChanged(QRect)),this,SLOT(availableGeometryChanged(QRect)));


//m_desktop->setGeometry(primaryScreen->availableGeometry());

//m_desktop=Desktop::instance();
//m_desktop->setGeometry(primaryScreen->geometry());
//m_dock->setParent(m_desktop);
//m_dock->setGeometry(0,0,m_dock->parent()->width()/8,m_dock->parent()->height());
//m_mainWindow->setParent(m_desktop);