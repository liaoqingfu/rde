#ifndef VOICEMODEL_H
#define VOICEMODEL_H
/*                                                                                               */
#include "Model.h"
#include <QVoice>
/*                                                                                               */
class VoiceModel:public Model
{
    Q_OBJECT
public:
    explicit VoiceModel();
    static QVector<QVoice> voices;

private:
    enum Roles{Voice,Name,Gender,Age};
    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return voices.count();}
    void setCurrentIndex(const int &index);
};
/*                                                                                               */
#endif