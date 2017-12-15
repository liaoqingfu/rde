#ifndef TEXTPREVIEW_H
#define TEXTPREVIEW_H

#include <QQuickItem>
#include <QtConcurrentRun>
#include <QFutureWatcher>
#include <QFileSystemWatcher>
#include <QFile>

class TextPreview : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString file WRITE setFile)
    Q_PROPERTY(QByteArray text READ getText NOTIFY textChanged)

public:
    explicit TextPreview();

private:
    QString file;
    void setFile(const QString &newFile);
    QByteArray text;
    QByteArray getText()const{return text;}
    QByteArray thread(const QString &file);
    QFileSystemWatcher *fileWatcher;
    QFutureWatcher<QByteArray> *watcher;

private slots:
    void finished();
    void fileChanged(const QString &file);

signals:
    void started();
    void textChanged();
};
#endif