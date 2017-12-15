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
    Q_PROPERTY(int total READ total NOTIFY totalChanged)
    Q_PROPERTY(bool isReady READ isReady NOTIFY isReadyChanged)
    Q_PROPERTY(QString filter READ filter NOTIFY filterChanged)
    Q_PROPERTY(int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged)
    Q_PROPERTY(QVariant module READ module)
    Q_PROPERTY(QVariant game READ game)
    Q_PROPERTY(QVariant title READ title NOTIFY titleChanged)
    Q_PROPERTY(QVariant developer READ developer NOTIFY developerChanged)
    Q_PROPERTY(QVariant year READ year NOTIFY yearChanged)
    Q_PROPERTY(QVariant category READ category NOTIFY categoryChanged)

public:
    LibraryModel(QObject *parent=0);
    void initialize();
    int total()const{return m_total;}
    bool isReady()const{return m_isReady;}
    QString filter()const{return m_filter;}
    int currentIndex()const{return m_currentIndex;}
    void setCurrentIndex(const int &index);
    QString module()const{return m_results.at(m_currentIndex).at(0);}
    QString game()const{return m_results.at(m_currentIndex).at(1);}
    QVariant title()const{return m_title;}
    QVariant developer()const{return m_developer;}
    QVariant year()const{return m_year;}
    QVariant category()const{return m_category;}
    ~LibraryModel();

public slots:
    void typeKey(const QString &key);
    void backspaceKey();
    void deleteKey();
    void selectRandomGame();
    void loadList(const QString &file);

private:
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return m_results.count();}
    QHash<int, QByteArray> roleNames() const;
    QVector<QStringList> m_results;
    int m_total;
    bool m_isReady;
    QString m_filter;
    int m_currentIndex;
    QStringList subqueries;
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

private slots:
    void filterReady();
    void infoReady();
    void timerReady();

signals:
    void currentIndexChanged();
    void developerChanged();
    void filterChanged();
    void gameSelected(const QString &module,const QString &game);
    void isReadyChanged();
    void totalChanged();
    void titleChanged();
    void yearChanged();
    void categoryChanged();
    void filterEmpty();
};
/*                                                                                               */
#endif