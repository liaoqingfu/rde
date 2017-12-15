#ifndef GAMING_PS2_H
/* defines                                                                                       */
#define GAMING_PS2_H
#define Program "PCSX2"
#define Environment "__GL_THREADED_OPTIMIZATIONS"
/* includes                                                                                      */
#include "gaming_ps2_global.h"
#include "/development/Neon-DE/src/module/gaming/Module/GamingInterface.h"
/* class                                                                                         */
class gaming_ps2:public QObject,public GamingInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "ps2" FILE "metadata.json")
    Q_INTERFACES(GamingInterface)

public:
    QString program()const{return Program;}
    QStringList getData();
    QProcessEnvironment processEnvironment()const;
    bool setGame(const QString &game);

private:
//    void notRunning(){}
//    void running(){}
//    void starting(){}
//    void readError(const QString &text);
//    void readOutput(const QString &text);
//    void normalExit(const int &code);
//    void crashExit(const int &code);
};
/*                                                                                               */
#endif