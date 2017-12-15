#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <QObject>

class WebPage : public QObject{
    Q_OBJECT

public:
    explicit WebPage(const QString &url,QObject *parent = 0);
    QString getURL()const{return url;}
    QString getIcon()const{return icon;}

private:
    QString url;
    QString icon;
};
#endif