#include "gaming_libretro.h"
/*                                                                                               */
bool gaming_libretro::initialize()
{
    QDir coreDir("/emu/retroarch/cores","*.so");
    if(coreDir.isReadable()){
        foreach(QFileInfo info,coreDir.entryInfoList()){
            m_cores.append(info.absoluteFilePath());
            qDebug() << "Found retro core " << info.absoluteFilePath();
        }
    }
    else
        qDebug() << "Could not read core dir " << coreDir.absolutePath();


    //qDebug() << "Cores:" << m_cores;
    return true;
}
/*                                                                                               */
QStringList gaming_libretro::getData()
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
QProcessEnvironment gaming_libretro::processEnvironment()const
{
    QProcessEnvironment env=QProcessEnvironment::systemEnvironment();
    return env;
}
/*                                                                                               */
bool gaming_libretro::setGame(const QString &game)
{
    m_args.clear();
    QStringList k=game.split("/");
    QString core;
    QString rp;
    QString ext;
    if(k.at(0)=="nds"){
        core="/emu/retroarch/cores/desmume_libretro.so";
        rp="/emu/nds/roms/";
        ext="7z";
    }
    else if(k.at(0)=="dos"){
        core="/emu/retroarch/cores/dosbox_libretro.so";
        rp="/emu/dos/configurations/";
        ext="conf";
        m_workingDir="/emu/dos/games/"+k.at(1);
    }
    else if(k.at(0)=="dolphin"){
        core="/emu/retroarch/cores/dolphin_libretro.so";
        rp="/emu/dolphin/";

        QStringList exts;
        exts << "gcz";
        exts << "wbfs";
        exts << "wad";
        exts << "iso";

        foreach(QString x,exts){
            QFileInfo i(rp+k.at(1)+"."+x);
            if(i.exists())
                ext=x;
        }
    }
    else if(k.at(0)=="dc"){
        core="/emu/retroarch/cores/reicast_libretro.so";
        rp="/emu/dc/iso/";
        ext="chd";
    }
    else if(k.at(0)=="psp"){
        core="/emu/retroarch/cores/ppsspp_libretro.so";
        rp="/emu/psp/iso/";
        ext="cso";
    }
    else if(k.at(0)=="3ds"){
        core="/emu/retroarch/cores/citra_libretro.so";
        rp="/emu/3ds/";
        ext="7z";
    }
    else if(k.at(0)=="n64"){
        core="/emu/retroarch/cores/parallel_n64_libretro.so";
        rp="/emu/n64/";
        ext="7z";
    }
    m_args << "-L" << core << rp+k.at(1)+"."+ext;
    return true;
}
/*                                                                                               */
QStringList gaming_libretro::readXML(QString file)
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
                        l << "(\""+info.baseName()+"/"+name+"\",\""+title+"\",\""+developer+"\",\""+year+"\",\""+category+"\")";

                        //l << "(\""+name+"\",\""+title+"\",\""+developer+"\",\""+year+"\",\""+category+"\")";
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
void gaming_libretro::readError(const QString &error)
{
    qDebug() << "Libretro error:" << error;
}
/*                                                                                               */
void gaming_libretro::readOutput(const QString &output)
{
    qDebug() << "Libretro output:" << output;
}
/*                                                                                               */