#include "gaming_supermodel.h"
/*                                                                                               */
QStringList gaming_supermodel::getData()
{
    QStringList l;
    QFile file("/system/data/gamexml/model3.xml");
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
bool gaming_supermodel::setGame(const QString &game)
{
    m_workingDir="/emu/supermodel";
    m_args << "roms/"+game+".zip";
    m_args << "-fullscreen";
    m_args << "-wide-screen";
    m_args << "-res=1280x720";
    m_args << "-multi-texture";
    return true;
}
/*                                                                                               */