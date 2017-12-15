#ifndef GAMINGINTERFACE
/*                                                                                               */
#define GAMINGINTERFACE
#define Plugin_iid "org.lemonade.gaming.interface"
/*                                                                                               */
#include <QtPlugin>
#include <QtQml>
/*                                                                                               */
class GamingInterface
{
public:
    QQmlContext *context;
    virtual QProcessEnvironment processEnvironment()const{return QProcessEnvironment::systemEnvironment();}
    virtual bool initialize(){return true;}
    virtual QString program()const=0;
    virtual QString workingDir()const{return m_workingDir;}
    virtual QStringList arguments()const{return m_args;}
    virtual QStringList getData()=0;
    virtual bool setGame(const QString &game)=0;
    virtual QIODevice::OpenMode openMode(){return QIODevice::ReadOnly;}
    virtual void normalExit(const int &code){Q_UNUSED(code)}
    virtual void crashExit(const int &code){Q_UNUSED(code)}
    virtual void readOutput(const QString &output){Q_UNUSED(output)}
    virtual void readError(const QString &error){Q_UNUSED(error)}

    virtual void failedToStart(){}
    virtual void crashed(const QByteArray &text){Q_UNUSED(text)}
    virtual void timedOut(){}
    virtual void writeError(){}
    virtual void readError(){}
    virtual void unknownError(){}
    virtual void notRunning(){}
    virtual void running(){}
    virtual void starting(){}
    QString m_workingDir;
    QStringList m_args;
};
/*                                                                                               */
Q_DECLARE_INTERFACE(GamingInterface,Plugin_iid)
#endif