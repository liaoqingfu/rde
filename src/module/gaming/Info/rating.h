#ifndef RATING_H
#define RATING_H
/*                                                                                               */
#include <QQuickItem>
#include <QSettings>
//#include <QDebug>
/*                                                                                               */
class Rating : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
public:
    Rating();

public slots:
    void updateRating(const QString &module,const QString &game);

private:
    QMap<QString,int> map;
    int value();
    void setValue(const int & value);

signals:
    void valueChanged();
};
/*                                                                                               */
#endif