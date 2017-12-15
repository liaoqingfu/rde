#ifndef DESKTOPFILESMODEL_H
#define DESKTOPFILESMODEL_H
/*                                                                                               */
#include "desktopfile.h"
#include <QAbstractItemModel>
#include <QDir>
#include <QDirIterator>
#include <QFileSystemWatcher>
#include <QFutureWatcher>
#include <QtConcurrentRun>
#include <QProcessEnvironment>
#include <QStandardPaths>
/*                                                                                               */
class DesktopFilesModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit DesktopFilesModel(QObject *parent = 0);

public slots:
    void click(const int &index){list.at(index)->click();}

private:
    QHash<int, QByteArray> roleNames() const;
    QModelIndex index(int row,int column,const QModelIndex &parent) const{Q_UNUSED(parent);return createIndex(row,column);}
    QModelIndex parent(const QModelIndex &child)const{Q_UNUSED(child);return QModelIndex();}
    int rowCount(const QModelIndex &parent) const{Q_UNUSED(parent);return list.size();}
    int columnCount(const QModelIndex &parent)const{Q_UNUSED(parent);return 1;}
    QVariant data(const QModelIndex &index,int role)const;
    QFutureWatcher<QVector<DesktopFile*> > *watcher;
    QFileSystemWatcher *dirWatcher;
    QVector<DesktopFile*> list;
    QVector<DesktopFile*> scan();
    QStringList paths;

private slots:
    void directoryChanged(const QString &directory);
    void finished();
};
/*                                                                                               */
#endif