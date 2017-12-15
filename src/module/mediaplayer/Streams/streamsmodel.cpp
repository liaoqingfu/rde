#include "streamsmodel.h"
/*                                                                                               */
StreamsModel::StreamsModel():Model()
{
    m_path=QStandardPaths::standardLocations(QStandardPaths::GenericDataLocation).at(0)+"/streams";
    startScan();
}
/*                                                                                               */
QHash<int, QByteArray> StreamsModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="Name";
    hash[1]="File";
    return hash;
}
/*                                                                                               */
QVariant StreamsModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid())
        return m_list.at(index.row()).at(role);
    return QVariant();
}
/*                                                                                               */
void StreamsModel::startScan()
{
    m_watcher=new QFutureWatcher<QVector<QStringList> >(this);
    connect(m_watcher,SIGNAL(finished()),this,SLOT(scanFinished()));
    m_watcher->setFuture(QtConcurrent::run(this,&StreamsModel::scan));
}
/*                                                                                               */
extern QVector<QStringList> StreamsModel::scan()
{
    QVector<QStringList> vector;
    QDir dir(m_path,"*.pls *.m3u");
    if(dir.isReadable()){
        foreach(QFileInfo info,dir.entryInfoList()){
            QSettings settings(info.absoluteFilePath(),QSettings::NativeFormat);
            settings.beginGroup("playlist");
            QStringList l;
            l << settings.value("Title1").toString() << info.absoluteFilePath();
            vector.append(l);
            settings.endGroup();
        }
    }
    return vector;
}
/*                                                                                               */
void StreamsModel::scanFinished()
{
    beginResetModel();
    m_list=m_watcher->result();
    endResetModel();
    m_watcher->deleteLater();
}
/*                                                                                               */