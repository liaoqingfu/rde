#ifndef FIGHTERMODEL_H
#define FIGHTERMODEL_H
/*                                                                                               */
#include "Model.h"
#include <QSettings>
#include <QDir>
#include <QDebug>
#include <QFutureWatcher>
#include <QtConcurrentRun>

#include "Fighter/fighter.h"
/*                                                                                               */
class FighterModel : public Model
{
    Q_OBJECT
    Q_PROPERTY(int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged)

public:
    explicit FighterModel(QObject *parent = nullptr);
    int currentIndex()const{return m_currentIndex;}
    void setCurrentIndex(const int &index);

private:
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return m_list.count();}
    QHash<int, QByteArray> roleNames() const;
    QStringList m_list;
    QString m_path;
    int m_currentIndex;

    QFutureWatcher<QStringList> *m_watcher;
    QStringList scanThread();

private slots:
    void scanFinished();

signals:
    void currentIndexChanged();
};
/*                                                                                               */
#endif