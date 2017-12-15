#include "fightermodel.h"
/*                                                                                               */
FighterModel::FighterModel(QObject *parent):Model(parent)
{
    m_watcher=new QFutureWatcher<QStringList>(this);
    connect(m_watcher,SIGNAL(finished()),this,SLOT(scanFinished()));
    m_watcher->setFuture(QtConcurrent::run(this,&FighterModel::scanThread));
}
/*                                                                                               */
extern QStringList FighterModel::scanThread()
{
    QStringList l;

    QSettings settings;
    settings.beginGroup("Spright");
    m_path=settings.value("Path").toString();
    settings.endGroup();

    QDir dir(m_path);
    dir.setFilter(QDir::Dirs|QDir::NoDotAndDotDot);
    foreach(QString info,dir.entryList()){
        //QFileInfo i(m_path+"/"+info+"/"+info+".qml");
        QFileInfo i(m_path+"/"+info+"/"+info+".txt");
        if(i.isReadable())
            l << info;
            //m_list << info;
        //qDebug() << "Sprite " << info << " found";
        else
            qDebug() << i.absoluteFilePath() << " is not readable";
    }
    return l;
}
/*                                                                                               */
void FighterModel::scanFinished()
{
    beginResetModel();
    m_list=m_watcher->result();
    endResetModel();
}
/*                                                                                               */
QHash<int, QByteArray> FighterModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="Name";
    return hash;
}
/*                                                                                               */
QVariant FighterModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        return m_list.at(index.row());
    }
    return QVariant();
}
/*                                                                                               */
void FighterModel::setCurrentIndex(const int &index)
{
    m_currentIndex=index;
    Fighter::parseTextFile(m_list.at(index));
}
/*                                                                                               */