#include "program.h"
/*                                                                                               */
Program::Program(const QString &name,QObject *parent):QObject(parent)
{
    QString path=QStandardPaths::findExecutable(name);
    if(!path.isEmpty()){
        m_name=name;
        m_fileWatcher=new QFileSystemWatcher(this);
        connect(m_fileWatcher,SIGNAL(fileChanged(QString)),this,SLOT(changed(QString)));
        m_fileWatcher->addPath(path);
    }
}
/*                                                                                               */
void Program::changed(const QString &file)
{
    qDebug() << "Program " << file << "has changed!!!!";
}
/*                                                                                               */