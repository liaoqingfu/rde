#ifndef GAMING_NATIVE_H
/*                                                                                               */
#define GAMING_NATIVE_H
/*                                                                                               */
#include "gaming_native_global.h"
#include "/development/Neon-DE/src/module/gaming/Module/GamingInterface.h"
/*                                                                                               */
class gaming_native:public QObject,public GamingInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "native" FILE "metadata.json")
    Q_INTERFACES(GamingInterface)

public:
    QString program()const{return m_game;}
    QStringList getData();
    bool setGame(const QString &game);

private:
    QString m_game;
};
/*                                                                                               */
#endif