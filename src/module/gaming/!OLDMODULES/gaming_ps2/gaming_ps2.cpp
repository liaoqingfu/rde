#include "gaming_ps2.h"
/*                                                                                               */
QStringList gaming_ps2::getData()
{
    QStringList l;
    QFile file("/system/data/gamexml/ps2.xml");
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
QProcessEnvironment gaming_ps2::processEnvironment()const
{
    QProcessEnvironment env=QProcessEnvironment::systemEnvironment();
    env.insert(Environment,"1");
    return env;
}
/*                                                                                               */
bool gaming_ps2::setGame(const QString &game)
{
    m_workingDir="/emu/ps2/iso";
    QFileInfo info;
    info.setFile(m_workingDir+"/"+game+".cso");
    if(info.exists()){
        m_args << info.fileName() << "--nogui";
        return true;
    }
    info.setFile(m_workingDir+"/"+game+".iso");
    if(info.exists()){
        m_args << info.fileName() << "--nogui";

        return true;
    }
    return false;
}
/*                                                                                               */