#ifndef ENGINEMODEL_H
#define ENGINEMODEL_H
/*                                                                                               */
#include "Model.h"
#include <QTextToSpeech>
/*                                                                                               */
class EngineModel : public Model
{
    Q_OBJECT
public:
    explicit EngineModel();

private:
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return m_engines.count();}
    QHash<int, QByteArray> roleNames() const;
    QStringList m_engines;
    void setCurrentIndex(const int &index);
};
/*                                                                                               */
#endif