#ifndef STATSMONITOR_H
#define STATSMONITOR_H
#include "statsmonitor_global.h"
#include "/development/rde/src/core/Module/ModuleInterface.h"
#include "sys/sysinfo.h"
#include <QSettings>
/*                                                                                               */
class StatsMonitor: public QObject,public ModuleInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "StatsMonitor" FILE "metadata.json")
    Q_INTERFACES(ModuleInterface)
    Q_PROPERTY(int totalRAM READ totalRAM NOTIFY totalRAMChanged)
    Q_PROPERTY(int usedRAM READ usedRAM NOTIFY usedRAMChanged)

private:
    struct sysinfo memInfo;
    Type type(){return Dock;}
    bool initialize();
    void timerEvent(QTimerEvent *event);
    double megaByte=1024*1024;
    int m_usedRAM;
    int usedRAM()const{return m_usedRAM;}
    int m_totalRAM;
    int totalRAM()const{return m_totalRAM;}
    int timerInterval;

signals:
    void usedRAMChanged();
    void totalRAMChanged();
};
#endif
