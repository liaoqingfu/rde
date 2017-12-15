#include "voice.h"
/*                                                                                               */
bool Voice::initialize()
{
    QStringList engines=QTextToSpeech::availableEngines();
    if(!engines.isEmpty()){
        m_speech=new QTextToSpeech(QTextToSpeech::availableEngines().at(0),this);
        if(m_speech->state()==QTextToSpeech::Ready){
            connect(m_speech,SIGNAL(stateChanged(QTextToSpeech::State)),this,SLOT(stateChanged(QTextToSpeech::State)));
            connect(m_speech,SIGNAL(localeChanged(QLocale)),this,SLOT(localeChanged(QLocale)));
            connect(m_speech,SIGNAL(voiceChanged(QVoice)),this,SLOT(voiceChanged(QVoice)));

            //connect(m_speech,SIGNAL(volumeChanged(int)),this,SLOT(volumeChanged(int)));
            //connect(m_speech,SIGNAL(pitchChanged(double)),this,SLOT(pitchChanged(double)));
            //connect(m_speech,SIGNAL(rateChanged(double)),this,SLOT(rateChanged(double)));
            //connect(m_speech,SIGNAL(pitchChanged(double)),this,SIGNAL(pitchChanged(double)));
            //connect(m_speech,SIGNAL(rateChanged(double)),this,SIGNAL(rateChanged(double)));

            //qDebug() << "Set volume" << settings->value("volume").toDouble();
            //qDebug() << "Set rate" << settings->value("rate").toDouble();
            //qDebug() << "Set pitch" << settings->value("pitch").toDouble();

            //setVolume(settings->value("volume",1.0).toDouble());
            setRate(settings->value("rate",0.0).toDouble());
            setPitch(settings->value("pitch",0.0).toDouble());
            //setVoice();



            //m_speech->setVoice(m_speech->availableVoices().at(2));
            emit ready();







            //            foreach(QVoice voice,m_speech->availableVoices()){
            //                qDebug() << "Found voice " << voice.name();
            //            }
        }
    }

    VoiceModel::voices=m_speech->availableVoices();
    LanguageModel::locales=m_speech->availableLocales();

    qmlRegisterType<EngineModel>("org.rde.voice",1,0,"EngineModel");
    qmlRegisterType<VoiceModel>("org.rde.voice",1,0,"VoiceModel");
    qmlRegisterType<LanguageModel>("org.rde.voice",1,0,"LanguageModel");
    context->parentContext()->setContextProperty("Voice",this);

    //m_speech->setPitch(-1.0);
    return true;
}
/*                                                                                               */
void Voice::say(QString text)
{
    //    if(!text.isEmpty()){
    //        if(text.contains(" IV"))
    //            text.replace(" IV"," 4");
    //        if(text.contains(" III"))
    //            text.replace(" III"," 3");
    //        if(text.contains(" II"))
    //            text.replace(" II"," 2");
    //    }
    //    else
    //        text="what do you want me to say?";


    m_speech->say(text);
}
/*                                                                                               */
void Voice::stop()
{
    m_speech->stop();
}
/*                                                                                               */
void Voice::localeChanged(QLocale locale)
{
    qDebug() << "Voice :: Locate changed to " << locale.name();
}
/*                                                                                               */
void Voice::stateChanged(QTextToSpeech::State state)
{
    switch(state){
    case QTextToSpeech::Ready:
        emit ready();
        break;
    case QTextToSpeech::Speaking:
        emit speaking();
        break;
    case QTextToSpeech::Paused:
        emit paused();
        break;
    case QTextToSpeech::BackendError:
        emit error();
        break;
    }
}
/*                                                                                               */
void Voice::saveSettings()
{
    //qDebug() << "Saving settings!!!!!";
    settings->setValue("rate",m_speech->rate());
    settings->setValue("pitch",m_speech->pitch());
    settings->setValue("volume",m_speech->volume());
}
/*                                                                                               */
void Voice::voiceChanged(QVoice voice)
{
    qDebug() << "Voice :: Voice changed to " << voice.name();
}
/*                                                                                               */
void Voice::volumeChanged(int volume)
{
    qDebug() << "Voice :: Volume changed to " << volume;
}
/*                                                                                               */