#include "probe.h"
/*                                                                                               */
Probe::Probe(QObject *parent):QAudioProbe(parent)
{
    connect(this,SIGNAL(audioBufferProbed(QAudioBuffer)),this,SLOT(audioBufferProbed(QAudioBuffer)));
}
/*                                                                                               */
void Probe::audioBufferProbed(QAudioBuffer buffer)
{
//    char * data = (char*)buffer.data();
//    quint32 len = buffer.byteCount();

//    qDebug() << "Data: " << data;
//    qDebug() << "Len:" << len;
//    const quint32 channelBytes = m_audioFormat.sampleSize() / 8;
//    const quint32 sampleBytes = m_channelCount * channelBytes;
//    const quint32 numSamples = len / sampleBytes;
//    Q_ASSERT(len % sampleBytes == 0);

//    for (quint32 j = 0; j < m_channelCount; ++j) {
//        const unsigned char *ptr = reinterpret_cast<const unsigned char *>(data);
//        quint32 maxAmpValue = 0;  // Max amplitude value in seen in working channel.
//        quint32 sumAmpValue = 0;  // Sum amplitude values in working channel.
//        ptr += j*channelBytes;
//        for(quint32 i = 0; i < numSamples; ++i) {
//            qint64 value = 0;
//            if(m_audioFormat.sampleSize() == 8 && m_audioFormat.sampleType() == QAudioFormat::UnSignedInt) {
//                value = *reinterpret_cast<const quint8*>(ptr);
//            }
//            else if(m_audioFormat.sampleSize() == 8 && m_audioFormat.sampleType() == QAudioFormat::SignedInt) {
//                value = *reinterpret_cast<const qint8*>(ptr);
//            }
//            else if(m_audioFormat.sampleSize() == 16 && m_audioFormat.sampleType() == QAudioFormat::UnSignedInt) {
//                if(m_audioFormat.byteOrder() == QAudioFormat::LittleEndian)
//                    value = qFromLittleEndian<quint16>(ptr);
//                else
//                    value = qFromBigEndian<quint16>(ptr);
//            }
//            else if(m_audioFormat.sampleSize() == 16 && m_audioFormat.sampleType() == QAudioFormat::SignedInt) {
//                if(m_audioFormat.byteOrder() == QAudioFormat::LittleEndian) {
//                    value = qFromLittleEndian<qint16>(ptr);
//                }
//                else
//                    value = qFromBigEndian<qint16>(ptr);
//            }
//            else if(m_audioFormat.sampleSize() == 32 && m_audioFormat.sampleType() == QAudioFormat::UnSignedInt) {
//                if(m_audioFormat.byteOrder() == QAudioFormat::LittleEndian)
//                    value = qFromLittleEndian<quint32>(ptr);
//                else
//                    value = qFromBigEndian<quint32>(ptr);
//            }
//            else if(m_audioFormat.sampleSize() == 32 && m_audioFormat.sampleType() == QAudioFormat::SignedInt) {
//                if(m_audioFormat.byteOrder() == QAudioFormat::LittleEndian)
//                    value = qFromLittleEndian<qint32>(ptr);
//                else
//                    value = qFromBigEndian<qint32>(ptr);
//            }
//            else if(m_audioFormat.sampleSize() == 32 && m_audioFormat.sampleType() == QAudioFormat::Float) {
//                value = *reinterpret_cast<const float*>(ptr) * 0x80000000; // assumes 0-1.0
//            }
//            sumAmpValue += qAbs(value);
//            maxAmpValue = qMax(quint32(qAbs(value)), maxAmpValue);
//            ptr += sampleBytes;
//        }
//        m_avgAmplitude[j] = qreal(sumAmpValue / (numSamples * m_channelCount)) / m_maxAmplitude;
//        m_expAmplitude[j] = qreal(m_expAmplitude[j]*m_alphaExp + m_avgAmplitude[j]*(1.0-m_alphaExp));
//        m_peakAmplitude[j] = qreal(maxAmpValue) / m_maxAmplitude;
//    }
//    //updateThresholdLevel();
//    //emit update(len);
//    return len;
}
/*                                                                                               */