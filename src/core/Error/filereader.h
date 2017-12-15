#ifndef FILEREADER_H
#define FILEREADER_H
/*                                                                                               */
#include <QQuickItem>
#include <QFile>
/*                                                                                               */
class FileReader : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString file READ file WRITE setFile NOTIFY fileChanged)
    Q_PROPERTY(QString content READ content NOTIFY contentChanged)
public:
    explicit FileReader();

    QString file()const{return m_file;}
    void setFile(QString file);
    QString content()const{return m_content;}

private:
    QString m_file;
    QString m_content;

signals:
    void fileChanged();
    void contentChanged();
};
/*                                                                                               */
#endif