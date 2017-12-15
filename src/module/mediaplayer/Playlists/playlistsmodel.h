#ifndef PLAYLISTSMODEL_H
#define PLAYLISTSMODEL_H
/*                                                                                               */
#include "Model.h"
#include <QDir>
#include <QFileInfoList>
#include <QFutureWatcher>
#include <QStandardPaths>
#include <QtConcurrentRun>
/*                                                                                               */
class PlaylistsModel : public Model
{
    Q_OBJECT

public:
    explicit PlaylistsModel(QObject *parent = 0);

private:
    enum Roles{File,Name};
    QHash<int,QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return m_list.size();}

    void startScan();
    QFileInfoList m_list;
    QFileInfoList scan();
    QFutureWatcher<QFileInfoList> *m_watcher;
    QString m_path;

private slots:
    void scanFinished();
};
/*                                                                                               */
#endif