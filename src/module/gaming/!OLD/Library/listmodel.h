#ifndef LISTMODEL_H
#define LISTMODEL_H
/*                                                                                               */
#include "Model.h"
#include <QDir>
#include <QSettings>
/*                                                                                               */
class ListModel : public Model
{
    Q_OBJECT
public:
    explicit ListModel(QObject *parent = 0);

private:

    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return list.count();}
    QHash<int, QByteArray> roleNames() const;
    QFileInfoList list;
    enum Roles{File,Name};
    QFileSystemWatcher *m_watcher;
    QString m_path;

private slots:
    void directoryChanged(const QString &directory);
};
#endif
/*                                                                                               */