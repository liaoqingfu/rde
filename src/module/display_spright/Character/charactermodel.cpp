#include "charactermodel.h"
/*                                                                                               */
CharacterModel::CharacterModel(QObject *parent):Model(parent)
{
    m_watcher=new QFutureWatcher<QStringList>(this);
    connect(m_watcher,SIGNAL(finished()),this,SLOT(scanFinished()));
    m_watcher->setFuture(QtConcurrent::run(this,&CharacterModel::scanThread));
}
/*                                                                                               */
extern QStringList CharacterModel::scanThread()
{
    QStringList l;

    QSettings settings;
    settings.beginGroup("Spright");
    m_path=settings.value("Path").toString();
    settings.endGroup();

    QDir dir(m_path);
    dir.setFilter(QDir::Dirs|QDir::NoDotAndDotDot);
    foreach(QString info,dir.entryList()){
        QFileInfo i(m_path+"/"+info+"/"+info+".txt");
        if(i.isReadable())
            l << info;
        else
            qDebug() << i.absoluteFilePath() << " is not readable";
    }
    return l;
}
/*                                                                                               */
void CharacterModel::scanFinished()
{
    beginResetModel();
    m_list=m_watcher->result();
    endResetModel();
}
/*                                                                                               */
QHash<int, QByteArray> CharacterModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="Name";
    return hash;
}
/*                                                                                               */
QVariant CharacterModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        return m_list.at(index.row());
    }
    return QVariant();
}
/*                                                                                               */
void CharacterModel::setCurrentIndex(const int &index)
{
    m_currentIndex=index;

    Character *chara=new Character(m_list.at(index));
}
/*                                                                                               */