#ifndef MODULE_H
#define MODULE_H
/*                                                                                               */
#include "program.h"
#include <QtConcurrentRun>
#include <QFutureWatcher>
#include <QProcessEnvironment>
#include <QVector>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QXmlStreamReader>
#include <QDir>
/*                                                                                               */
class Module : public QObject
{
    Q_OBJECT
public:
    explicit Module(const QString &program);
    static QVector<Module*> modules;
    static Module *byIID(const QString &IID);

    QString program(){return m_program->name();}
    QString workingDir(){return m_workingDir;}
    virtual QStringList arguments(const QString &game)=0;
    virtual QStringList importData()=0;

    virtual QProcessEnvironment processEnvironment()const{return QProcessEnvironment::systemEnvironment();}
    virtual QIODevice::OpenMode openMode(){return QIODevice::ReadOnly;}

    virtual void starting(){}
    virtual void running(){}
    virtual void notRunning(){}
    virtual void failedToStart(){}
    virtual void timedOut(){}

    //virtual void readError(){}
    //virtual void writeError(){}
    virtual void unknownError(){}
    virtual void readOutput(QString text){Q_UNUSED(text)}
    virtual void readError(QString text){Q_UNUSED(text)}
    virtual void crashed(QByteArray text){Q_UNUSED(text)}
    virtual void normalExit(const int &code){Q_UNUSED(code)}
    virtual void crashExit(const int &code){Q_UNUSED(code)}
    void startImporting();

protected:
    Program *m_program;
    QString m_workingDir;

private:
    QFutureWatcher<QStringList> *m_watcher;
    QStringList importThread();
    static QMap<QString,Module*> iidMap;


private slots:
    void importFinished();
    void fileChanged(const QString &program);

signals:
    void hideDock();
};
/*                                                                                               */
#endif