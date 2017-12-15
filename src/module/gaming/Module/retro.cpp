#include "retro.h"
/*                                                                                               */
Retro::Retro():Module("retroarch")
{
}
/*                                                                                               */
QStringList Retro::importData()
{
    QStringList l;
    l << readXML("/system/data/gamexml/3ds.xml");
    l << readXML("/system/data/gamexml/dc.xml");
    l << readXML("/system/data/gamexml/dos.xml");
    l << readXML("/system/data/gamexml/nds.xml");
    l << readXML("/system/data/gamexml/psp.xml");
    l << readXML("/system/data/gamexml/dolphin.xml");
    return l;
}
/*                                                                                               */
QStringList Retro::readXML(QString file)
{
    QStringList l;
    QFile f(file);
    if(f.open(QIODevice::ReadOnly)){
        QXmlStreamReader reader;
        reader.setDevice(&f);
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
                        QFileInfo info(file);
                        l << "(\"retroarch\",\""+info.baseName()+"/"+name+"\",\""+title+"\",\""+developer+"\",\""+year+"\",\""+category+"\")";
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
QStringList Retro::arguments(const QString &game)
{
    QStringList a;
    QStringList k=game.split("/");

    if(k.at(0)=="nds"){
        m_workingDir="/emu/nds/roms/";
        a << "-L" << "/emu/retroarch/cores/desmume_libretro.so";
        a << "/emu/nds/roms/"+k.at(1)+".7z";
    }

    else if(k.at(0)=="dos"){
        m_workingDir="/emu/dos/games/"+k.at(1);
        a << "-L" << "/emu/retroarch/cores/dosbox_libretro.so";
        a << "/emu/dos/configurations/"+k.at(1)+".conf";
    }

    else if(k.at(0)=="dolphin"){
        m_workingDir="/emu/dolphin/iso";
        a << "-L" << "/emu/retroarch/cores/dolphin_libretro.so";


        QStringList exts;
        exts << "gcz";
        exts << "wbfs";
        exts << "wad";
        exts << "iso";

        foreach(QString x,exts){
            QFileInfo i("/emu/dolphin/"+k.at(1)+"."+x);
            if(i.exists())
                a << i.absoluteFilePath();
        }
        //                m_media=i.absoluteFilePath();
        //            //m_media="/emu/dolphin/"+k.at(1)+x;
        //            //m_ext=x;
        //        }
    }
    else if(k.at(0)=="dc"){
        m_workingDir="/emu/dc/iso";
        a << "-L" << "/emu/retroarch/cores/reicast_libretro.so";
        a << "/emu/dc/iso/"+k.at(1)+".chd";
    }
    else if(k.at(0)=="psp"){
        m_workingDir="/emu/psp/iso";
        a << "-L" << "/emu/retroarch/cores/ppsspp_libretro.so";
        a << "/emu/psp/iso/"+k.at(1)+".cso";
    }
    else if(k.at(0)=="3ds"){
        //m_core="/emu/retroarch/cores/citra_libretro.so";
        //m_media="/emu/3ds/"+k.at(1)+".7z";
        //m_ext="7z";
    }
    else if(k.at(0)=="n64"){
        //m_core="/emu/retroarch/cores/parallel_n64_libretro.so";
        //m_rompath="/emu/n64/";
        //m_ext="7z";
    }


    qDebug() << "Arg:" << a;
    return a;
}
/*                                                                                               */
void Retro::crashed(QByteArray text)
{
    qDebug() << "RA has crashed:" << text;
}
/*                                                                                               */
void Retro::crashExit(const int &code)
{
    qDebug() << "RA crashed with exitcode " << code;
}
/*                                                                                               */
void Retro::failedToStart()
{
    qDebug() << "RA failed to sart!!!";
}
/*                                                                                               */
void Retro::normalExit(const int &code)
{
    switch(ExitCodes(code)){
    case Normal:qDebug() << "RA exited normally!!!";break;
    case Error:qDebug() << "RA exited with an error";break;
    }
}
/*                                                                                               */
void Retro::readError(QString text)
{
    qDebug() << "RA Error:" << text;
}
/*                                                                                               */
void Retro::readOutput(QString text)
{
    qDebug() << "RA Output:" << text;
}
/*                                                                                               */
void Retro::running()
{
}
/*                                                                                               */
void Retro::notRunning()
{
}
/*                                                                                               */
Retro *Retro::m_instance;
Retro *Retro::instance(){if(!m_instance)m_instance=new Retro();return m_instance;}