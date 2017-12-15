#include "librarymodel.h"
/*                                                                                               */
LibraryModel::LibraryModel()
{
    QSqlDatabase db=QSqlDatabase::database(ConnectionName);
    QSqlQuery q=db.exec("SELECT COUNT(*) from games");
    if(q.first()){
        m_total=q.value(0).toInt();
    }
    q.finish();

    filterQuery=new QSqlQuery(db);
    filterQuery->setForwardOnly(true);
    m_filterWatcher=new QFutureWatcher<QVector<QStringList> >(this);
    connect(m_filterWatcher,SIGNAL(finished()),this,SLOT(filterReady()));

    infoQuery=new QSqlQuery(db);
    infoQuery->setForwardOnly(true);
    m_infoWatcher=new QFutureWatcher<void>(this);
    connect(m_infoWatcher,SIGNAL(finished()),this,SLOT(infoReady()));

    m_title="";
    m_developer="";
    m_year="";
    m_category="";

    m_timer=new QTimer(this);
    m_timer->setInterval(200);
    m_timer->setSingleShot(true);
    connect(m_timer,SIGNAL(timeout()),this,SLOT(timerReady()));

    QSettings settings(qApp->applicationName(),"Gaming",this);
    settings.beginGroup("Library");
    m_currentIndex=settings.value("CurrentIndex",0).toInt();
    m_filter=settings.value("Filter").toString();
    settings.endGroup();

    m_filterWatcher->setFuture(QtConcurrent::run(this,&LibraryModel::filterThread,m_filter));
}
/*                                                                                               */
void LibraryModel::typeKey(const QString &key)
{
    m_filterWatcher->cancel();
    m_filter+=key;
    m_filterWatcher->setFuture(QtConcurrent::run(this,&LibraryModel::filterThread,m_filter));
}
/*                                                                                               */
void LibraryModel::backspaceKey()
{
    if(!m_filter.isEmpty()){
        m_filter.chop(1);
        m_filterWatcher->setFuture(QtConcurrent::run(this,&LibraryModel::filterThread,m_filter));
    }
}
/*                                                                                               */
void LibraryModel::deleteKey()
{
    if(!m_filter.isEmpty()){
        m_filter.clear();
        m_results.clear();
        m_filterWatcher->setFuture(QtConcurrent::run(this,&LibraryModel::filterThread,m_filter));
    }
}
/*                                                                                               */
extern QVector<QStringList> LibraryModel::filterThread(const QString &filter)
{
    QVector<QStringList> vector;
    QString q=getQuery();
    if(filterQuery->prepare(q)){
        filterQuery->exec(q);
        while(filterQuery->next())
            vector.append(QStringList() << filterQuery->value(0).toString() << filterQuery->value(1).toString());
    }
    else
        qDebug() << "Active query failed to prepare " << filter;
    return vector;
}
/*                                                                                               */
void LibraryModel::filterReady()
{
    QVector<QStringList> result=m_filterWatcher->result();
    if(result.count()>0){
        if(result!=m_results){
            beginResetModel();
            m_results=result;
            endResetModel();

            //            if(m_currentIndex>m_results.size())
            //                m_currentIndex=m_results.size()-1;
            //m_currentIndex=
        }
    }
    else{
        emit filterEmpty();
        m_filter.chop(1);
    }
    emit filterChanged();
}
/*                                                                                               */
QString LibraryModel::getQuery()
{
    //return "SELECT module,name FROM games WHERE title like \"%"+m_filter+"%\" ORDER BY title LIMIT 100";
    return "SELECT module,name FROM games WHERE title like \"%"+m_filter+"%\" ORDER BY title";
}
/*                                                                                               */
void LibraryModel::setCurrentIndex(const int &index)
{
    if(!m_results.isEmpty()){
        if(index<m_results.size()){
            //qDebug() << "Setting current index to " << index << "/" << m_results.size();

            //        if(index > m_results.size())
            //            qDebug() << "This is not possible!!";

            m_currentIndex=index;
            if(m_module!=m_results.at(index).at(0) or m_game!=m_results.at(index).at(1)){
                m_module=m_results.at(index).at(0);
                m_game=m_results.at(index).at(1);
                if(m_timer->isActive())
                    m_timer->stop();
                m_timer->start();
            }
        }
    }
}
/*                                                                                               */
void LibraryModel::timerReady()
{
    m_infoWatcher->setFuture(QtConcurrent::run(this,&LibraryModel::infoThread));
    emit gameSelected(m_module,m_game);
}
/*                                                                                               */
extern void LibraryModel::infoThread()
{
    QString queryString="SELECT title,developer,year,category FROM games WHERE module=\""+m_module+"\" AND name=\""+m_game+"\"";
    if(infoQuery->prepare(queryString)){
        if(infoQuery->exec()){
            if(infoQuery->first()){


                //qDebug() << "InfoQuery:" << infoQuery->size();


                m_title=infoQuery->value(0);
                m_developer=infoQuery->value(1);
                m_year=infoQuery->value(2);
                m_category=infoQuery->value(3);
            }
        }
        else
            qWarning() << "Failed to execute query " << queryString;
    }
    else
        qWarning() << "Couldn't prep q:" << queryString << infoQuery->lastError().text();
}
/*                                                                                               */
void LibraryModel::infoReady()
{
    emit titleChanged(m_title);
    emit developerChanged(m_developer);
    emit yearChanged(m_year);
    emit categoryChanged(m_category);
}
/*                                                                                               */
//void LibraryModel::selectRandomGame()
//{
//    setCurrentIndex(qrand()%m_results.count());
//}
/*                                                                                               */
//void LibraryModel::loadList(const QString &file)
//{
//    QVector<QStringList> r;
//    QFile f(file);
//    if(f.open(QIODevice::ReadOnly)){
//        QString aa=f.readAll();
//        foreach(QString entry,aa.split("\n")){
//            if(!entry.isEmpty() && entry.contains(" "))
//                r.append(entry.split(" "));
//        }
//        f.close();
//    }
//    beginResetModel();
//    m_results=r;
//    endResetModel();
//}
/*                                                                                               */
QHash<int, QByteArray> LibraryModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="Module";
    hash[1]="Name";
    return hash;
}
/*                                                                                              */
QVariant LibraryModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid())
        return m_results.at(index.row()).at(role);
    return QVariant();
}
/*                                                                                               */
LibraryModel::~LibraryModel()
{
    if(filterQuery->isActive())
        filterQuery->finish();
    delete filterQuery;
    QSettings settings(qApp->applicationName(),"Gaming",this);
    settings.beginGroup("Library");
    settings.setValue("Filter",m_filter);
    settings.setValue("CurrentIndex",m_currentIndex);
    settings.endGroup();
}
/*                                                                                               */