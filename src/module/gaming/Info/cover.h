#ifndef COVER_H
#define COVER_H
/*                                                                                               */
#include <QQuickItem>
#include <QFileInfo>
/*                                                                                               */
class Cover : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString file READ file NOTIFY fileChanged)
public:
    Cover();
    QString file()const{return m_file;}
public slots:
    void setItems(QQuickItem *imageA,QQuickItem *imageB);
    void updateCover(const QString &module,const QString &game);

private:
    QString m_file;
    QQuickItem *m_imageA;
    QQuickItem *m_imageB;

    QString findCover(const QString &module,const QString &game);

signals:
    void fileChanged();
};
/*                                                                                               */
#endif