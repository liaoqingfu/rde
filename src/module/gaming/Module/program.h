#ifndef PROGRAM_H
#define PROGRAM_H
/*                                                                                               */
#include <QFileSystemWatcher>
#include <QFileInfo>
#include <QStandardPaths>
#include <QDebug>
/*                                                                                               */
class Program : public QObject
{
    Q_OBJECT

public:
    explicit Program(const QString &name,QObject *parent = nullptr);
    QString name()const{return m_name;}

private:
    QFileSystemWatcher *m_fileWatcher;
    QString m_name;

private slots:
    void changed(const QString &file);
};
/*                                                                                               */
#endif