#ifndef RETRO_H
#define RETRO_H
/*                                                                                               */
#include "module.h"
#include <QStandardPaths>
#include <QFile>
/*                                                                                               */
class Retro : public Module
{
    Q_OBJECT
public:
    static Retro *instance();
    QStringList importData();
    QStringList arguments(const QString &game);

private:
    Retro();
    static Retro *m_instance;
    enum ExitCodes{Normal,Error};

    void crashed(QByteArray text);
    void crashExit(const int &code);
    void failedToStart();
    void normalExit(const int &code);
    void notRunning();
    void readError(QString text);
    void readOutput(QString text);
    void running();

    QStringList readXML(QString file);
    //QString m_core;
    //QString m_media;
    //QString m_rompath;
    //QString m_ext;
};
/*                                                                                               */
#endif