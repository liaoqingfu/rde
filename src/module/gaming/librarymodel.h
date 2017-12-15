#ifndef LIBRARYMODEL_H
#define LIBRARYMODEL_H
/*                                                                                               */
#define ConnectionName "Games"
/*                                                                                               */
#include "Model.h"
#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QKeyEvent>
#include <QTimer>
/*                                                                                               */
class LibraryModel : public Model
{
    Q_OBJECT

    Q_PROPERTY(int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged)
    Q_PROPERTY(int total READ total NOTIFY totalChanged)


    Q_PROPERTY(QString filter READ filter NOTIFY filterChanged)

    Q_PROPERTY(QString module READ module NOTIFY moduleChanged)
    Q_PROPERTY(QString game READ game NOTIFY gameChanged)

    Q_PROPERTY(QVariant title READ title NOTIFY titleChanged)
    Q_PROPERTY(QVariant developer READ developer NOTIFY developerChanged)
    Q_PROPERTY(QVariant year READ year NOTIFY yearChanged)
    Q_PROPERTY(QVariant category READ category NOTIFY categoryChanged)

public:
    LibraryModel();
    QString filter()const{return m_filter;}
    int currentIndex()const{return m_currentIndex;}
    void setCurrentIndex(const int &index);
    QString module()const{return m_module;}
    QString game()const{return m_game;}
    QVariant title()const{return m_title;}
    QVariant developer()const{return m_developer;}
    QVariant year()const{return m_year;}
    QVariant category()const{return m_category;}
    int total()const{return m_total;}
    ~LibraryModel();

public slots:
    void typeKey(const QString &key);
    void backspaceKey();
    void deleteKey();
    //void selectRandomGame();
    //void loadList(const QString &file);

private:
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return m_results.count();}
    QHash<int, QByteArray> roleNames() const;
    QVector<QStringList> m_results;
    int m_currentIndex;
    QString m_filter;
    QSqlQuery *filterQuery;
    QSqlQuery *infoQuery;
    QFutureWatcher<int> *m_initWatcher;
    QFutureWatcher<QVector<QStringList> > *m_filterWatcher;
    QFutureWatcher<void> *m_infoWatcher;
    QTimer *m_timer;
    QVector<QStringList> filterThread(const QString &filter);
    void infoThread();
    QString getQuery();
    QVariant m_title;
    QVariant m_developer;
    QVariant m_year;
    QVariant m_category;
    QString m_module;
    QString m_game;
    int m_total;

private slots:
    void filterReady();
    void infoReady();
    void timerReady();

signals:
    void currentIndexChanged();
    void filterChanged();
    void gameSelected(const QVariant &module,const QVariant &game);
    void titleChanged(QVariant title);
    void developerChanged(QVariant developer);
    void yearChanged(QVariant year);
    void categoryChanged(QVariant category);
    void filterEmpty();
    void moduleChanged(QString module);
    void gameChanged(QString game);
    void totalChanged(int total);
};
/*                                                                                               */
#endif