#ifndef INIUI_H
#define INIUI_H
#include "ini.h"
class IniUI : public Ini
{
    Q_OBJECT
    Q_PROPERTY(QString historyPath READ getHistoryPath WRITE setHistoryPath NOTIFY historyPathChanged)
    Q_PROPERTY(QString extraIniPath READ getExtraIniPath WRITE setExtraIniPath NOTIFY extraIniPathChanged)
    Q_PROPERTY(QString cabinetsDir READ getCabinetsDir WRITE setCabinetsDir NOTIFY cabinetsDirChanged)
    Q_PROPERTY(QString cpanelsDir READ getCPanelsDir WRITE setCPanelsDir NOTIFY cPanelsDirChanged)
    Q_PROPERTY(QString pcbsDir READ getPCBsDir WRITE setPCBsDir NOTIFY pcbsDirChanged)
    Q_PROPERTY(QString flyersDir READ getFlyersDir WRITE setFlyersDir NOTIFY flyersDirChanged)
    Q_PROPERTY(QString titlesDir READ getTitlesDir WRITE setTitlesDir NOTIFY titlesDirChanged)
    Q_PROPERTY(QString endsDir READ getEndsDir WRITE setEndsDir NOTIFY endsDirChanged)
    Q_PROPERTY(QString marqueesDir READ getMarqueesDir WRITE setMarqueesDir NOTIFY marqueesDirChanged)
    Q_PROPERTY(QString artPreviewDir READ getArtPreviewDir WRITE setArtPreviewDir NOTIFY artPreviewDirChanged)
    Q_PROPERTY(QString bossesDir READ getBossesDir WRITE setBossesDir NOTIFY bossesDirChanged)
    Q_PROPERTY(QString logosDir READ getLogosDir WRITE setLogosDir NOTIFY logosDirChanged)
    Q_PROPERTY(QString scoresDir READ getScoresDir WRITE setScoresDir NOTIFY scoresDirChanged)
    Q_PROPERTY(QString versusDir READ getVersusDir WRITE setVersusDir NOTIFY versusDirChanged)
    Q_PROPERTY(QString gameOverDir READ getGameOverDir WRITE setGameOverDir NOTIFY gameOverDirChanged)
    Q_PROPERTY(QString howToDir READ getHowToDir WRITE setHowToDir NOTIFY howToDirChanged)
    Q_PROPERTY(QString selectDir READ getSelectDir WRITE setSelectDir NOTIFY selectDirChanged)
    Q_PROPERTY(QString iconsDir READ getIconsDir WRITE setIconsDir NOTIFY iconsDirChanged)
    Q_PROPERTY(QString coverDir READ getCoverDir WRITE setCoverDir NOTIFY coverDirChanged)
    Q_PROPERTY(QString uiPath READ getUIPath WRITE setUIPath NOTIFY uiPathChanged)
    Q_PROPERTY(bool datsEnabled READ getDatsEnabled WRITE setDatsEnabled NOTIFY datsEnabledChanged)
    Q_PROPERTY(bool rememberLast READ getRememberLast WRITE setRememberLast NOTIFY rememberLastChanged)
    Q_PROPERTY(bool enlargeSnaps READ getEnlargeSnaps WRITE setEnlargeSnaps NOTIFY enlargeSnapsChanged)
    Q_PROPERTY(bool forced4x3 READ getForced4x3 WRITE setForced4x3 NOTIFY forced4x3Changed)
    Q_PROPERTY(bool useBackground READ getUseBackground WRITE setUseBackground NOTIFY useBackgroundChanged)
    Q_PROPERTY(bool skipBiosMenu READ getSkipBiosMenu WRITE setSkipBiosMenu NOTIFY skipBiosMenuChanged)
    Q_PROPERTY(bool skipPartsMenu READ getSkipPartsMenu WRITE setSkipPartsMenu NOTIFY skipPartsMenuChanged)
    Q_PROPERTY(QString lastUsedFilter READ getLastUsedFilter WRITE setLastUsedFilter NOTIFY lastUsedFilterChanged)
    Q_PROPERTY(QString lastUsedMachine READ getLastUsedMachine WRITE setLastUsedMachine NOTIFY lastUsedMachineChanged)
    Q_PROPERTY(bool infoAuditEnabled READ getInfoAuditEnabled WRITE setInfoAuditEnabled NOTIFY infoAuditEnabledChanged)
    Q_PROPERTY(double infosTextSize READ getInfosTextSize WRITE setInfosTextSize NOTIFY infosTextSizeChanged)

public:
    explicit IniUI(QObject *parent = 0);

    QString getHistoryPath()const;
    void setHistoryPath(const QString &value);
    QString getExtraIniPath()const;
    void setExtraIniPath(const QString &value);
    QString getCabinetsDir()const;
    void setCabinetsDir(const QString &value);
    QString getCPanelsDir()const;
    void setCPanelsDir(const QString &value);
    QString getPCBsDir()const;
    void setPCBsDir(const QString &value);
    QString getFlyersDir()const;
    void setFlyersDir(const QString &value);
    QString getTitlesDir()const;
    void setTitlesDir(const QString &value);
    QString getEndsDir()const;
    void setEndsDir(const QString &value);
    QString getMarqueesDir()const;
    void setMarqueesDir(const QString &value);
    QString getArtPreviewDir()const;
    void setArtPreviewDir(const QString &value);
    QString getBossesDir()const;
    void setBossesDir(const QString &value);
    QString getLogosDir()const;
    void setLogosDir(const QString &value);
    QString getScoresDir()const;
    void setScoresDir(const QString &value);
    QString getVersusDir()const;
    void setVersusDir(const QString &value);
    QString getGameOverDir()const;
    void setGameOverDir(const QString &value);
    QString getHowToDir()const;
    void setHowToDir(const QString &value);
    QString getSelectDir()const;
    void setSelectDir(const QString &value);
    QString getIconsDir()const;
    void setIconsDir(const QString &value);
    QString getCoverDir()const;
    void setCoverDir(const QString &value);
    QString getUIPath()const;
    void setUIPath(const QString &value);
    bool getDatsEnabled()const;
    void setDatsEnabled(const bool &value);
    bool getRememberLast()const;
    void setRememberLast(const bool &value);
    bool getEnlargeSnaps()const;
    void setEnlargeSnaps(const bool &value);
    bool getForced4x3()const;
    void setForced4x3(const bool &value);
    bool getUseBackground()const;
    void setUseBackground(const bool &value);
    bool getSkipBiosMenu()const;
    void setSkipBiosMenu(const bool &value);
    bool getSkipPartsMenu()const;
    void setSkipPartsMenu(const bool &value);
    QString getLastUsedFilter()const;
    void setLastUsedFilter(const QString &value);
    QString getLastUsedMachine()const;
    void setLastUsedMachine(const QString &value);
    bool getInfoAuditEnabled()const;
    void setInfoAuditEnabled(const bool &value);
    double getInfosTextSize()const;
    void setInfosTextSize(const double &value);

    /*
    //    int getFontRows()const;
    //    void setFontRows(const int &value);
    //    int getHideMainPanel()const;
    //    void setHideMainPanel(const int &value);
    //    QString getUIBorderColor()const;
    //    void setUIBorderColor(const QString &value);
    //    QString getBGColor()const;
    //    void setUIBGColor(const QString &value);
    //    QString getUICloneColor()const;
    //    void setUICloneColor(const QString &value);
    //    QString getUIDipSwitchColor()const;
    //    void setUIDipSwitchColor(const QString &value);
    */





private:
    void readSettingsReady();

signals:
    void historyPathChanged();
    void extraIniPathChanged();
    void cabinetsDirChanged();
    void cPanelsDirChanged();
    void pcbsDirChanged();
    void flyersDirChanged();
    void titlesDirChanged();
    void endsDirChanged();
    void marqueesDirChanged();
    void artPreviewDirChanged();
    void bossesDirChanged();
    void logosDirChanged();
    void scoresDirChanged();
    void versusDirChanged();
    void gameOverDirChanged();
    void howToDirChanged();
    void selectDirChanged();
    void iconsDirChanged();
    void coverDirChanged();
    void uiPathChanged();
    void datsEnabledChanged();
    void rememberLastChanged();
    void enlargeSnapsChanged();
    void forced4x3Changed();
    void useBackgroundChanged();
    void skipBiosMenuChanged();
    void skipPartsMenuChanged();
    void lastUsedFilterChanged();
    void lastUsedMachineChanged();
    void infoAuditEnabledChanged();
    void infosTextSizeChanged();
};
#endif
