#ifndef SCREENSAVERMODEL_H
/*                                                                                               */
#define SCREENSAVERMODEL_H
#define Path "/usr/lib/xscreensaver"
/*                                                                                               */
#include "Model.h"
#include <QDir>
#include <QMimeDatabase>
#include <QFileSystemWatcher>
#include "session.h"
/*                                                                                               */
class ScreensaverModel : public Model
{
    Q_OBJECT
public:
    explicit ScreensaverModel(QObject *parent = 0);

private:
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return list.count();}
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
    QFileInfoList list;

    QFileSystemWatcher *fileWatcher;

    void setCurrentIndex(const int &index);

private slots:
    void directoryChanged(const QString &directory);
};
/*                                                                                               */
#endif