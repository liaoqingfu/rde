#include "cdtrackmodel.h"
/*                                                                                               */
CDTrackModel::CDTrackModel()
{
    if(!QStandardPaths::findExecutable(RippingTool).isNull()){
        m_process=new QProcess(this);
        connect(m_process,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(finish(int,QProcess::ExitStatus)));
        m_process->setProgram(RippingTool);
        m_process->setProcessChannelMode(QProcess::MergedChannels);
        m_process->setArguments(QStringList("-Q"));
        if(m_process->open(QProcess::ReadOnly)){
        }
    }
    else
        qDebug() << "Could not find cd paranoia";
}
/*                                                                                               */
void CDTrackModel::error(QProcess::ProcessError error)
{
    switch(error){
    case QProcess::FailedToStart:return; //break
    case QProcess::Crashed:return;
    case QProcess::Timedout:return;
    case QProcess::WriteError:return;
    case QProcess::ReadError:return;
    case QProcess::UnknownError:return;
    }
}
/*                                                                                               */
void CDTrackModel::finish(const int &exitCode, QProcess::ExitStatus status)
{
    switch(status){
    case QProcess::NormalExit:{
        QString out=m_process->readAllStandardOutput();
        QStringRef ref=out.midRef(out.lastIndexOf("=\n")+3);
        ref.truncate(ref.indexOf("TOTAL")-1);
        beginResetModel();
        foreach(QString track,ref.toString().split("\n")){
            QStringRef length=track.midRef(track.indexOf("[")+1);
            //length.chop(length.indexOf("]"));
            list.append(length.left(length.indexOf("]")).toString());
        }
        endResetModel();
        break;
    }
    case QProcess::CrashExit:{
        qDebug() << RippingTool << " crashed?";
        return;
    }
    }
}
/*                                                                                               */
void CDTrackModel::ripCD()
{
    cdRipper=new CDRipper(this);
}
/*                                                                                               */
//void CDTrackModel::startedConverting()
//{
//    qDebug() << "Conversion started...";
//}
/*                                                                                               */
//void CDTrackModel::finishedConverting(const int &exitCode, QProcess::ExitStatus status)
//{
//    switch(status){
//    case QProcess::NormalExit:
//        qDebug() << "Finished Converting!";
//        return;
//    case QProcess::CrashExit:
//        return;
//    }
//}
/*                                                                                               */
//void CDTrackModel::convertError(QProcess::ProcessError error)
//{
//    switch(error){
//    case QProcess::FailedToStart:return;
//    case QProcess::Crashed:return;
//    case QProcess::Timedout:return;
//    case QProcess::WriteError:return;
//    case QProcess::ReadError:return;
//    case QProcess::UnknownError:return;
//    }
//}
/*                                                                                               */
//void CDTrackModel::readConvertOutput()
//{
//}
/*                                                                                               */
//void CDTrackModel::readConvertError()
//{
//}
/*                                                                                               */
QHash<int, QByteArray> CDTrackModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="Length";
    //hash[1]="Length";
    //hash[1]="Title";
    //hash[2]="Artist";
    //hash[3]="Album";
    //hash[4]="Genre";
    //hash[5]="Year";
    return hash;
}
/*                                                                                               */
QVariant CDTrackModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid())
        return list.at(index.row());
    return QVariant();
}
/*                                                                                               */
//    if(m_process->open(QProcess::ReadOnly)){
//        qDebug() << "Querying...";
//    }

/*                                                                                               */
//void CDTrackModel::startQuery(){beginResetModel();}
//        convertProcess=new QProcess(this);
//        connect(convertProcess,SIGNAL(started()),this,SLOT(startedConverting()));
//        connect(convertProcess,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(finishedConverting(int,QProcess::ExitStatus)));
//        connect(convertProcess,SIGNAL(error(QProcess::ProcessError)),this,SLOT(convertError(QProcess::ProcessError)));
//        connect(convertProcess,SIGNAL(readyReadStandardOutput()),this,SLOT(readConvertOutput()));
//        connect(convertProcess,SIGNAL(readyReadStandardError()),this,SLOT(readConvertError()));
//        convertProcess->setProgram(ConvertTool);
//        convertProcess->setWorkingDirectory(tempPath);
//        QStringList args;
//        args << "-e" << "*";
//        if(convertProcess->open(QProcess::ReadOnly)){
//        }
//        return;
//    }
/*                                                                                               */
//void CDTrackModel::readRipOutput()
//{
//    qDebug() << "OUT!";
//    while(m_process->canReadLine()){
//        QString line=m_process->readLine().constData();
//        line.chop(1);


//        qDebug() << "CD LINE:" << line;

//        //line=line.trimmed();
//        //if(!line.isEmpty())
//        //qDebug() << line;
//        //m_module->readOutput(line);
//    }
//}
/*                                                                                               */
//void CDTrackModel::readRipError()
//{
//    qDebug() << "STDERR";
//    //qDebug() << m_process->

//}
