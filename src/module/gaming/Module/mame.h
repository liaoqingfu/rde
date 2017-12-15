#ifndef MAME_H
#define MAME_H
/*                                                                                               */
#include "module.h"
#include <QStandardPaths>
#include <QSettings>
#include <QCoreApplication>
#include <QMap>
/*                                                                                               */
class MAME:public Module
{
    Q_OBJECT
public:
    static MAME *instance();
    QStringList importData();
    QStringList arguments(const QString &game);
    QIODevice::OpenMode openMode(){return QIODevice::ReadWrite;}

private:
    MAME();
    static MAME *m_instance;
    enum DataType{Arcade,Home};
    enum ExitCodes{NoError,FailedValidity,MissingFiles,FatalError,Device,NoSuchGame,InvalidConfig};
    void crashed(QByteArray text);
    void crashExit(const int &code);
    void failedToStart();
    void normalExit(const int &code);
    void readError(QString text);
    void readOutput(QString text);
    //    void running();
    //    void notRunning();

    QStringList m_verifyRoms;
    QStringList verify(DataType type);
    QStringList list(DataType type);
    QMap<QString,QStringList> m_drivers;
};
/*                                                                                               */
#endif