#ifndef GAMING_DOOM_H
/*                                                                                               */
#define GAMING_DOOM_H
/*                                                                                               */
#include "gaming_doom_global.h"
#include "/development/Neon-DE/src/module/gaming/Module/GamingInterface.h"
#include "mapmodel.h"
#include "modmodel.h"
/*                                                                                               */
class gaming_doom:public QObject,public GamingInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "doom" FILE "metadata.json")
    Q_INTERFACES(GamingInterface)

public:
    QString program()const{return "doom";}
    QStringList getData();
    bool setGame(const QString &game);

public slots:
    void setMap(const QString &map);
    void setMod(const QString &mod);

private:
    bool initialize();
    enum ExitCodes{Normal=0,NoIWAD=255};
    void readError(const QString &error);
    void readOutput(const QString &output);
    void normalExit(const int &code);
    void crashExit(const int &code);
    void crashed(const QByteArray &text);
};
/*                                                                                               */
#endif