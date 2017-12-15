#include "program.h"
/* Constructor                                                                                   */
Program::Program(const QString name,QObject *parent):QObject(parent)
{
    m_programName=name;
}
/*                                                                                               */
bool Program::initialize()
{
    QString path=findPath();
    if(!path.isEmpty()){
        fileWatcher=new QFileSystemWatcher(this);
        connect(fileWatcher,SIGNAL(fileChanged(QString)),this,SLOT(fileChanged(QString)));
        return fileWatcher->addPath(path);
    }
    return false;
}
/*                                                                                               */
void Program::fileChanged(const QString &file)
{
    Q_UNUSED(file);
    QFileInfo info(file);
    if(info.isExecutable()){
        //qDebug() << file << " changed!";
        md5Watcher=new QFutureWatcher<QByteArray>(this);
        connect(md5Watcher,SIGNAL(finished()),this,SLOT(md5Ready()));
        md5Watcher->setFuture(QtConcurrent::run(this,&Program::getMd5));
    }
    else
        emit removed();
}
/*                                                                                               */
extern QByteArray Program::getMd5()
{
    QFile file(path());
    if(file.open(QFile::ReadOnly)){
        QCryptographicHash hash(QCryptographicHash::Md5);
        if(hash.addData(&file))
            return hash.result().toHex();
    }
    return QByteArray();
}
/*                                                                                               */
void Program::md5Ready()
{
    QByteArray result=md5Watcher->result();
    md5Watcher->deleteLater();

    QSettings settings("rde","gaming");
    settings.beginGroup("Programs");

    m_md5=settings.value(m_programName).toByteArray();
    if(m_md5!=result){
        settings.setValue(m_programName,QString(m_md5));
        m_md5=result;
        emit updated();
    }
    settings.endGroup();
}
/*                                                                                               */
bool Program::isValid()const
{
    return !QStandardPaths::findExecutable(m_programName).isEmpty();
}
/* EOF                                                                                           */