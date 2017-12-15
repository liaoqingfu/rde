#ifndef GAMING_MAME_H
/* defines                                                                                       */
#define GAMING_MAME_H
#define Program "mame"
/* includes                                                                                      */
#include "gaming_mame_global.h"
#include "/development/Neon-DE/src/module/gaming/Module/GamingInterface.h"
/* class                                                                                         */
class gaming_mame:public QObject,public GamingInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "mame" FILE "metadata.json")
    Q_INTERFACES(GamingInterface)

public:
    QString program()const{return Program;}
    QStringList getData();
    bool setGame(const QString &game);
    QIODevice::OpenMode openMode(){return QIODevice::ReadWrite;}

private:
    enum DataType{MAME,MESS};
    bool initialize();
    void readError(const QString &error);
    void readOutput(const QString &output);
    void normalExit(const int &code);
    void crashExit(const int &code);
    void crashed(const QByteArray &text);
    bool verifyProgram(const QString &media,const QString &game);
    bool verifyRom(const QString &game);
    enum ExitCodes{NoError,FailedValidity,MissingFiles,FatalError,Device,NoSuchGame,InvalidConfig};
    QStringList m_verifyRoms;
    QMap<QString,QStringList> map;
    QString m_game;
    QString m_media;
    int m_speed;
    int m_time;

    QStringList verify(DataType type);
    QStringList list(DataType type);

    //signals:
    //void writeToConsole(QVariant text);
};
/*                                                                                               */
#endif