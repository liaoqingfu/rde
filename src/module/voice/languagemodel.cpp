#include "languagemodel.h"
/*                                                                                               */
LanguageModel::LanguageModel():Model()
{
}
/*                                                                                               */
QHash<int, QByteArray> LanguageModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="Locale";
    hash[1]="Name";
    return hash;
}
/*                                                                                               */
QVariant LanguageModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        switch(Roles(role)){
        case Locale:return locales.at(index.row());
        case Name:return locales.at(index.row()).nativeLanguageName();
        }
    }
    return QVariant();
}
/*                                                                                               */
QVector<QLocale> LanguageModel::locales;