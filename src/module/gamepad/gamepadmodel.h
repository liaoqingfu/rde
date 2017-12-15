#ifndef GAMEPADMODEL_H
#define GAMEPADMODEL_H
/*                                                                                               */
#include "Model.h"
#include <QGamepadManager>
#include <QGamepad>
#include <QtConcurrentRun>
#include <QFutureWatcher>
/*                                                                                               */
class GamepadModel:public Model
{
    Q_OBJECT
    Q_CLASSINFO("Author", "Ralf Van Bogaert")

public:
    GamepadModel();

private:
    enum Roles{DeviceID,Name,IsConnected};
    QHash<int, QByteArray> roleNames() const;
    int rowCount(const QModelIndex &parent) const{Q_UNUSED(parent);return m_gamepads.size();}
    QVariant data(const QModelIndex &index,int role)const;
    void setCurrentIndex(const int &index);
    QFutureWatcher<QVector<QGamepad*> > *m_watcher;
    void startScan();
    QVector<QGamepad*> scan();
    QVector<QGamepad*> m_gamepads;

private slots:
    void scanFinished();
};
/*                                                                                               */
#endif