#ifndef VOICE_H
/*                                                                                               */
#define VOICE_H
/*                                                                                               */
#include "voice_global.h"
#include "/development/rde/src/core/Module/ModuleInterface.h"
#include <QTextToSpeech>
#include "enginemodel.h"
#include "voicemodel.h"
#include "languagemodel.h"
/*                                                                                               */
class Voice: public QObject,public ModuleInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Voice" FILE "metadata.json")
    Q_INTERFACES(ModuleInterface)
    Q_PROPERTY(double rate READ rate WRITE setRate NOTIFY rateChanged)
    Q_PROPERTY(double pitch READ pitch WRITE setPitch NOTIFY pitchChanged)
    Q_PROPERTY(double volume READ volume WRITE setVolume NOTIFY volumeChanged)
    Q_PROPERTY(QLocale locale READ locale WRITE setLocale NOTIFY localeChanged)
    Q_PROPERTY(QVoice voice READ voice WRITE setVoice NOTIFY voiceChanged)

public slots:
    void say(QString text);
    void stop();

public:
    double rate(){return m_speech->rate();}
    void setRate(double rate){m_speech->setRate(rate);}
    double pitch(){return m_speech->pitch();}
    void setPitch(double pitch){m_speech->setPitch(pitch);}
    double volume(){return m_speech->volume();}
    void setVolume(double volume){m_speech->setVolume(volume);}
    QLocale locale(){return m_speech->locale();}
    void setLocale(QLocale locale){m_speech->setLocale(locale);}
    QVoice voice(){return m_speech->voice();}
    void setVoice(QVoice voice){m_speech->setVoice(voice);}

public slots:
    void saveSettings();

private:
    Type type(){return Dock;}
    bool initialize();
    QTextToSpeech *m_speech;

private slots:
    void localeChanged(QLocale locale);
    void voiceChanged(QVoice voice);
    void volumeChanged(int volume);
    void stateChanged(QTextToSpeech::State state);

signals:
    void speaking();
    void ready();
    void paused();
    void error();
    //void pitchChanged(double pitch);
    //void rateChanged(double rate);
    //void volumeChanged(double volume);
    void pitchChanged();
    void rateChanged();
    void volumeChanged();
    void localeChanged();
    void voiceChanged();
};
/*                                                                                               */
#endif