#ifndef PROBE_H
#define PROBE_H
/*                                                                                               */
#include <QAudioProbe>
#include <QDebug>
/*                                                                                               */
class Probe : public QAudioProbe
{
    Q_OBJECT
public:
    explicit Probe(QObject *parent);

private slots:
    void audioBufferProbed(QAudioBuffer buffer);
};
/*                                                                                               */
#endif