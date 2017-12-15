#include "pcsx2.h"
/*                                                                                               */
PCSX2::PCSX2():Module("PCSX2")
{
}
/*                                                                                               */
QProcessEnvironment PCSX2::processEnvironment()const
{
    QProcessEnvironment env=QProcessEnvironment::systemEnvironment();
    env.insert("__GL_THREADED_OPTIMIZATIONS","1");
    return env;
}
/*                                                                                               */
QStringList PCSX2::importData()
{
    QStringList l;
    QFile file("/system/data/gamexml/ps2.xml");
    if(file.open(QIODevice::ReadOnly)){
        QXmlStreamReader reader;
        reader.setDevice(&file);
        if(reader.readNextStartElement() && reader.name()=="gamelist"){
            QString query;
            while(!reader.atEnd()){
                reader.readNext();
                if(reader.name()=="game"){
                    if(reader.isStartElement()){
                        query="(\"PCSX2\",\""+reader.attributes().value("name").toString()+"\"";
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
QStringList PCSX2::arguments(const QString &game)
{
    m_workingDir="/emu/ps2/iso";
    QStringList l;
    l << "--nogui";
    QFileInfo info("/emu/ps2/iso/"+game+".cso");
    if(info.isReadable())
        l << info.absoluteFilePath();
    else{
        info.setFile("/emu/ps2/iso/"+game+".iso");
        if(info.isReadable())
            l << info.absoluteFilePath();
    }
    return l;
}
/*                                                                                               */
void PCSX2::failedToStart()
{
    qDebug() << "Failed to start PCSX2";
}
/*                                                                                               */
void PCSX2::crashExit(const int &code)
{
    qDebug() << "PCSX2: crash exit code" << code;
}
/*                                                                                               */
void PCSX2::crashed(QByteArray text)
{
    qDebug() << "PCSX2 crashed:" << text;
}
/*                                                                                               */
void PCSX2::readError(QString text)
{
    qDebug() << "PCSX2 error:" << text;
}
/*                                                                                               */
void PCSX2::readOutput(QString text)
{
    //qDebug() << "PCSX2 output:" << text;
}
/*                                                                                               */
void PCSX2::normalExit(const int &code)
{
    qDebug() << "PCSX2: exited with code " << code;
}
/*                                                                                               */
void PCSX2::notRunning()
{
    qDebug() << "PCSX2: not running";
}
/*                                                                                               */
void PCSX2::running()
{
    qDebug() << "PCSX2: running";
}
/*                                                                                               */
PCSX2 *PCSX2::m_instance;
PCSX2 *PCSX2::instance(){if(!m_instance)m_instance=new PCSX2();return m_instance;}