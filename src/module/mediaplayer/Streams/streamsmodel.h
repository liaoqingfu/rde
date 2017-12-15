#ifndef STREAMSMODEL_H
#define STREAMSMODEL_H
/*                                                                                               */
#include "Model.h"
#include <QSettings>
#include <QDir>
#include <QStandardPaths>
#include <QtConcurrentRun>
#include <QFutureWatcher>
/*                                                                                               */
class StreamsModel : public Model
{
    Q_OBJECT
public:
    StreamsModel();
private:
    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return m_list.count();}
    QString m_path;
    QVector<QStringList> m_list;
    QVector<QStringList> scan();
    QFutureWatcher<QVector<QStringList> > *m_watcher;
    void startScan();

private slots:
    void scanFinished();
};
/*                                                                                               */
#endif