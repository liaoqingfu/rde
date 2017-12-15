#ifndef YEARMODEL_H
#define YEARMODEL_H
/*                                                                                               */
#include <QSortFilterProxyModel>
/*                                                                                               */
class YearModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit YearModel(QObject *parent = 0);
};
/*                                                                                               */
#endif