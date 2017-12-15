#ifndef GAMING_LIBRETRO_H
#define GAMING_LIBRETRO_H
#define Program "retroarch"
/* includes                                                                                      */
#include "gaming_libretro_global.h"
#include "/development/Neon-DE/src/module/gaming/Module/GamingInterface.h"
#include <QXmlStreamReader>
#include <QFile>
/*                                                                                               */
class gaming_libretro:public QObject,public GamingInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "libretro" FILE "metadata.json")
    Q_INTERFACES(GamingInterface)

public:
    QString program()const{return Program;}
    QStringList getData();
    QProcessEnvironment processEnvironment()const;
    bool setGame(const QString &game);

private:
    bool initialize();
    QString m_corePath;
    QStringList m_cores;
    QString m_game;
    QStringList readXML(QString file);
    void readError(const QString &error);
    void readOutput(const QString &output);
};
/*                                                                                               */
#endif