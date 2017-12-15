#ifndef CHARACTER_H
#define CHARACTER_H
/*                                                                                               */
#include <QtConcurrentRun>
#include <QFutureWatcher>
#include <QFile>
/*                                                                                               */
class Character : public QObject
{
    Q_OBJECT
public:
    explicit Character(QString id,QObject *parent = nullptr);
    static QVector<Character*> m_characters;

private:
    QString m_id;
    QString m_name;
    double m_speed;
    double m_jumpvelocity;

    QFutureWatcher<QString> *m_watcher;
    QString readThread();
    QString m_txt;

private slots:
    void ready();
};
/*                                                                                               */
#endif