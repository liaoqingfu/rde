#ifndef SCREENSERVICE_H
#define SCREENSERVICE_H
/*                                                                                               */
#include "service.h"
#include "screenmodel.h"
/*                                                                                               */
class ScreenService : public Service
{
    Q_OBJECT
public:
    static ScreenService *instance();
    bool configure(QSettings &settings);

public slots:
    void screenAdded(QScreen *screen);
    void screenRemoved(QScreen *screen);
    void primaryScreenChanged(QScreen *screen);

private:
    ScreenService();
    static ScreenService *m_instance;
};
/*                                                                                               */
#endif