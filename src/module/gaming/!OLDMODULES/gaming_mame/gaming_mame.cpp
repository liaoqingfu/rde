#include "gaming_mame.h"
/*                                                                                               */
bool gaming_mame::initialize()
{
    m_workingDir="/mame";
    QSettings settings("neon",Program);
    settings.beginGroup("MediaToSystem");
    foreach(QString key,settings.allKeys())
        map.insert(key,settings.value(key).toStringList());
    settings.endGroup();
    return true;
}
/*                                                                                               */
QStringList gaming_mame::getData()
{
    QStringList l;
    m_verifyRoms=verify(MAME);
    l << list(MAME);
    m_verifyRoms.clear();
    m_verifyRoms=verify(MESS);
    l << list(MESS);
    return l;
}
/*                                                                                               */
bool gaming_mame::setGame(const QString &game)
{
    m_args.clear();
    if(game.contains("/")){
        QStringList l=game.split("/");
        if(verifyProgram(l.at(0),l.at(1))){
            m_media=l.at(0);
            m_game=l.at(1);
            if(!m_media.isEmpty()){
                if(map.contains(m_media))
                    m_args << map.value(m_media);
                else
                    m_args << m_media;
            }
            m_args << m_game;
            return true;
        }
    }
    else{
        if(verifyRom(game)){
            m_media.clear();
            m_args << game;
            return true;
        }
    }
    //    args << "-record" << m_game+".inp";
    //    args << "-console";
    return false;
}
/*                                                                                               */
bool gaming_mame::verifyRom(const QString &game)
{
    QProcess process;
    process.setProgram(Program);
    process.setWorkingDirectory(workingDir());
    QStringList args;
    args << game;
    args << "-verifyroms";
    process.setArguments(args);
    if(process.open(QProcess::ReadOnly)){
        process.waitForFinished();
        if(process.exitCode()==0)
            return true;
        else{
            qDebug() << "MAMEPROC:" << process.readAllStandardError();
        }
    }
    return false;
}
/*                                                                                               */
bool gaming_mame::verifyProgram(const QString &media,const QString &game)
{
    QProcess process;
    process.setProgram(Program);
    process.setWorkingDirectory(m_workingDir);
    QStringList args;
    args << media;
    args << game;
    args << "-verifysoftware";
    process.setArguments(args);
    if(process.open(QProcess::ReadOnly)){
        process.waitForFinished();
        if(process.exitCode()==0)
            return true;
        else
            //qDebug() << "MAME code: " << process.exitCode();
            qDebug() << "MAMEPROC:" << process.readAllStandardError();
        //qDebug() << "MAMEPROC:" << process.readAllStandardOutput();
    }
    return false;

    //return true;
}
/*                                                                                               */
void gaming_mame::readError(const QString &error)
{
    //    qWarning() << "MAME error:" << error;
    //    if(error.contains("NOT FOUND")){
    //        QStringRef file=error.leftRef(error.indexOf(" "));
    //        //missingFiles << file.toString();
    //    }
}
/*                                                                                               */
void gaming_mame::readOutput(const QString &output)
{
    if(output.contains("Average speed: ")){
        int idx1=output.indexOf(":")+2;
        int idx2=output.indexOf("%",idx1);
        int idx3=output.indexOf("(",idx2)+1;
        int idx4=output.indexOf(" ",idx3);
        double spd=output.midRef(idx1,idx2-idx1).toDouble();
        m_speed=(int) spd;
        m_time=output.midRef(idx3,idx4-idx3).toInt();
    }
}
/*                                                                                               */
void gaming_mame::normalExit(const int &code)
{

}
/*                                                                                               */
void gaming_mame::crashed(const QByteArray &text)
{
    qDebug() << "MAME CRASHED:" << text;
}
/*                                                                                               */
void gaming_mame::crashExit(const int &code)
{
    qWarning() << "MAME crashed with code " << code;
}
/*                                                                                               */
QStringList gaming_mame::verify(DataType type)
{
    QStringList l;
    QProcess process;
    process.setWorkingDirectory(m_workingDir);
    QStringList args;

    switch(type){
    case MAME:args << "-verifyroms";break;
    case MESS:args << "-verifysoftware";break;
    }

    process.start(Program,args,QIODevice::ReadOnly);
    QByteArray output;
    while(!process.state()==QProcess::NotRunning){
        if (process.atEnd())
            process.waitForReadyRead();
        output.append(process.readAllStandardOutput());
        if(output.endsWith("\n")){
            output.chop(1);
            if(output.endsWith("good")){
                l << output.mid(7,output.indexOf(" ",7)-7);
                //qDebug() << "Good: " << output.mid(7,output.indexOf(" ",7)-7);
            }
            else if(output.endsWith("available")){
                output=output.mid(output.indexOf("romset ")+7);
                //qDebug() << "Available:" << output.left(output.indexOf(" "));
                l << output.left(output.indexOf(" "));
            }
            else if(output.endsWith("bad")){
                //qDebug() << "BAD:" << output;
            }
            output.clear();
        }
    }
    return l;
}
/*                                                                                               */
QStringList gaming_mame::list(DataType type)
{
    QStringList l;
    QProcess process;
    process.setWorkingDirectory(m_workingDir);
    QStringList args;
    args << "-noconsole";
    switch(type){
    case MAME:args << "-listxml" << m_verifyRoms;break;
    case MESS:args << "-listsoftware";break;    }
    process.setProgram(Program);
    process.setArguments(args);
    QXmlStreamReader xml;
    xml.setDevice(&process);
    if(process.open(QIODevice::ReadOnly)){
        QString query;
        switch(type){
        case MAME:{
            while(process.state()!=QProcess::NotRunning){
                if(process.atEnd())
                    process.waitForReadyRead();
                xml.readNextStartElement();
                if(xml.isStartElement()){
                    if(xml.name()=="machine"){
                        QXmlStreamAttributes attr=xml.attributes();
                        if(attr.value("ismechanical").toString()=="yes" or attr.value("runnable").toString()=="no" or attr.value("isbios").toString()=="yes" or attr.value("isdevice").toString()=="yes"){
                            query.clear();
                            xml.skipCurrentElement();
                        }
                        else
                            query="(\""+attr.value("name").toString()+"\"";
                    }
                    else if(xml.name()=="input"){
                        QXmlStreamAttributes attr=xml.attributes();
                        if(!attr.hasAttribute("coins")){
                            query.clear();
                            xml.skipCurrentElement();
                        }
                    }
                    else if(xml.name()=="description"){
                        QString description=xml.readElementText();
                        if(description.contains(" ("))
                            description.truncate(description.indexOf(" ("));
                        query=query+",\""+description+"\"";
                    }
                    else if(xml.name()=="year" or xml.name()=="manufacturer")
                        query=query+",\""+xml.readElementText()+"\"";
                }
                else if(xml.isEndElement() && xml.name()=="machine" && !query.isEmpty()){
                    //query=query+",\"\")"; // genre -- maybe import catver here?
                    //qDebug() << "QUERY IS:" << query;
                    l << query+",\"\")";
                    query.clear();
                }
            }
            break;
        }
        case MESS:{
            //QSettings catver;
            QString messmachine;
            while(process.state()!=QProcess::NotRunning){
                if(process.atEnd())
                    process.waitForReadyRead();
                xml.readNextStartElement();
                if(xml.isStartElement()){
                    if(xml.name()=="software"){
                        QXmlStreamAttributes attr=xml.attributes();
                        if(m_verifyRoms.contains(messmachine+":"+attr.value("name").toString()))
                            query="(\""+messmachine+"/"+attr.value("name").toString()+"\"";
                        else{
                            query.clear();
                            xml.skipCurrentElement();
                        }
                    }
                    else if(xml.name()=="description"){
                        QString description=xml.readElementText();
                        if(description.contains(" ("))
                            description.truncate(description.indexOf(" ("));
                        query=query+",\""+description+"\"";
                    }
                    else if(xml.name()=="year" or xml.name()=="publisher")
                        query=query+",\""+xml.readElementText()+"\"";
                    else if(xml.name()=="softwarelist"){
                        messmachine=xml.attributes().value("name").toString();
                        //catver
                    }
                }
                else if(xml.isEndElement() && xml.name()=="software" && !query.isEmpty()){
                    query=query+",\"\")"; // genre -- maybe import catver here?
                    l << query;
                    query.clear();
                }
            }
            break;
        }
        }
    }
    return l;
}
/*                                                                                               */
//        //delete from mame where id like "%neogeo/%"
//        //delete from mame where id like "%stv/%"