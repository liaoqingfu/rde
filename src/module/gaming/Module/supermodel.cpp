#include "supermodel.h"
/*                                                                                               */
Supermodel::Supermodel():Module("supermodel")
{
}
/*                                                                                               */
QStringList Supermodel::arguments(const QString &game)
{
    m_workingDir="/emu/supermodel";
    QStringList l;
    l << "roms/"+game+".zip";
    l << "-fullscreen";
    l << "-wide-screen";
    l << "-res=1280x720";
    l << "-multi-texture";
    return l;
}
/*                                                                                               */
QStringList Supermodel::importData()
{
    QStringList l;
    QFile file("/system/data/gamexml/model3.xml");
    if(file.open(QIODevice::ReadOnly)){
        QXmlStreamReader reader;
        reader.setDevice(&file);
        if(reader.readNextStartElement() && reader.name()=="gamelist"){
            QString query;
            while(!reader.atEnd()){
                reader.readNext();
                if(reader.name()=="game"){
                    if(reader.isStartElement()){
                        query="(\"supermodel\",\""+reader.attributes().value("name").toString()+"\"";
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
                qWarning() << "Error! Line: " << reader.lineNumber() << ":" << reader.errorString();
            }
        }
        else
            qWarning() << "Failed to read next start element";
    }
    return l;
}
/*                                                                                               */
Supermodel *Supermodel::m_instance;
Supermodel *Supermodel::instance(){if(!m_instance)m_instance=new Supermodel();return m_instance;}