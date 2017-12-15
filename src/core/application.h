#ifndef APPLICATION_H
#define APPLICATION_H
#define ApplicationName "rde"
#define ApplicationDisplayName "RDE"
#define OrganizationName "rde"
#define OrganizationDomain "org.rde"
#define ApplicationVersion "1.0"
//#define PlatformName "wayland"
#define Margin 4
/*                                                                                               */
#include "Audio/audioservice.h"
//#include "Bluetooth/bluetoothservice.h"
#include "Environment/environmentservice.h"
//#include "Gamepad/gamepadservice.h"
#include "Module/moduleservice.h"
#include "Network/networkservice.h"
#include "Screen/screenservice.h"
#include "UI/uiservice.h"
#include "Display/displayservice.h"
#include "Error/errorservice.h"
#include <QDBusConnection>
#include <QGuiApplication>
/*                                                                                               */
class Application : public QGuiApplication
{
    Q_OBJECT
public:
    explicit Application(int &argc,char **argv);

private:
    void loadServices();
    void configureServices();

    ErrorService *m_errorService;
    AudioService *m_audioService;
    DisplayService *m_displayService;
    //BluetoothService *m_bluetoothService;
    EnvironmentService *m_environmentService;
    //GamepadService *m_gamepadService;
    ModuleService *m_moduleService;
    NetworkService *m_networkService;
    ScreenService *m_screenService;
    UIService *m_uiService;

private slots:
    void saveStateRequest(QSessionManager &sessionManager);
    void stateChanged(Qt::ApplicationState state);
    void lastWindowClosed();
    void commitDataRequest(QSessionManager &sessionManager);
    void focusObjectChanged(QObject *focusObject);
    void focusWindowChanged(QWindow *focusWindow);
    void layoutDirectionChanged(Qt::LayoutDirection direction);
    void fontDatabaseChanged();
    void paletteChanged(const QPalette &pal);
};
/*                                                                                               */
#endif