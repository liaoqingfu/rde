#include "titlespeech.h"
/*                                                                                               */
TitleSpeech::TitleSpeech()
{
    m_phonetics.insert("Raiden","rye den");
}
/*                                                                                               */
QString TitleSpeech::setTitle(QString title)
{
    //qDebug() << "From:" << title;




    foreach(QString key,m_phonetics.keys()){
        //qDebug() << "Key" << key;
        if(title.contains(key))
            title.replace(key,m_phonetics.value(key));
    }

    //qDebug() << "To:" << title;
    return title;
}
/*                                                                                               */
TitleSpeech *TitleSpeech::m_instance;
TitleSpeech *TitleSpeech::instance(){if(!m_instance)m_instance=new TitleSpeech();return m_instance;}