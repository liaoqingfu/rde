#include "librarymodel.h"
/*                                                                                               */
LibraryModel::LibraryModel(QObject *parent):Model(parent)
{
    m_title="";
    m_developer="";
    m_year="";
    m_category="";

    m_timer=new QTimer(this);
    m_timer->setInterval(200);
    m_timer->setSingleShot(true);
    connect(m_timer,SIGNAL(timeout()),this,SLOT(timerReady()));

    m_filterWatcher=new QFutureWatcher<QVector<QStringList> >(this);
    connect(m_filterWatcher,SIGNAL(finished()),this,SLOT(filterReady()));

    m_infoWatcher=new QFutureWatcher<void>(this);
    connect(m_infoWatcher,SIGNAL(finished()),this,SLOT(infoReady()));
}
/*                                                                                               */
void LibraryModel::initialize()
{
    QSettings settings(qApp->applicationName(),"Gaming",this);
    settings.beginGroup("Library");
    m_currentIndex=settings.value("CurrentIndex",0).toInt();
    m_filter=settings.value("Filter").toString();
    settings.endGroup();

    QSqlDatabase db=QSqlDatabase::database(ConnectionName);
    filterQuery=new QSqlQuery(db);
    filterQuery->setForwardOnly(true);
    infoQuery=new QSqlQuery(db);
    infoQuery->setForwardOnly(true);
    QStringList tables=db.tables();
    if(!tables.isEmpty()){
        foreach(QString table,tables){
            subqueries << "SELECT '"+table+"' AS module,id,title FROM "+table+" WHERE title like \"%filter%\""; //not elegant
        }
    }
    m_filterWatcher->setFuture(QtConcurrent::run(this,&LibraryModel::filterThread,m_filter));

}
/*                                                                                               */
void LibraryModel::typeKey(const QString &key)
{
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
    m_filter.clear();
    m_results.clear();
    m_filterWatcher->setFuture(QtConcurrent::run(this,&LibraryModel::filterThread,m_filter));
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
    QString q;
    q.append("SELECT * FROM (");
    q.append(subqueries.join(" UNION "));
    q.append(") ORDER BY title");
    q.replace("filter",m_filter);
    q.append(" LIMIT 100");
    return q;
}
/*                                                                                               */
void LibraryModel::setCurrentIndex(const int &index)
{
    //qDebug() << "Selected game " << m_results.at(index).at(0) << m_results.at(index).at(1);

    m_currentIndex=index;
    if(m_timer->isActive())
        m_timer->stop();
    m_timer->start();
}
/*                                                                                               */
void LibraryModel::timerReady()
{
    m_infoWatcher->setFuture(QtConcurrent::run(this,&LibraryModel::infoThread));
    emit gameSelected(module(),game());
}
/*                                                                                               */
extern void LibraryModel::infoThread()
{
    QString queryString="select title,developer,year,category from "+module()+" where id=\""+game()+"\"";
    if(infoQuery->prepare(queryString)){
        if(infoQuery->exec()){
            if(infoQuery->first()){
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
    emit titleChanged();
    emit developerChanged();
    emit yearChanged();
    emit categoryChanged();
}
/*                                                                                               */
void LibraryModel::selectRandomGame()
{
    setCurrentIndex(qrand()%m_results.count());
}
/*                                                                                               */
void LibraryModel::loadList(const QString &file)
{
    QVector<QStringList> r;
    QFile f(file);
    if(f.open(QIODevice::ReadOnly)){
        QString aa=f.readAll();
        foreach(QString entry,aa.split("\n")){
            if(!entry.isEmpty() && entry.contains(" "))
                r.append(entry.split(" "));
        }
        f.close();
    }
    beginResetModel();
    m_results=r;
    endResetModel();
}
/*                                                                                               */
QHash<int, QByteArray> LibraryModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="Module";
    hash[1]="Name";
    return hash;
}
/*                                                                                               */
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
/* EOF                                                                                           */