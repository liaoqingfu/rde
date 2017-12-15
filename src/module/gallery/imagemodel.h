#ifndef IMAGEMODEL_H
#define IMAGEMODEL_H

#include "Model.h"
#include <QFileInfoList>
#include <QDir>
#include <QSettings>
#include <QStandardPaths>

class ImageModel:public Model
{
    Q_OBJECT
    Q_PROPERTY(QString path READ getPath NOTIFY pathChanged)

public:
    ImageModel();

private:
    enum Roles{FilePath=257,FileName=258};
    QFileInfoList list;
    QHash<int, QByteArray>roleNames()const;
    QVariant data(const QModelIndex &index,int role)const;
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return list.count();}
    QString path;
    QString getPath()const{return path;}

signals:
    void pathChanged();
};
#endif