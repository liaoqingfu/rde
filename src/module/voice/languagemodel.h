#ifndef LANGUAGEMODEL_H
#define LANGUAGEMODEL_H
/*                                                                                               */
#include "Model.h"
#include <QLocale>
/*                                                                                               */
class LanguageModel : public Model
{
    Q_OBJECT
public:
    explicit LanguageModel();
    static QVector<QLocale> locales;

private:
    enum Roles{Locale,Name};
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return locales.count();}
    QHash<int, QByteArray> roleNames() const;
};
/*                                                                                               */
#endif