#ifndef SCREENMODEL_H
#define SCREENMODEL_H
/*                                                                                               */
#include "Model.h"
#include <QGuiApplication>
#include <QScreen>
#include <QFutureWatcher>
#include <QtConcurrentRun>
/*                                                                                               */
class ScreenModel:public Model
{
    Q_OBJECT
    Q_CLASSINFO("Author", "Ralf Van Bogaert")

public:
    ScreenModel();

private:
    enum Roles{Name=0,ModelName=1,Manufacturer=2};
    QHash<int, QByteArray> roleNames() const;
    int rowCount(const QModelIndex &parent) const{Q_UNUSED(parent);return m_screens.size();}
    QVariant data(const QModelIndex &index,int role)const;
    void setCurrentIndex(const int &index);
    QList<QScreen*> m_screens;
    void startScan();
    QList<QScreen*> scan();
    QFutureWatcher<QList<QScreen*> > *m_watcher;

private slots:
    void scanFinished();
};
/*                                                                                               */
#endif