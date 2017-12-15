#ifndef IMPORTER_H
#define IMPORTER_H
/*                                                                                               */
#include "Module/module.h"

/*                                                                                               */
class Importer : public QObject
{
    Q_OBJECT
public:
    explicit Importer(QVector<Module*> modules,QObject *parent = nullptr);

private:
    QVector<Module*> m_modules;
    int m_index;
    QFutureWatcher<QStringList> *m_importWatcher;
    QStringList import();

private slots:
    void finished();
};
/*                                                                                               */
#endif