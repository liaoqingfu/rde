#include "historyreader.h"
/*                                                                                               */
HistoryReader::HistoryReader()
{
    //m_text="Empty";
    process=new QProcess(this);
    process->setProgram("sed");
    connect(process,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(finished(int,QProcess::ExitStatus)));

    path="/mame/dats/history.dat";
    QFileInfo info(path);
    if(info.isReadable()){
        setEnabled(true);
        //QMimeDatabase db;
        //QMimeType type=db.mimeTypeForFile(info.absoluteFilePath());
        //qDebug() << "Parents:" << type.parentMimeTypes();
    }
    else
        setEnabled(false);
}
/*                                                                                               */
void HistoryReader::updateHistory(const QString &module, const QString &game)
{
    //if(process->isOpen())
    //process->close();

    if(module=="mame"){
        QStringList args;
        args << "-n";

        QString tag;
        if(game.contains("/")){
            QStringList l=game.split("/");
            tag="/"+l.at(0)+"="+l.at(1);
        }
        else
            tag="/info="+game;

        tag.append(",/,/end/p");
        args << tag;
        args << path;
        process->setArguments(args);
        if(process->open(QIODevice::ReadOnly)){
        }
    }
    else{
        m_text.clear();
        emit textChanged();
    }
}
/*                                                                                               */
void HistoryReader::finished(const int &code, QProcess::ExitStatus status)
{
    QString text=process->readAllStandardOutput().trimmed();
    if(!text.isEmpty()){
        QStringList lines=text.split("\n");
        lines.removeFirst();
        lines.removeFirst();
        lines.removeFirst();
        lines.removeLast();
        m_text=lines.join("\n");
    }
    else
        m_text.clear();
    emit textChanged();
}
/*                                                                                               */