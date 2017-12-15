#ifndef VOLUMEMODEL_H
#define VOLUMEMODEL_H
/*                                                                                               */
#include "Model.h"
#include "volume.h"
#include <QStorageInfo>
/*                                                                                               */
class VolumeModel : public Model
{
    Q_OBJECT
    Q_PROPERTY(int currentIndex READ getCurrentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged)
public:
    explicit VolumeModel(QObject *parent = 0);
    int getCurrentIndex()const{return currentIndex;}
    void setCurrentIndex(const int &index);

private:

    QVector<Volume*> vector;
    enum Roles{Name,DisplayName,Device,RootPath,BytesTotal,BytesAvailable,Ready};
    QHash<int, QByteArray>roleNames()const;
    QVariant data(const QModelIndex &index,int role)const;
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return vector.count();}
    int currentIndex;

signals:
    void currentIndexChanged();
};
/*                                                                                               */
#endif