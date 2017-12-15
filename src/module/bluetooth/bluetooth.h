#ifndef BLUETOOTH_H
#define BLUETOOTH_H
/*                                                                                               */
#include "bluetooth_global.h"
#include "/development/rde/src/core/Module/ModuleInterface.h"
//#include "devicemanager.h"
//#include "devicemodel.h"
#include "adapter.h"
/*                                                                                               */
class Bluetooth:public QObject,public ModuleInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Bluetooth" FILE "metadata.json")
    Q_INTERFACES(ModuleInterface)
    Q_PROPERTY(bool active READ active NOTIFY activeChanged)

public:
    bool active()const{return m_adapter->isActive();}

public slots:
    void toggleAdapter();

private:
    bool initialize();
    //UI ui(){return Tray;}
    UI ui(){return Dock;}
    Adapter *m_adapter;
    //DeviceManager *m_deviceManager;

signals:
    void activeChanged();
    void deviceConnected();
    void deviceDisconnected();
};
/*                                                                                               */
#endif
