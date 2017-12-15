#include "modulemanager.h"
/*                                                                                               */
ModuleManager::ModuleManager()
{
    QString mame=QStandardPaths::findExecutable("mame");
    if(!mame.isEmpty()){
        MAME::instance()->setParent(this);
    }
}
/*                                                                                               */
ModuleManager *ModuleManager::m_instance;
ModuleManager *ModuleManager::instance(){if(!m_instance)m_instance=new ModuleManager();return m_instance;}