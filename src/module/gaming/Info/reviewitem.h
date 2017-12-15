#ifndef REVIEWITEM_H
#define REVIEWITEM_H
/*                                                                                               */
#include <QQuickItem>
#include <QFileInfo>
#include <QFile>
#include <QDir>
#include <QtConcurrentRun>
#include <QFutureWatcher>
/*                                                                                               */
class ReviewItem : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text NOTIFY textChanged)

public:
    ReviewItem();
    QString text()const{return m_text;}

public slots:
    void updateReview(const QString &module,const QString &game);
    void writeText(const QByteArray &text);

private:
    QByteArray m_text;
    QString m_module;
    QString m_game;
    QFutureWatcher<QByteArray> *m_watcher;
    QByteArray readThread(const QString &module,const QString &game);

private slots:
    void finishedReading();

signals:
    void textChanged();
};
/*                                                                                               */
#endif