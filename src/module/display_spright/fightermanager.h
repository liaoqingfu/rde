#ifndef FIGHTERMANAGER_H
#define FIGHTERMANAGER_H
/*                                                                                               */
#include "fighter.h"

#include <QDir>
#include <QSettings>
#include <QFutureWatcher>
#include <QtConcurrentRun>
/*                                                                                               */
class FighterManager : public QObject
{
    Q_OBJECT
public:
    static FighterManager *instance();

private:
    QString m_path;
    static FighterManager *m_instance;
    FighterManager();
    void scan();
    QFutureWatcher<QStringList> *m_watcher;
    QStringList scanThread();

private slots:
    void scanFinished();
};
/*                                                                                               */
#endif