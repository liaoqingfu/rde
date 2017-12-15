#include "librarymodel.h"
/*                                                                                               */
LibraryModel::LibraryModel()
{
    QSqlDatabase database=QSqlDatabase::addDatabase("QSQLITE","Music");
    database.setDatabaseName(QStandardPaths::standardLocations(QStandardPaths::AppLocalDataLocation).at(0)+"/database/music.db");
    m_watcher=new QFutureWatcher<QList<QStringList> >(this);
    connect(m_watcher,SIGNAL(finished()),this,SLOT(finished()));
    QSettings settings(qApp->applicationName(),"MediaPlayer");
    m_filter=settings.value("Filter").toString();
    startThread();
}
/*                                                                                               */
void LibraryModel::startThread()
{
    m_watcher->setFuture(QtConcurrent::run(this,&LibraryModel::thread,getQuery()));
}
/*                                                                                               */
extern QList<QStringList> LibraryModel::thread(const QString &newQuery)
{
    QList<QStringList> newList;
    QSqlQuery query(QSqlDatabase::database("Music"));
    if(query.prepare(newQuery)){
        query.setForwardOnly(true);
        query.exec(newQuery);
        while(query.next()){
            QStringList l;
            l << query.value(0).toString();
            l << query.value(1).toString();
            l << query.value(2).toString();
            l << query.value(3).toString();
            l << query.value(4).toString();
            l << query.value(5).toString();
            newList << l;
        }
    }
    else
        qDebug() << query.lastError().text();
    query.finish();
    return newList;
}
/*                                                                                               */
void LibraryModel::finished()
{
    QList<QStringList> result=m_watcher->result();
    if(result.count()>0){
        if(result!=list){
            beginResetModel();
            list=m_watcher->result();
            endResetModel();
        }
    }
    else
        m_filter.chop(1);
    emit filterChanged();
}
/*                                                                                               */
void LibraryModel::typeKey(const QString &key)
{
    m_filter+=key;
    startThread();
}
/*                                                                                               */
void LibraryModel::backspaceKey()
{
    if(!m_filter.isEmpty()){
        m_filter.chop(1);
        startThread();
    }
}
/*                                                                                               */
void LibraryModel::deleteKey()
{
    m_filter.clear();
    startThread();
}
/*                                                                                               */
void LibraryModel::deleteFile(const QString &file)
{
    QSqlDatabase database=QSqlDatabase::database("Music");
    database.exec("DELETE FROM Music WHERE File='"+file+"'");
}
/*                                                                                               */
QHash<int, QByteArray> LibraryModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="File";
    hash[1]="Title";
    hash[2]="Artist";
    hash[3]="Album";
    hash[4]="Genre";
    hash[5]="Year";
    return hash;
}
/*                                                                                               */
QVariant LibraryModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid())
        return list.at(index.row()).at(role);
    return QVariant();
}
/*                                                                                               */
QString LibraryModel::getQuery()
{
    return "SELECT File,Title,Artist,Album,Genre,Year FROM Music WHERE Title LIKE \"%"+m_filter+"%\" AND Title NOT NULL ORDER BY Title";
}
/*                                                                                               */
LibraryModel::~LibraryModel()
{
    QSqlDatabase::database("Music").close();
    QSqlDatabase::removeDatabase("Music");


    //if(filterQuery->isActive())
        //filterQuery->finish();
    //delete filterQuery;

    QSettings settings;
    settings.beginGroup("MediaPlayer");
    settings.setValue("Filter",m_filter);
    //settings.setValue("CurrentIndex",m_currentIndex);
    settings.endGroup();
}
/*                                                                                               */