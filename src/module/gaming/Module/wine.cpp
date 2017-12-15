#include "wine.h"
/*                                                                                               */
WINE::WINE():Module("wine")
{
}
/*                                                                                               */
QProcessEnvironment WINE::processEnvironment()const
{
    QProcessEnvironment env=QProcessEnvironment::systemEnvironment();
    env.insert("WINEDEBUG","-all");
    //env.insert("WINEPREFIX,m_prefix);
    return env;
}
/*                                                                                               */
QStringList WINE::importData()
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
                        query="(\"wine\",\""+reader.attributes().value("name").toString()+"\"";
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
QStringList WINE::arguments(const QString &game)
{
    m_workingDir="/games/"+game;
    QStringList a;
    a << game;
    return a;
}
/*                                                                                               */
void WINE::crashed(QByteArray text)
{
    qDebug() << "WINE crash!:" << text;
}
/*                                                                                               */
void WINE::crashExit(const int &code)
{
    qDebug() << "WINE exited crashing with code " << code;
}
/*                                                                                               */
void WINE::failedToStart()
{
    qDebug() << "WINE failed to start!!!!";
}
/*                                                                                               */
void WINE::normalExit(const int &code)
{
    switch(ExitCodes(code)){
    case NoExe:qDebug() << "WINE could not find exe";break;
    case FailedToLaunch:qDebug() << "WINE: Program has crashed!";break;
    case IsNotValid:qDebug() << "IS NOT VALID";
    }
}
/*                                                                                               */
void WINE::readError(QString text)
{
    qDebug() << "WINE error:" << text;
}
/*                                                                                               */
void WINE::readOutput(QString text)
{
    //qDebug() << "WINE output:" << text;
}
/*                                                                                               */
WINE *WINE::m_instance;
WINE *WINE::instance(){if(!m_instance)m_instance=new WINE();return m_instance;}