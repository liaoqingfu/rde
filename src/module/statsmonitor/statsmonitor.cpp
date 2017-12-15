#include "statsmonitor.h"
/*                                                                                               */
bool StatsMonitor::initialize()
{
    context->setContextProperty("StatsMonitor",this);
    sysinfo (&memInfo);
    m_totalRAM=memInfo.totalram/megaByte;
    m_usedRAM=0;

    QSettings settings;
    settings.beginGroup("StatsMonitor");
    startTimer(settings.value("Interval",1000).toInt(),Qt::VeryCoarseTimer);
    settings.endGroup();
    return true;
}
/*                                                                                               */
void StatsMonitor::timerEvent(QTimerEvent *event)
{
    m_usedRAM=m_totalRAM-(memInfo.freeram/megaByte);
    //qDebug() << "Used RAM: " << usedRAM();
    emit usedRAMChanged();
}
/*                                                                                               */