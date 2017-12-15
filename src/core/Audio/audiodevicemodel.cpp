#include "audiodevicemodel.h"
/*                                                                                               */
AudioDeviceModel::AudioDeviceModel(QAudio::Mode mode):Model()
{
    m_watcher=new QFutureWatcher<QList<QAudioDeviceInfo> >(this);
    connect(m_watcher,SIGNAL(finished()),this,SLOT(scanFinished()));
    m_watcher->setFuture(QtConcurrent::run(this,&AudioDeviceModel::scan,mode));
}
/*                                                                                               */
QVariant AudioDeviceModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role)
    if(index.isValid()){
        return m_list.at(index.row()).deviceName();
    }
    return QVariant();
}
/*                                                                                               */
QHash<int, QByteArray> AudioDeviceModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="DeviceName";
    return hash;
}
/*                                                                                               */
extern QList<QAudioDeviceInfo> AudioDeviceModel::scan(QAudio::Mode mode)
{
    return QAudioDeviceInfo::availableDevices(mode);
}
/*                                                                                               */
void AudioDeviceModel::scanFinished()
{
    beginResetModel();
    m_list=m_watcher->result();
    endResetModel();
    m_watcher->deleteLater();
}
/*                                                                                               */