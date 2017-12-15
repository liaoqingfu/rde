#include "ppsspp.h"
/*                                                                                               */
PPSSPP::PPSSPP():Module("ppsspp")
{
}
/*                                                                                               */
QStringList PPSSPP::arguments(const QString &game)
{
    QStringList a;


    a << "/emu/psp/iso/"+game+".cso";
//    qDebug() << "PSP Game " << game;

//    QDir dir("/emu/psp/iso");
//    if(dir.isReadable()){
//        qDebug() << "PSP ISO dir ok!";
//        foreach(QString entry,dir.entryList(QStringList(game))){
//        //  foreach(QString entry,dir.entryList(QStringList(game))){
//            qDebug() << "CAND:" << entry;
//        }

//    }

    qDebug() << a;

    return a;
}
/*                                                                                               */
QStringList PPSSPP::importData()
{
    QStringList l;
    QFile file("/system/data/gamexml/psp.xml");
    if(file.open(QIODevice::ReadOnly)){
        QXmlStreamReader reader;
        reader.setDevice(&file);
        if(reader.readNextStartElement() && reader.name()=="gamelist"){
            QString query;
            while(!reader.atEnd()){
                reader.readNext();
                if(reader.name()=="game"){
                    if(reader.isStartElement()){
                        query="(\"ppsspp\",\""+reader.attributes().value("name").toString()+"\"";
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
PPSSPP *PPSSPP::m_instance;
PPSSPP *PPSSPP::instance(){if(!m_instance)m_instance=new PPSSPP();return m_instance;}