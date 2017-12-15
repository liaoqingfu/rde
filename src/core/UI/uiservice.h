#ifndef UISERVICE_H
#define UISERVICE_H
/*                                                                                               */
#include "compositor.h"
#include "service.h"
#include "dock.h"
#include "mainwindow.h"
#include "traymodel.h"
#include "IconProvider.h"
#include "MimeIconProvider.h"
#include "surface.h"
#include <QStandardPaths>
#include <QIcon>
#include <QDir>
/*                                                                                               */
class UIService : public Service
{
    Q_OBJECT
public:
    static UIService *instance();
    bool configure(QSettings &settings);

private:
    static UIService* m_instance;
    UIService();
    Dock *m_dock;
    MainWindow *m_mainWindow;

private slots:
    void availableGeometryChanged(QRect geometry);
};
/*                                                                                               */
#endif