#ifndef GAMING_UAE_H
/* defines                                                                                       */
#define GAMING_UAE_H
#define Program "fs-uae"
//#define ExeMime "application/x-ms-dos-executable"
//#define ComMime "application/octet-stream"
/* includes                                                                                      */
#include "gaming_uae_global.h"
#include "/development/Neon-DE/src/module/gaming/Module/GamingInterface.h"
/*                                                                                               */
class gaming_uae:public QObject,public GamingInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "uae" FILE "metadata.json")
    Q_INTERFACES(GamingInterface)

public:
    QString program()const{return Program;}
    QStringList getData();
    bool setGame(const QString &game);

private:
    bool initialize()const;
    QString m_baseDir;
    QString m_game;

    //enum ExitCodes{FailedToLaunch=5,IsNotValid=87,IsWeird=66,BadExeFormat=193};
//    void notRunning();
//    void running();
//    void starting();
//    void readError(const QString &text);
//    void readOutput(const QString &text);
//    void normalExit(const int &code);
//    void crashExit(const int &code);
};
/*                                                                                               */
#endif