#include "iniui.h"
IniUI::IniUI(QObject *parent):Ini("/MAME/ini/ui.ini",parent){}
void IniUI::readSettingsReady()
{
    emit historyPathChanged();
    emit extraIniPathChanged();
    emit cabinetsDirChanged();
    emit cPanelsDirChanged();
    emit pcbsDirChanged();
    emit flyersDirChanged();
    emit titlesDirChanged();
    emit endsDirChanged();
    emit marqueesDirChanged();
    emit artPreviewDirChanged();
    emit bossesDirChanged();
    emit logosDirChanged();
    emit scoresDirChanged();
    emit versusDirChanged();
    emit gameOverDirChanged();
    emit howToDirChanged();
    emit selectDirChanged();
    emit iconsDirChanged();
    emit coverDirChanged();
    emit uiPathChanged();
    emit datsEnabledChanged();
    emit rememberLastChanged();
    emit enlargeSnapsChanged();
    emit forced4x3Changed();
    emit useBackgroundChanged();
    emit skipBiosMenuChanged();
    emit skipPartsMenuChanged();
    emit lastUsedFilterChanged();
    emit lastUsedMachineChanged();
    emit infoAuditEnabledChanged();
    emit infosTextSizeChanged();
}

QString IniUI::getHistoryPath()const{return settings.value("historypath").toString();}
void IniUI::setHistoryPath(const QString &value){settings.insert("historypath",value);}
QString IniUI::getExtraIniPath()const{return settings.value("extrainipath").toString();}
void IniUI::setExtraIniPath(const QString &value){settings.insert("extrainipath",value);}
QString IniUI::getCabinetsDir()const{return settings.value("cabinets_directory").toString();}
void IniUI::setCabinetsDir(const QString &value){settings.insert("cabinets_directory",value);}
QString IniUI::getCPanelsDir()const{return settings.value("cpanels_directory").toString();}
void IniUI::setCPanelsDir(const QString &value){settings.insert("cpanels_directory",value);}
QString IniUI::getPCBsDir()const{return settings.value("pcbs_directory").toString();}
void IniUI::setPCBsDir(const QString &value){settings.insert("pcbs_directory",value);}
QString IniUI::getFlyersDir()const{return settings.value("flyers_directory").toString();}
void IniUI::setFlyersDir(const QString &value){settings.insert("flyers_directory",value);}
QString IniUI::getTitlesDir()const{return settings.value("titles_directory").toString();}
void IniUI::setTitlesDir(const QString &value){settings.insert("titles_directory",value);}
QString IniUI::getEndsDir()const{return settings.value("ends_directory").toString();}
void IniUI::setEndsDir(const QString &value){settings.insert("ends_directory",value);}
QString IniUI::getMarqueesDir()const{return settings.value("marquees_directory").toString();}
void IniUI::setMarqueesDir(const QString &value){settings.insert("marquees_directory",value);}
QString IniUI::getArtPreviewDir()const{return settings.value("artpreview_directory").toString();}
void IniUI::setArtPreviewDir(const QString &value){settings.insert("artpreview_directory",value);}
QString IniUI::getBossesDir()const{return settings.value("bosses_directory").toString();}
void IniUI::setBossesDir(const QString &value){settings.insert("bosses_directory",value);}
QString IniUI::getLogosDir()const{return settings.value("logos_directory").toString();}
void IniUI::setLogosDir(const QString &value){settings.insert("logos_directory",value);}
QString IniUI::getScoresDir()const{return settings.value("scores_directory").toString();}
void IniUI::setScoresDir(const QString &value){settings.insert("scores_directory",value);}
QString IniUI::getVersusDir()const{return settings.value("versus_directory").toString();}
void IniUI::setVersusDir(const QString &value){settings.insert("versus_directory",value);}
QString IniUI::getGameOverDir()const{return settings.value("gameover_directory").toString();}
void IniUI::setGameOverDir(const QString &value){settings.insert("gameover_directory",value);}
QString IniUI::getHowToDir()const{return settings.value("howto_directory").toString();}
void IniUI::setHowToDir(const QString &value){settings.insert("howto_directory",value);}
QString IniUI::getSelectDir()const{return settings.value("select_directory").toString();}
void IniUI::setSelectDir(const QString &value){settings.insert("select_directory",value);}
QString IniUI::getIconsDir()const{return settings.value("icons_directory").toString();}
void IniUI::setIconsDir(const QString &value){settings.insert("icons_directory",value);}
QString IniUI::getCoverDir()const{return settings.value("cover_directory").toString();}
void IniUI::setCoverDir(const QString &value){settings.insert("cover_directory",value);}
QString IniUI::getUIPath()const{return settings.value("ui_path").toString();}
void IniUI::setUIPath(const QString &value){settings.insert("ui_path",value);}
bool IniUI::getDatsEnabled()const{return settings.value("dats_enabled").toBool();}
void IniUI::setDatsEnabled(const bool &value){settings.insert("dats_enabled",value);}
bool IniUI::getRememberLast()const{return settings.value("remember_last").toBool();}
void IniUI::setRememberLast(const bool &value){settings.insert("remember_last",value);}
bool IniUI::getEnlargeSnaps()const{return settings.value("enlarge_snaps").toBool();}
void IniUI::setEnlargeSnaps(const bool &value){settings.insert("enlarge_snaps",value);}
bool IniUI::getForced4x3()const{return settings.value("forced4x3").toBool();}
void IniUI::setForced4x3(const bool &value){settings.insert("forced4x3",value);}
bool IniUI::getUseBackground()const{return settings.value("use_background").toBool();}
void IniUI::setUseBackground(const bool &value){settings.insert("use_background",value);}
bool IniUI::getSkipBiosMenu()const{return settings.value("skip_biosmenu").toBool();}
void IniUI::setSkipBiosMenu(const bool &value){settings.insert("skip_biosmenu",value);}
bool IniUI::getSkipPartsMenu()const{return settings.value("skip_partsmenu").toBool();}
void IniUI::setSkipPartsMenu(const bool &value){settings.insert("skip_partsmenu",value);}
QString IniUI::getLastUsedFilter()const{return settings.value("last_used_filter").toString();}
void IniUI::setLastUsedFilter(const QString &value){settings.insert("last_used_filter",value);}
QString IniUI::getLastUsedMachine()const{return settings.value("last_used_machine").toString();}
void IniUI::setLastUsedMachine(const QString &value){settings.insert("last_used_machine",value);}
bool IniUI::getInfoAuditEnabled()const{return settings.value("info_audit_enabled").toBool();}
void IniUI::setInfoAuditEnabled(const bool &value){settings.insert("info_audit_enabled",value);}
double IniUI::getInfosTextSize()const{settings.value("infos_text_size").toDouble();}
void IniUI::setInfosTextSize(const double &value){settings.insert("infos_text_size",value);}