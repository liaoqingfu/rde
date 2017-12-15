#ifndef GAMEPAD_H
#define GAMEPAD_H
/*                                                                                               */
#include "gamepad_global.h"
#include "/development/rde/src/core/Module/ModuleInterface.h"
#include <QGamepadManager>
#include "gamepadmodel.h"
/*                                                                                               */
class Gamepad: public QObject,public ModuleInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Gamepad" FILE "metadata.json")
    Q_INTERFACES(ModuleInterface)
    Q_PROPERTY(bool enabled READ enabled WRITE setEnabled NOTIFY enabledChanged)

public:
    bool enabled()const{return m_enabled;}
    void setEnabled(const bool &enabled);

private:
    Type type(){return ModuleInterface::Configure;}
    bool initialize();
    QGamepad *m_gamepad=NULL;
    bool m_enabled;
    void createGamepad();

private slots:
    void connectedGamepadsChanged();
    void gamepadConnected(const int &id);
    void gamepadDisconnected(const int &id);
    void configurationCanceled(const int &id);
    void buttonConfigured(const int &id,QGamepadManager::GamepadButton button);
    void upChanged(const bool &on){if(on)emit upOn();else emit upOff();}
    void downChanged(const bool &on){if(on)emit downOn();else emit downOff();}
    void leftChanged(const bool &on){if(on)emit leftOn();else emit leftOff();}
    void rightChanged(const bool &on){if(on)emit rightOn();else emit rightOff();}
    void aChanged(const bool &on){if(on)emit aOn();else emit aOff();}
    void bChanged(const bool &on){if(on)emit bOn();else emit bOff();}
    void xChanged(const bool &on){if(on)emit xOn();else emit xOff();}
    void yChanged(const bool &on){if(on)emit yOn();else emit yOff();}
    void selectChanged(const bool &on){if(on)emit selectOn();else emit selectOff();}
    void startChanged(const bool &on){if(on)emit startOn();else emit startOff();}
    void guideChanged(const bool &on){if(on)emit guideOn();else emit guideOff();}
    void l1Changed(const bool &on){if(on)emit l1On();else emit l1Off();}
    void l2Changed(const bool &on){if(on)emit l2On();else emit l2Off();}
    void l3Changed(const bool &on){if(on)emit l3On();else emit l3Off();}
    void r1Changed(const bool &on){if(on)emit r1On();else emit r1Off();}
    void r2Changed(const bool &on){if(on)emit r2On();else emit r2Off();}
    void r3Changed(const bool &on){if(on)emit r3On();else emit r3Off();}

signals:
    void enabledChanged();

    void upOn();
    void upOff();
    void downOn();
    void downOff();
    void leftOn();
    void leftOff();
    void rightOn();
    void rightOff();
    void aOn();
    void aOff();
    void bOn();
    void bOff();
    void xOn();
    void xOff();
    void yOn();
    void yOff();
    void startOn();
    void startOff();
    void selectOn();
    void selectOff();
    void guideOn();
    void guideOff();
    void l1On();
    void l1Off();
    void l2On();
    void l2Off();
    void l3On();
    void l3Off();
    void r1On();
    void r1Off();
    void r2On();
    void r2Off();
    void r3On();
    void r3Off();
};
/*                                                                                               */
#endif