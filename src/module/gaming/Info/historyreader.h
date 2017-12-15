#ifndef HISTORYREADER_H
#define HISTORYREADER_H
/*                                                                                               */
#include <QQuickItem>
#include <QFileInfo>
#include <QDebug>
#include <QProcess>
#include <QMimeDatabase>
/*                                                                                               */
class HistoryReader : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text NOTIFY textChanged)

public:
    HistoryReader();
    QString text()const{return m_text;}

public slots:
    void updateHistory(const QString &module,const QString &game);

private:
    QString path;
    QString m_text;
    QProcess *process;

private slots:
    void finished(const int &code,QProcess::ExitStatus status);

signals:
    void textChanged();
};
/*                                                                                               */
#endif