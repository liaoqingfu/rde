#ifndef AUDIODEVICEMODEL_H
#define AUDIODEVICEMODEL_H
/*                                                                                               */
#include "Model.h"
#include <QFutureWatcher>
#include <QtConcurrentRun>
#include <QAudioDeviceInfo>
/*                                                                                               */
class AudioDeviceModel : public Model
{
    Q_OBJECT
public:
    explicit AudioDeviceModel(QAudio::Mode mode);
    virtual ~AudioDeviceModel(){}

private:
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return m_list.count();}
    QList<QAudioDeviceInfo> m_list;
    QList<QAudioDeviceInfo> scan(QAudio::Mode mode);
    QFutureWatcher<QList<QAudioDeviceInfo> > *m_watcher;

private slots:
    void scanFinished();
};
/*                                                                                               */
#endif