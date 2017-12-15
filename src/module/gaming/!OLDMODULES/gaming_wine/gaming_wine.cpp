#include "gaming_wine.h"
/*                                                                                               */
bool gaming_wine::initialize()
{
    QSettings settings(qApp->applicationName(),"Gaming");
    settings.beginGroup("Wine");
    QDir prefix(settings.value("DefaultPrefix",".wine").toString());
    if(prefix.isReadable())
        m_prefix=prefix.absolutePath();
    else
        qDebug() << "Wine couldn't find prefix " << prefix.absolutePath();
    settings.endGroup();
    return true;
}
/*                                                                                               */
QStringList gaming_wine::getData()
{
    QStringList l;
    QFile file("/system/data/gamexml/wine.xml");
    if(file.open(QIODevice::ReadOnly)){
        QXmlStreamReader reader;
        reader.setDevice(&file);
        if(reader.readNextStartElement() && reader.name()=="gamelist"){
            QString query;
            while(!reader.atEnd()){
                reader.readNext();
                if(reader.name()=="game"){
                    if(reader.isStartElement()){
                        query="(\""+reader.attributes().value("name").toString()+"\"";
                        reader.readNextStartElement();
                        query=query+",\""+reader.readElementText()+"\"";
                        reader.readNextStartElement();
                        query=query+",\""+reader.readElementText()+"\"";
                        reader.readNextStartElement();
                        query=query+",\""+reader.readElementText()+"\"";
                        reader.readNextStartElement();
                        query=query+",\""+reader.readElementText()+"\")";
                    }
                    else if(reader.isEndElement()){
                        l << query;
                        query.clear();
                    }
                }
            }
            if (reader.hasError()){
                qDebug() << "Error! Line: " << reader.lineNumber() << ":" << reader.errorString();
            }
        }
        else
            qDebug() << "Failed to read next start element";
    }
    return l;
}
/*                                                                                               */
QProcessEnvironment gaming_wine::processEnvironment()const
{
    QProcessEnvironment env=QProcessEnvironment::systemEnvironment();
    env.insert("WINEDEBUG","-all");
    env.insert("WINEPREFIX",m_prefix);
    return env;
}
/*                                                                                               */
bool gaming_wine::setGame(const QString &game)
{
    m_args.clear();
    QDir prefix(m_prefix);
    if(prefix.isReadable()){
        QDir dir("/games/"+game);
        if(dir.isReadable()){
            QFileInfo exe(dir.absolutePath()+"/"+game+".exe");
            if(exe.isReadable()){
                QMimeDatabase db;
                QMimeType type=db.mimeTypeForFile(exe);
                if(type.inherits("application/octet-stream") && type.name()==MimeType){
                    m_workingDir=dir.absolutePath();
                    m_args << exe.completeBaseName();
                    return true;
                }
                else qWarning() << "Wine Error: Game executable " << exe.absoluteFilePath() << " does not appear to be a Windows executable";
            }
            else qWarning() << "Wine Error: Game executable " << exe.absoluteFilePath() << " not found!";
        }
        else qWarning() << "Wine Error: Game directory " << dir.absolutePath() << " not readable!";
    }
    else qWarning() << "Wine Error: Prefix " << prefix.absolutePath() << " not readable!";
    return false;
}