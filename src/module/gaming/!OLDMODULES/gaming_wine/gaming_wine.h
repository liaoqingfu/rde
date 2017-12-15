#ifndef GAMING_WINE_H
/* defines                                                                                       */
#define GAMING_WINE_H
#define Program "wine"
#define MimeType "application/x-ms-dos-executable"
/* includes                                                                                      */
#include "gaming_wine_global.h"
#include "/development/Neon-DE/src/module/gaming/Module/GamingInterface.h"
#include <QXmlStreamReader>
/*                                                                                               */
class gaming_wine:public QObject,public GamingInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "wine" FILE "metadata.json")
    Q_INTERFACES(GamingInterface)

public:
    QString program()const{return Program;}
    QStringList getData();
    QProcessEnvironment processEnvironment()const;
    bool setGame(const QString &game);

private:
    bool initialize();
    QString m_prefix;
    void readError(const QString &error);
    void readOutput(const QString &output);
    void normalExit(const int &code);
    void crashExit(const int &code);
    enum ExitCodes{NoExe=2,FailedToLaunch=5,IsNotValid=87,IsWeird=66,BadExeFormat=193};
};
/*                                                                                               */
#endif