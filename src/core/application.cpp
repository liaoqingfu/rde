#include "application.h"
/*                                                                                               */
Application::Application(int &argc,char **argv):QGuiApplication(argc,argv)
{
    setApplicationName(ApplicationName);
    setApplicationDisplayName(ApplicationDisplayName);
    setApplicationVersion(ApplicationVersion);
    setOrganizationName(OrganizationName);
    setOrganizationDomain(OrganizationDomain);
    setDesktopFileName(ApplicationName);

    connect(this,SIGNAL(applicationStateChanged(Qt::ApplicationState)),this,SLOT(stateChanged(Qt::ApplicationState)));
    connect(this,SIGNAL(lastWindowClosed()),this,SLOT(lastWindowClosed()));
    connect(this,SIGNAL(saveStateRequest(QSessionManager&)),this,SLOT(saveStateRequest(QSessionManager&)));
    connect(this,SIGNAL(commitDataRequest(QSessionManager&)),this,SLOT(commitDataRequest(QSessionManager&)));
    connect(this,SIGNAL(focusObjectChanged(QObject*)),this,SLOT(focusObjectChanged(QObject*)));
    connect(this,SIGNAL(focusWindowChanged(QWindow*)),this,SLOT(focusWindowChanged(QWindow*)));
    connect(this,SIGNAL(fontDatabaseChanged()),this,SLOT(fontDatabaseChanged()));
    connect(this,SIGNAL(layoutDirectionChanged(Qt::LayoutDirection)),this,SLOT(layoutDirectionChanged(Qt::LayoutDirection)));
    connect(this,SIGNAL(paletteChanged(const QPalette)),this,SLOT(paletteChanged(QPalette)));

    qsrand(QTime::currentTime().msec());
    //QLocale::setDefault(QLocale(QLocale::Dutch,QLocale::Belgium));

    Service::primaryScreen=primaryScreen();
    Service::engine=new QQmlEngine(this);
    Service::engine->addImportPath("/rde/bin/");
    Service::engine->rootContext()->setContextProperty("Margin",Margin);
    Service::engine->rootContext()->setContextProperty("DefaultFont","Square Sans Serif 7");
    Service::engine->rootContext()->setContextProperty("DefaultSmallFontSize",16);
    Service::engine->rootContext()->setContextProperty("DefaultLargeFontSize",24);

    loadServices();
    configureServices();
}
/*                                                                                               */
void Application::stateChanged(Qt::ApplicationState state)
{
    switch(state){
    case Qt::ApplicationSuspended:
        break;
    case Qt::ApplicationHidden:
        break;
    case Qt::ApplicationInactive:
        break;
    case Qt::ApplicationActive:
        break;
    }
}
/*                                                                                               */
void Application::lastWindowClosed()
{
    qDebug() << "Last window closed!";
}
/*                                                                                               */
void Application::saveStateRequest(QSessionManager &sessionManager)
{
    Q_UNUSED(sessionManager);
}
/*                                                                                               */
void Application::focusObjectChanged(QObject *focusObject)
{
    Q_UNUSED(focusObject)
}
/*                                                                                               */
void Application::focusWindowChanged(QWindow *focusWindow)
{
    Q_UNUSED(focusWindow);
}
/*                                                                                               */
void Application::commitDataRequest(QSessionManager &sessionManager)
{
    Q_UNUSED(sessionManager);
}
/*                                                                                               */
void Application::fontDatabaseChanged()
{
}
/*                                                                                               */
void Application::layoutDirectionChanged(Qt::LayoutDirection direction)
{
    Q_UNUSED(direction);
}
/*                                                                                               */
void Application::paletteChanged(const QPalette &pal)
{
    Q_UNUSED(pal);
}
/*                                                                                               */
void Application::loadServices()
{
    m_uiService=UIService::instance();
    m_errorService=ErrorService::instance();
    m_audioService=AudioService::instance();
    //m_bluetoothService=BluetoothService::instance();
    m_environmentService=EnvironmentService::instance();
    m_screenService=ScreenService::instance();
    m_networkService=NetworkService::instance();
    m_moduleService=ModuleService::instance();
    //m_gamepadService=GamepadService::instance();
    //m_displayService=DisplayService::instance();
    connect(this,SIGNAL(screenAdded(QScreen*)),m_screenService,SLOT(screenAdded(QScreen*)));
    connect(this,SIGNAL(screenRemoved(QScreen*)),m_screenService,SLOT(screenRemoved(QScreen*)));
    connect(this,SIGNAL(primaryScreenChanged(QScreen*)),m_screenService,SLOT(primaryScreenChanged(QScreen*)));
}
/*                                                                                               */
void Application::configureServices()
{
    QSettings settings;
    settings.beginGroup("Screen");
    m_screenService->configure(settings);
    settings.endGroup();
    settings.beginGroup("Audio");
    m_audioService->configure(settings);
    settings.endGroup();
    settings.beginGroup("UI");
    m_uiService->configure(settings);
    settings.endGroup();
    settings.beginGroup("Modules");
    m_moduleService->configure(settings);
    settings.endGroup();
}
/*                                                                                               */