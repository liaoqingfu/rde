#ifndef MODULEMODEL_H
/*                                                                                               */
#define MODULEMODEL_H
/*                                                                                               */
#include "Model.h"
#include "module.h"
/*                                                                                               */
class ModuleModel : public Model
{
    Q_OBJECT
    Q_CLASSINFO("Author", "Ralf Van Bogaert")
    Q_PROPERTY(QString description READ description NOTIFY descriptionChanged)
    Q_PROPERTY(QString version READ version NOTIFY versionChanged)

public:
    explicit ModuleModel();

public slots:
    void toggle(const int &index);

private:
    enum Roles{IID,IconName,Loaded,Type};
    QHash<int, QByteArray> roleNames() const;
    int rowCount(const QModelIndex &parent) const{Q_UNUSED(parent);return Module::vector.size();}
    QVariant data(const QModelIndex &index,int role)const;
    void setCurrentIndex(const int &index);
    int m_currentIndex;

    QString description()const{return Module::vector.at(m_currentIndex)->description();}
    QString version()const{return Module::vector.at(m_currentIndex)->version();}

signals:
    void descriptionChanged();
    void versionChanged();
};
/*                                                                                               */
#endif