#ifndef ERRORSERVICE_H
#define ERRORSERVICE_H
/*                                                                                               */
#include "service.h"
#include "messagemodel.h"
#include "filereader.h"
//#include <QQmlError>
//#include <QQmlContext>
//#include <stdio.h>
//#include <stdlib.h>
/*                                                                                               */
class ErrorService : public Service
{
    Q_OBJECT
public:
    static ErrorService *instance();

private:
    static ErrorService *m_instance;
    ErrorService();
};
/*                                                                                               */
#endif