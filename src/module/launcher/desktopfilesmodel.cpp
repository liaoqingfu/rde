#include "desktopfilesmodel.h"
/*                                                                                               */
DesktopFilesModel::DesktopFilesModel(QObject *parent):QAbstractItemModel(parent)
{
    watcher=new QFutureWatcher<QVector<DesktopFile*> >(this);
    connect(watcher,SIGNAL(finished()),this,SLOT(finished()));

    dirWatcher=new QFileSystemWatcher(this);
    connect(dirWatcher,SIGNAL(directoryChanged(QString)),SLOT(directoryChanged(QString)));

    watcher->setFuture(QtConcurrent::run(this,&DesktopFilesModel::scan));
    //directoryChanged(dirWatcher->directories().at(2));
}
/*                                                                                               */
void DesktopFilesModel::directoryChanged(const QString &dir)
{
    //watcher->setFuture(QtConcurrent::run(this,&DesktopFilesModel::scan,dir));
}
/*                                                                                               */
extern QVector<DesktopFile*> DesktopFilesModel::scan()
{
    QVector<DesktopFile*> list;
    foreach(QString p,QStandardPaths::standardLocations(QStandardPaths::ApplicationsLocation)){
        QDir dir(p,"*.desktop");
        if(dir.isReadable()){
            QDirIterator iterator(dir,QDirIterator::Subdirectories);
            while(iterator.hasNext()){
                QSettings settings(iterator.next(),QSettings::NativeFormat);
                settings.beginGroup("Desktop Entry");

                if(!settings.value("NoDisplay").toBool() && settings.value("Type").toString()=="Application"){

                    QStringList cat=settings.value("Categories").toStringList();
                    if(cat.contains("Game") or cat.contains("Screensaver"));
                    else
                        list.append(new DesktopFile(settings));



                    //if(!settings.value("Categories").toStringList().contains("Game"))
                    //list.append(new DesktopFile(settings));

                }
                settings.endGroup();
            }
            dirWatcher->addPath(p);
        }
        else;
        //qDebug() << p << " is NOT readable";
    }
    return list;
}
/*                                                                                               */
QHash<int, QByteArray> DesktopFilesModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="IconName";
    return hash;
}
/*                                                                                               */
QVariant DesktopFilesModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid())
        return list.at(index.row())->icon();
    return QVariant();
}
/*                                                                                               */
void DesktopFilesModel::finished()
{
    beginResetModel();
    list=watcher->result();
    endResetModel();
}
/* EOF                                                                                           */