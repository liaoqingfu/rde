#ifndef LAUNCHWINDOWITEM_H
#define LAUNCHWINDOWITEM_H
/*                                                                                               */
#include <QQuickItem>
/*                                                                                               */
class LaunchWindowItem:public QQuickItem
{
    Q_OBJECT
public:
    LaunchWindowItem();
    QStringList arguments();
};
/*                                                                                               */
#endif