#ifndef TITLESPEECH_H
#define TITLESPEECH_H
/*                                                                                               */
#include <QObject>
#include <QDebug>
/*                                                                                               */
class TitleSpeech : public QObject
{
    Q_OBJECT
public:
    static TitleSpeech *instance();
    QString setTitle(QString title);

private:
    static TitleSpeech *m_instance;
    TitleSpeech();

    QMap<QString,QString> m_phonetics;
};
/*                                                                                               */
#endif