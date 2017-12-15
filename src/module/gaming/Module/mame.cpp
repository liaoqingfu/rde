#include "mame.h"
/*                                                                                               */
MAME::MAME():Module("mame")
{
    m_workingDir="/mame";

    m_drivers.insert("amigaaga_flop",QStringList("a1200"));
    m_drivers.insert("apple2",QStringList("apple2gs"));
    m_drivers.insert("c64_cart",QStringList("c64p") << "-cart");
    m_drivers.insert("c64_flop",QStringList("c64p") << "-flop");
    m_drivers.insert("cpc_flop",QStringList("cpc6128") << "-flop1");
    m_drivers.insert("famicom_flop",QStringList("fds"));
    m_drivers.insert("fmtowns_cd",QStringList("fmtowns"));
    m_drivers.insert("fmtowns_flop",QStringList("fmtowns") << "-flop1");
    m_drivers.insert("gameboy",QStringList("gbcolor"));
    m_drivers.insert("ibm5150",QStringList("at486") << "-flop2");
    m_drivers.insert("ibm5170",QStringList("at486") << "-flop1");
    m_drivers.insert("msx1_cart",QStringList("canonv30") << "-cart1");
    m_drivers.insert("msx1_flop",QStringList("canonv30") << "-flop1");
    m_drivers.insert("msx2_cart",QStringList("canonv30") << "-cart1");
    m_drivers.insert("msx2_flop",QStringList("canonv30") << "-flop1");
    m_drivers.insert("pc8801_flop",QStringList("pc8801mk2sr"));
    m_drivers.insert("pc98",QStringList("pc9821"));
    m_drivers.insert("pce",QStringList("pce") << "-cart");
    m_drivers.insert("pcecd",QStringList("pce"));
    m_drivers.insert("psx",QStringList("psj"));
    m_drivers.insert("saturn",QStringList("saturnjp"));
    m_drivers.insert("sms",QStringList("smsj"));
    m_drivers.insert("st_flop",QStringList("st_uk"));
    m_drivers.insert("x1_flop",QStringList("x1"));
    m_drivers.insert("x68k_flop",QStringList("x68000"));


    // LUA COMMANDS


    // emu.start("raiden") launches game raiden

}
/*                                                                                               */
QStringList MAME::arguments(const QString &game)
{
    QStringList a;


    if(game.contains("/")){
        QStringList l=game.split("/");
        if(m_drivers.contains(l.at(0)))
            a << m_drivers.value(l.at(0));
        else
            a << l.at(0);
        a << l.at(1);
    }
    else
        a << game;

    qDebug() << "MAME Args:" << a;

    a << "-console";
    return a;
}
/*                                                                                               */
QStringList MAME::importData()
{
    QStringList l;
    m_verifyRoms=verify(Arcade);
    l << list(Arcade);
    m_verifyRoms.clear();
    m_verifyRoms=verify(Home);
    l << list(Home);
    return l;
}
/*                                                                                               */
void MAME::failedToStart()
{
    qDebug() << "MAME failed to start!";
}
/*                                                                                               */
//void MAME::running()
//{
//}
/*                                                                                               */
//void MAME::notRunning()
//{
//}
/*                                                                                               */
void MAME::normalExit(const int &code)
{
    switch(ExitCodes(code)){
    case NoError:{
        //        if(m_speed>0){
        //            QSettings settings("neon",Program);
        //            settings.beginGroup("AverageSpeed");
        //            QString key;
        //            if(m_media.isEmpty())key=m_game;else key=m_media;
        //            settings.setValue(key,(int)m_speed);
        //            settings.endGroup();
        //            settings.beginGroup("TotalTimePlayed");

        //            // ...
        //            //        settings.setValue(key,text.midRef(idx3,idx4-idx3).toInt());
        //            //if(m_media.isEmpty())
        //            //key=m_game;
        //            //else
        //            //key=m_media+"/"+game;
        //            //qDebug() << "Playtime:" << m_time << " seconds";

        //            settings.endGroup();
        //            m_speed=0;
        //        }
        break;
    }
    case FailedValidity:
        qWarning() << "MAME exit: Failed Validity Checks Error";
        break;
    case MissingFiles:
        qWarning() << "MAME exit: Missing Files Error";
        break;
    case FatalError:
        qWarning() << "MAME exit: Fatal Error";
        break;
    case Device:
        qWarning() << "MAME exit: Device Initialization Error";
        break;
    case NoSuchGame:
        qWarning() << "MAME exit: No such game";
        break;
    case InvalidConfig:
        qWarning() << "MAME exit: Invalid configuration error";
        break;
    }
}
/*                                                                                               */
void MAME::crashed(QByteArray text)
{
}
/*                                                                                               */
void MAME::crashExit(const int &code)
{
    //    m_driver.clear();
    //    m_rom.clear();
}
/*                                                                                               */
void MAME::readOutput(QString text)
{
    //    if(text.contains("Average speed: ")){
    //        QSettings settings(qApp->applicationName(),"Gaming");
    //        settings.beginGroup("MAME");
    //        int idx1=text.indexOf(":")+2;
    //        int idx2=text.indexOf(".",idx1);
    //        settings.setValue(m_driver,text.mid(idx1,idx2-idx1));
    //        settings.endGroup();
    //    }
}
/*                                                                                               */
void MAME::readError(QString text)
{
    //qDebug() << "MAME ERROR:" << text;
}
/*                                                                                               */
QStringList MAME::verify(DataType type)
{
    QStringList l;
    QProcess process;
    process.setWorkingDirectory(workingDir());
    QStringList args;

    switch(type){
    case Arcade:args << "-verifyroms";break;
    case Home:args << "-verifysoftware";break;
    }

    process.start(m_program->name(),args,QIODevice::ReadOnly);
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
QStringList MAME::list(DataType type)
{
    QStringList l;
    QProcess process;
    process.setWorkingDirectory(m_workingDir);
    QStringList args;
    args << "-noconsole";

    switch(type){
    case Arcade:args << "-listxml" << m_verifyRoms;break;
    case Home:args << "-listsoftware";break;
    }
    process.setProgram(m_program->name());
    process.setArguments(args);
    QXmlStreamReader xml;
    xml.setDevice(&process);
    if(process.open(QIODevice::ReadOnly)){
        QString query;
        switch(type){
        case Arcade:{
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
                            query="(\"mame\",\""+attr.value("name").toString()+"\"";
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
        case Home:{
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
                            query="(\"mame\",\""+messmachine+"/"+attr.value("name").toString()+"\"";
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
MAME *MAME::m_instance;
MAME *MAME::instance(){if(!m_instance)m_instance=new MAME();return m_instance;}