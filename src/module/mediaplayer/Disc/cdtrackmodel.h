#ifndef CDTRACKMODEL_H
#define CDTRACKMODEL_H
#define RippingTool "cdparanoia"
#define ConvertTool "flac"
/*                                                                                               */
#include "Model.h"
#include <QProcess>
#include <QStandardPaths>
#include <QDebug>
//#include <QQuickItem>
#include <QDir>
#include "cdripper.h"
/*                                                                                               */
class CDTrackModel : public Model
{
    Q_OBJECT
public:
    explicit CDTrackModel();

public slots:
    void ripCD();

private:
    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return list.count();}
    QString tempPath;
    QProcess *m_process;
    QStringList list;
    CDRipper *cdRipper;

private slots:
    //void startQuery();
    void finish(const int &exitCode,QProcess::ExitStatus status);
    void error(QProcess::ProcessError error);
    //void readRipOutput();
    //void readRipError();

    //void startedConverting();
    //void finishedConverting(const int &exitCode,QProcess::ExitStatus status);
    //void convertError(QProcess::ProcessError error);
    //void readConvertOutput();
    //void readConvertError();
};
/*                                                                                               */
#endif