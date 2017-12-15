#include "gaming_uae.h"
/*                                                                                               */
bool gaming_uae::initialize()const
{
    return false;
}
/*                                                                                               */
QStringList gaming_uae::getData()
{
    QStringList l;
    QFile file("/system/data/gamexml/amiga.xml");
    if(file.open(QIODevice::ReadOnly)){
        QXmlStreamReader reader;
        reader.setDevice(&file);
        if(reader.readNextStartElement() && reader.name()=="gamelist"){
            QString name;
            QString title;
            QString developer;
            QString year;
            QString category;
            while(!reader.atEnd()){
                reader.readNext();
                if(reader.name()=="game"){
                    if(reader.isStartElement()){
                        name=reader.attributes().value("name").toString();
                        reader.readNextStartElement();
                        title=reader.readElementText();
                        reader.readNextStartElement();
                        developer=reader.readElementText();
                        reader.readNextStartElement();
                        year=reader.readElementText();
                        reader.readNextStartElement();
                        category=reader.readElementText();
                    }
                    else if(reader.isEndElement()){
                        l << "(\""+name+"\",\""+title+"\",\""+developer+"\",\""+year+"\",\""+category+"\")";
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
bool gaming_uae::setGame(const QString &game)
{
    m_args.clear();
    QDir dir("/emu/amiga");
    if(dir.isReadable()){
        m_workingDir=dir.absolutePath();
        QFileInfo file(m_workingDir+"/Configurations/"+game+".fs-uae");
        if(file.isReadable()){
            m_args << "--base-dir="+m_workingDir;
            m_args << "--window_width=1680";
            m_args << "--window_height=1080";
            m_args << "--keep_aspect=1";
            m_args << file.absoluteFilePath();
            return true;
        }
    }
    else return false;
}
/* EOF                                                                                           */