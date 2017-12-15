#ifndef LIBRARYMODEL_H
#define LIBRARYMODEL_H
/*                                                                                               */
#include "Model.h"
#include "importer.h"
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlQuery>
/*                                                                                               */
class LibraryModel : public Model
{
    Q_OBJECT
    Q_PROPERTY(QString filter READ filter NOTIFY filterChanged)

public:
    LibraryModel();
    ~LibraryModel();

public slots:
    void deleteFile(const QString &file);
    void typeKey(const QString &key);
    void backspaceKey();
    void deleteKey();

private:
    QString m_filter;
    QString filter()const{return m_filter;}

    QString getQuery();
    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return list.count();}
    QList<QStringList> list;
    void startThread();
    QList<QStringList> thread(const QString &newQuery);
    QFutureWatcher<QList<QStringList> > *m_watcher;

private slots:
    void finished();

signals:
    void filterChanged();
};
/*                                                                                               */
#endif