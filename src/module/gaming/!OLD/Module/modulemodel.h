#ifndef MODULEMODEL_H
#define MODULEMODEL_H
/*                                                                                               */
#include "Model.h"
//#include "modulemanager.h"

#include "Module/module.h"
/*                                                                                               */
class ModuleModel : public Model
{
    Q_OBJECT
    Q_PROPERTY(int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged)
    Q_PROPERTY(int currentRowCount READ currentRowCount NOTIFY currentRowCountChanged)
    Q_PROPERTY(bool allowDeleteData READ allowDeleteData NOTIFY allowDeleteDataChanged)

public:
    ModuleModel();
    int currentIndex()const{return m_currentIndex;}
    int currentRowCount(){return currentModule()->rowCount();}
    void setCurrentIndex(const int &index);
    bool allowDeleteData()const{return m_allowDeleteData;}

public slots:
    void importModuleData(int index);
    void deleteModuleData(){currentModule()->deleteData();}

private:
    enum Roles{IID,Description,IconName,Version,Imported};
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return Module::modules.count();}
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
    int m_currentIndex;

    Module* currentModule(){return Module::modules.at(m_currentIndex);}
    bool m_allowDeleteData;

signals:
    void importBusy();
    void importReady();
    void ready();
    void currentIndexChanged();
    void allowDeleteDataChanged();
    void currentRowCountChanged();
};
/*                                                                                               */
#endif