#include "inimame.h"
IniMAME::IniMAME(QObject *parent):Ini("/MAME/ini/mame.ini",parent){}
void IniMAME::readSettingsReady()
{
    emit readConfigChanged();
    emit writeConfigChanged();
    emit romPathChanged();
    emit hashPathChanged();
    emit samplePathChanged();
    emit artPathChanged();
    emit ctrlrPathChanged();
    emit iniPathChanged();
    emit fontPathChanged();
    emit cheatPathChanged();
    emit crosshairPathChanged();
    emit cfgDirChanged();
    emit nvramDirChanged();
    emit inputDirChanged();
    emit stateDirChanged();
    emit snapshotDirChanged();
    emit diffDirChanged();
    emit commentDirChanged();
    emit stateChanged();
    emit autoSaveChanged();
    emit playbackChanged();
    emit recordChanged();
    emit mngWriteChanged();
    emit aviWriteChanged();
    emit wavWriteChanged();
    emit snapNameChanged();
    emit snapSizeChanged();
    emit snapViewChanged();
    emit snapBilinearChanged();
    emit stateNameChanged();
    emit burninChanged();
    emit autoFrameSkipChanged();
    emit frameSkipChanged();
    emit secondsToRunChanged();
    emit throttleChanged();
    emit sleepChanged();
    emit speedChanged();
    emit refreshSpeedChanged();
    emit rotateChanged();
    emit rorChanged();
    emit rolChanged();
    emit autoRorChanged();
    emit autoRolChanged();
    emit flipXChanged();
    emit flipYChanged();
    emit artworkCropChanged();
    emit useBackdropsChanged();
    emit useOverlaysChanged();
    emit useBezelsChanged();
    emit useCPanelsChanged();
    emit useMarqueesChanged();
    emit brightnessChanged();
    emit contrastChanged();
    emit gammaChanged();
    emit effectChanged();
    emit beamChanged();
    emit flickerChanged();
    emit sampleRateChanged();
    emit samplesChanged();
    emit volumeChanged();
    emit coinLockoutChanged();
    emit ctrlrChanged();
    emit mouseChanged();
    emit joystickChanged();
    emit lightgunChanged();
    emit multiKeyboardChanged();
    emit multiMouseChanged();
    emit steadyKeyChanged();
    emit uiActiveChanged();
    emit offScreenReloadChanged();
    emit joystickMapChanged();
    emit joystickDeadzoneChanged();
    emit joystickSaturationChanged();
    emit naturalChanged();
    emit joystickContradictoryChanged();
    emit coinImpulseChanged();
    emit paddleDeviceChanged();
    emit adstickDeviceChanged();
    emit pedalDeviceChanged();
    emit dialDeviceChanged();
    emit trackballDeviceChanged();
    emit lightgunDeviceChanged();
    emit positionalDeviceChanged();
    emit mouseDeviceChanged();
    emit verboseChanged();
    emit logChanged();
    emit osLogChanged();
    emit debugChanged();
    emit updateInPauseChanged();
    emit debugScriptChanged();
    emit sdlVideoFPSChanged();
    emit commLocalHostChanged();
    emit commLocalPortChanged();
    emit commRemoteHostChanged();
    emit commRemotePortChanged();
    emit antiAliasChanged();
    emit drcChanged();
    emit drcUseCChanged();
    emit drcLogUMLChanged();
    emit drcLogNativeChanged();
    emit biosChanged();
    emit cheatChanged();
    emit skipGameInfoChanged();
    emit uiFontChanged();
    emit ramSizeChanged();
    emit confirmQuitChanged();
    emit uiMouseChanged();
    emit autoBootCommandChanged();
    emit autoBootDelayChanged();
    emit autoBootScriptChanged();
    emit httpChanged();
    emit httpPortChanged();
    emit httpPathChanged();
    emit consoleChanged();
    emit multiThreadingChanged();
    emit numProcessorsChanged();
    emit videoChanged();
    emit numScreensChanged();
    emit windowChanged();
    emit maximizeChanged();
    emit keepAspectChanged();
    emit unevenStretchChanged();
    emit waitVSyncChanged();
    emit syncRefreshChanged();
    emit screenChanged();
    emit aspectChanged();
    emit resolutionChanged();
    emit viewChanged();
    emit switchResChanged();
    emit filterChanged();
    emit prescaleChanged();
    emit glForcePow2TextureChanged();
    emit glNoTextureRectChanged();
    emit glVboChanged();
    emit glPboChanged();
    emit glGlslChanged();
    emit glGlslFilterChanged();
    emit soundChanged();
    emit audioLatencyChanged();
    emit centerHChanged();
    emit centerVChanged();
    emit scaleModeChanged();
    emit useAllHeadsChanged();
    emit keymapChanged();
    emit keymapFileChanged();
    emit sixAxisChanged();
    emit videoDriverChanged();
    emit renderDriverChanged();
    emit audioDriverChanged();
    emit glLibChanged();
}

bool IniMAME::getReadConfig()const{return settings.value("readconfig").toBool();}
void IniMAME::setReadConfig(const bool &s){settings.insert("readconfig",s);emit readConfigChanged();}
bool IniMAME::getWriteConfig()const{return settings.value("writeconfig").toBool();}
void IniMAME::setWriteConfig(const bool &s){settings.insert("writeconfig",s);emit writeConfigChanged();}
QString IniMAME::getRomPath()const{return settings.value("rompath").toString();}
void IniMAME::setRomPath(const QString &s){settings.insert("rompath",s);emit romPathChanged();}
QString IniMAME::getHashPath()const{return settings.value("hashpath").toString();}
void IniMAME::setHashPath(const QString &s){settings.insert("hashpath",s);emit hashPathChanged();}
QString IniMAME::getSamplePath()const{return settings.value("samplepath").toString();}
void IniMAME::setSamplePath(const QString &s){settings.insert("samplepath",s);emit samplePathChanged();}
QString IniMAME::getArtPath()const{return settings.value("artpath").toString();}
void IniMAME::setArtPath(const QString &s){settings.insert("artpath",s);emit artPathChanged();}
QString IniMAME::getCtrlrPath()const{return settings.value("ctrlrpath").toString();}
void IniMAME::setCtrlrPath(const QString &s){settings.insert("ctrlrpath",s);emit ctrlrPathChanged();}
QString IniMAME::getIniPath()const{return settings.value("inipath").toString();}
void IniMAME::setIniPath(const QString &s){settings.insert("inipath",s);emit iniPathChanged();}
QString IniMAME::getFontPath()const{return settings.value("fontpath").toString();}
void IniMAME::setFontPath(const QString &s){settings.insert("fontpath",s);emit fontPathChanged();}
QString IniMAME::getCheatPath()const{return settings.value("cheatpath").toString();}
void IniMAME::setCheatPath(const QString &s){settings.insert("cheatpath",s);emit cheatPathChanged();}
QString IniMAME::getCrosshairPath()const{return settings.value("crosshairpath").toString();}
void IniMAME::setCrosshairPath(const QString &s){settings.insert("crosshairpath",s);emit crosshairPathChanged();}
QString IniMAME::getCfgDir()const{return settings.value("cfg_directory").toString();}
void IniMAME::setCfgDir(const QString &s){settings.insert("cfg_directory",s);emit cfgDirChanged();}
QString IniMAME::getNvramDir()const{return settings.value("nvram_directory").toString();}
void IniMAME::setNvramDir(const QString &s){settings.insert("nvram_directory",s);emit nvramDirChanged();}
QString IniMAME::getInputDir()const{return settings.value("input_directory").toString();}
void IniMAME::setInputDir(const QString &s){settings.insert("input_directory",s);emit inputDirChanged();}
QString IniMAME::getStateDir()const{return settings.value("state_directory").toString();}
void IniMAME::setStateDir(const QString &s){settings.insert("state_directory",s);emit stateDirChanged();}
QString IniMAME::getSnapshotDir()const{return settings.value("snapshot_directory").toString();}
void IniMAME::setSnapshotDir(const QString &s){settings.insert("snapshot_directory",s);emit snapshotDirChanged();}
QString IniMAME::getDiffDir()const{return settings.value("diff_directory").toString();}
void IniMAME::setDiffDir(const QString &s){settings.insert("diff_directory",s);emit diffDirChanged();}
QString IniMAME::getCommentDir()const{return settings.value("comment_directory").toString();}
void IniMAME::setCommentDir(const QString &s){settings.insert("comment_directory",s);emit commentDirChanged();}
QString IniMAME::getState()const{return settings.value("state").toString();}
void IniMAME::setState(const QString &s){settings.insert("state",s);emit stateChanged();}
bool IniMAME::getAutoSave()const{return settings.value("autosave").toBool();}
QString IniMAME::getPlayback()const{return settings.value("playback").toString();}
QString IniMAME::getRecord()const{return settings.value("record").toString();}
QString IniMAME::getMngWrite()const{return settings.value("mngwrite").toString();}
QString IniMAME::getAviWrite()const{return settings.value("aviwrite").toString();}
QString IniMAME::getWavWrite()const{return settings.value("wavwrite").toString();}
QString IniMAME::getSnapName()const{return settings.value("snapname").toString();}
QString IniMAME::getSnapSize()const{return settings.value("snapsize").toString();}
QString IniMAME::getSnapView()const{return settings.value("snapview").toString();}
bool IniMAME::getSnapBilinear()const{return settings.value("snapbilinear").toBool();}
QString IniMAME::getStateName()const{return settings.value("statename").toString();}
bool IniMAME::getBurnin()const{return settings.value("burnin").toBool();}
bool IniMAME::getAutoFrameSkip()const{return settings.value("autoframeskip").toBool();}
int IniMAME::getFrameSkip()const{return settings.value("frameskip").toInt();}
int IniMAME::getSecondsToRun()const{return settings.value("secondstorun").toInt();}
bool IniMAME::getThrottle()const{return settings.value("throttle").toBool();}
bool IniMAME::getSleep()const{return settings.value("sleep").toBool();}
int IniMAME::getSpeed()const{return settings.value("speed").toInt();}
bool IniMAME::getRefreshSpeed()const{return settings.value("refreshspeed").toBool();}
bool IniMAME::getRotate()const{return settings.value("rotate").toBool();}
bool IniMAME::getRol()const{return settings.value("rol").toBool();}
bool IniMAME::getRor()const{return settings.value("ror").toBool();}
bool IniMAME::getAutoRol()const{return settings.value("autorol").toBool();}
bool IniMAME::getAutoRor()const{return settings.value("autoror").toBool();}
bool IniMAME::getFlipX()const{return settings.value("flipx").toBool();}
bool IniMAME::getFlipY()const{return settings.value("flipy").toBool();}
bool IniMAME::getArtworkCrop()const{return settings.value("artwork_crop").toBool();}
bool IniMAME::getUseBackdrops()const{return settings.value("use_backdrops").toBool();}
bool IniMAME::getUseOverlays()const{return settings.value("use_overlays").toBool();}
bool IniMAME::getUseBezels()const{return settings.value("use_bezels").toBool();}
bool IniMAME::getUseCPanels()const{return settings.value(" use_cpanels").toBool();}
bool IniMAME::getUseMarquees()const{return settings.value("use_marquees").toBool();}
int IniMAME::getBrightness()const{return settings.value("brightness").toInt();}
int IniMAME::getContrast()const{return settings.value("contrast").toInt();}
int IniMAME::getGamma()const{return settings.value("gamma").toInt();}
int IniMAME::getPauseBrightness()const{return settings.value("pause_brightness").toInt();}
QString IniMAME::getEffect()const{return settings.value("effect").toString();}
bool IniMAME::getAntiAlias()const{return settings.value("antialias").toBool();}
int IniMAME::getBeam()const{return settings.value("beam").toInt();}
QString IniMAME::getFlicker()const{return settings.value("flicker").toString();}
QString IniMAME::getSampleRate()const{return settings.value("samplerate").toString();}
bool IniMAME::getSamples()const{return settings.value("samples").toBool();}
int IniMAME::getVolume()const{return settings.value("volume").toBool();}
bool IniMAME::getCoinLockout()const{return settings.value("coin_lockout").toBool();}
QString IniMAME::getCtrlr()const{return settings.value("ctrlr").toString();}
bool IniMAME::getMouse()const{return settings.value("mouse").toBool();}
bool IniMAME::getJoystick()const{return settings.value("joystick").toBool();}
bool IniMAME::getLightgun()const{return settings.value("lightgun").toBool();}
bool IniMAME::getMultiKeyboard()const{return settings.value("multikeyboard").toBool();}
bool IniMAME::getMultiMouse()const{return settings.value("multimouse").toBool();}
bool IniMAME::getSteadyKey()const{return settings.value("steadykey").toBool();}
bool IniMAME::getUiActive()const{return settings.value("ui_active").toBool();}
bool IniMAME::getOffScreenReload()const{return settings.value("offscreen_reload").toBool();}
QString IniMAME::getJoystickMap()const{return settings.value("joystick_map").toString();}
QString IniMAME::getJoystickDeadzone()const{return settings.value("joystick_deadzone").toString();}
QString IniMAME::getJoystickSaturation()const{return settings.value("joystick_saturation").toString();}
bool IniMAME::getNatural()const{return settings.value("natural").toBool();}
bool IniMAME::getJoystickContradictory()const{return settings.value("joystick_contradictory").toBool();}
int IniMAME::getCoinImpulse()const{return settings.value("coin_impulse").toInt();}
QString IniMAME::getPaddleDevice()const{return settings.value("paddle_device").toString();}
QString IniMAME::getAdstickDevice()const{return settings.value("adstick_device").toString();}
QString IniMAME::getPedalDevice()const{return settings.value("pedal_device").toString();}
QString IniMAME::getDialDevice()const{return settings.value("dial_device").toString();}
QString IniMAME::getTrackballDevice()const{return settings.value("trackball_device").toString();}
QString IniMAME::getLightgunDevice()const{return settings.value("lightgun_device").toString();}
QString IniMAME::getPositionalDevice()const{return settings.value("positional_device").toString();}
QString IniMAME::getMouseDevice()const{return settings.value("mouse_device").toString();}
bool IniMAME::getVerbose()const{return settings.value("verbose").toBool();}
QString IniMAME::getCommLocalHost()const{return settings.value("comm_localhost").toString();}
QString IniMAME::getCommLocalPort()const{return settings.value("comm_localport").toString();}
QString IniMAME::getCommRemoteHost()const{return settings.value("comm_remotehost").toString();}
QString IniMAME::getCommRemotePort()const{return settings.value("comm_remoteport").toString();}
bool IniMAME::getDrc()const{return settings.value("drc").toBool();}
bool IniMAME::getDrcUseC()const{return settings.value("drc_use_c").toBool();}
bool IniMAME::getDrcLogUml()const{return settings.value("drc_log_uml").toBool();}
bool IniMAME::getDrcLogNative()const{return settings.value("drc_log_native").toBool();}
QString IniMAME::getBios()const{return settings.value("bios").toString();}
bool IniMAME::getCheat()const{return settings.value("cheat").toBool();}
bool IniMAME::getSkipGameInfo()const{return settings.value("skip_gameinfo").toBool();}
QString IniMAME::getUiFont()const{return settings.value("uifont").toString();}
QString IniMAME::getRamSize()const{return settings.value("ramsize").toString();}
bool IniMAME::getConfirmQuit()const{return settings.value("confirm_quit").toBool();}
bool IniMAME::getUiMouse()const{return settings.value("ui_mouse").toBool();}
QString IniMAME::getAutoBootCommand()const{return settings.value("autoboot_command").toString();}
int IniMAME::getAutoBootDelay()const{return settings.value("autoboot_delay").toInt();}
QString IniMAME::getAutoBootScript()const{return settings.value("autoboot_script").toString();}
bool IniMAME::getHttp()const{return settings.value("http").toBool();}
QString IniMAME::getHttpPort()const{return settings.value("http_port").toString();}
QString IniMAME::getHttpPath()const{return settings.value("http_path").toString();}
bool IniMAME::getConsole()const{return settings.value("console").toBool();}
bool IniMAME::getMultiThreading()const{return settings.value("multithreading").toBool();}
int IniMAME::getNumProcessors()const{return settings.value("numprocessors").toInt();}
QString IniMAME::getVideo()const{return settings.value("video").toString();}
int IniMAME::getNumScreens()const{return settings.value("numscreens").toInt();}
bool IniMAME::getWindow()const{return settings.value("window").toBool();}
bool IniMAME::getMaximize()const{return settings.value("maximize").toBool();}
bool IniMAME::getKeepAspect()const{return settings.value("keepaspect").toBool();}
bool IniMAME::getUnevenStretch()const{return settings.value("unevenstretch").toBool();}
bool IniMAME::getWaitVSync()const{return settings.value("waitvsync").toBool();}
bool IniMAME::getSyncRefresh()const{return settings.value("syncrefresh").toBool();}
QString IniMAME::getScreen()const{return settings.value("screen").toString();}
QString IniMAME::getAspect()const{return settings.value("aspect").toString();}
QString IniMAME::getResolution()const{return settings.value("resolution").toString();}
QString IniMAME::getView()const{return settings.value("view").toString();}
bool IniMAME::getSwitchRes()const{return settings.value("switchres").toBool();}
bool IniMAME::getFilter()const{return settings.value("filter").toBool();}
QString IniMAME::getPrescale()const{return settings.value("prescale").toString();}
bool IniMAME::getGlForcePow2Texture()const{return settings.value("gl_forcepow2texture").toBool();}
bool IniMAME::getGlNoTextureRect()const{return settings.value("gl_notexturerect").toBool();}
bool IniMAME::getGlVbo()const{return settings.value("gl_vbo").toBool();}
bool IniMAME::getGlPbo()const{return settings.value("gl_pbo").toBool();}
bool IniMAME::getGlGlsl()const{return settings.value("gl_glsl").toBool();}
QString IniMAME::getGlGlslFilter()const{return settings.value("gl_glsl_filter").toString();}
QString IniMAME::getSound()const{return settings.value("sound").toString();}
QString IniMAME::getAudioLatency()const{return settings.value("audio_latency").toString();}
bool IniMAME::getSDLVideoFPS()const{return settings.value("sdlvideofps").toBool();}
bool IniMAME::getCenterH()const{return settings.value("centerh").toBool();}
bool IniMAME::getCenterV()const{return settings.value("centerv").toBool();}
QString IniMAME::getScaleMode()const{return settings.value("scalemode").toString();}
bool IniMAME::getUseAllHeads()const{return settings.value("useallheads").toBool();}
bool IniMAME::getKeymap()const{return settings.value("keymap").toBool();}
QString IniMAME::getKeymapFile()const{return settings.value("keymap_file").toString();}
bool IniMAME::getSixAxis()const{return settings.value("sixaxis").toBool();}
QString IniMAME::getVideoDriver()const{return settings.value("videodriver").toString();}
void IniMAME::setVideoDriver(const QString &s){settings.insert("videodriver",s);emit videoDriverChanged();}
QString IniMAME::getRenderDriver()const{return settings.value("renderdriver").toString();}
void IniMAME::setRenderDriver(const QString &s){settings.insert("renderdriver",s);emit renderDriverChanged(); }
QString IniMAME::getAudioDriver()const{return settings.value("audiodriver").toString();}
void IniMAME::setAudioDriver(const QString &s){settings.insert("audiodriver",s);emit audioDriverChanged();}
QString IniMAME::getGlLib()const{return settings.value("gl_lib").toString();}
void IniMAME::setGlLib(const QString &s){settings.insert("",s);emit glLibChanged();}

void IniMAME::setAutoSave(const bool &s){settings.insert("autosave",s);emit autoSaveChanged();}
void IniMAME::setPlayback(const QString &s){settings.insert("playback",s);emit playbackChanged();}
void IniMAME::setRecord(const QString &s){settings.insert("record",s);emit recordChanged();}
void IniMAME::setMngWrite(const QString &s){settings.insert("mngwrite",s);emit mngWriteChanged();}
void IniMAME::setAviWrite(const QString &s){settings.insert("aviwrite",s);emit aviWriteChanged();}
void IniMAME::setWavWrite(const QString &s){settings.insert("wavwrite",s);emit wavWriteChanged();}
void IniMAME::setSnapName(const QString &s){settings.insert("snapname",s);emit snapNameChanged();}
void IniMAME::setSnapSize(const QString &s){settings.insert("snapsize",s);emit snapSizeChanged();}
void IniMAME::setSnapView(const QString &s){settings.insert("snapview",s);emit snapViewChanged();}
void IniMAME::setSnapBilinear(const bool &s){settings.insert("snapbilinear",s);emit snapBilinearChanged();}
void IniMAME::setStateName(const QString &s){settings.insert("statename",s);emit stateNameChanged();}
void IniMAME::setBurnin(const bool &s){settings.insert("burnin",s);emit burninChanged();}
void IniMAME::setAutoFrameSkip(const bool &s){settings.insert("autoframeskip",s);emit autoFrameSkipChanged();}
void IniMAME::setFrameSkip(const int &s){settings.insert("frameskip",s);emit frameSkipChanged();}
void IniMAME::setSecondsToRun(const int &s){settings.insert("secondstorun",s);emit secondsToRunChanged();}
void IniMAME::setThrottle(const bool &s){settings.insert("throttle",s);emit throttleChanged();}
void IniMAME::setSleep(const bool &s){settings.insert("sleep",s);emit sleepChanged();}
void IniMAME::setSpeed(const int &s){settings.insert("speed",s);emit speedChanged();}
void IniMAME::setRefreshSpeed(const bool &s){settings.insert("refreshspeed",s);emit refreshSpeedChanged();}
void IniMAME::setRotate(const bool &s){settings.insert("rotate",s);emit rotateChanged();}
void IniMAME::setRol(const bool &s){settings.insert("rol",s);emit rolChanged();}
void IniMAME::setRor(const bool &s){settings.insert("ror",s);emit rorChanged();}
void IniMAME::setAutoRol(const bool &s){settings.insert("autorol",s);emit autoRolChanged();}
void IniMAME::setAutoRor(const bool &s){settings.insert("autoror",s);emit autoRorChanged();}
void IniMAME::setFlipX(const bool &s){settings.insert("flipx",s);emit flipXChanged();}
void IniMAME::setFlipY(const bool &s){settings.insert("flipy",s);emit flipYChanged();}
void IniMAME::setArtworkCrop(const bool &s){settings.insert("artwork_crop",s);emit artworkCropChanged();}
void IniMAME::setUseBackdrops(const bool &s){settings.insert("use_backdrops",s);emit useBackdropsChanged();}
void IniMAME::setUseOverlays(const bool &s){settings.insert("use_overlays",s);emit useOverlaysChanged();}
void IniMAME::setUseBezels(const bool &s){settings.insert("use_bezels",s);emit useBezelsChanged();}
void IniMAME::setUseCPanels(const bool &s){settings.insert("use_cpanels",s);emit useCPanelsChanged();}
void IniMAME::setUseMarquees(const bool &s){settings.insert("use_marquees",s);emit useMarqueesChanged();}
void IniMAME::setBrightness(const int &s){settings.insert("brightness",s);emit brightnessChanged();}
void IniMAME::setContrast(const int &s){settings.insert("contrast",s);emit contrastChanged();}
void IniMAME::setGamma(const int &s){settings.insert("gamma",s);emit gammaChanged();}
void IniMAME::setPauseBrightness(const int &s){settings.insert("pauseBrightness",s);emit pauseBrightnessChanged();}
void IniMAME::setEffect(const QString &s){settings.insert("effect",s);emit effectChanged();}
void IniMAME::setAntiAlias(const bool &s){settings.insert("antialias",s);emit antiAliasChanged();}
void IniMAME::setBeam(const int &s){settings.insert("beam",s);emit beamChanged();}
void IniMAME::setFlicker(const QString &s){settings.insert("flicker",s);emit flickerChanged();}
void IniMAME::setSampleRate(const QString &s){settings.insert("samplerate",s);emit sampleRateChanged();}
void IniMAME::setSamples(const bool &s){settings.insert("samples",s);emit samplesChanged();}
void IniMAME::setVolume(const int &s){settings.insert("volume",s);emit volumeChanged();}
void IniMAME::setCoinLockout(const bool &s){settings.insert("coin_lockout",s);emit coinLockoutChanged();}
void IniMAME::setCtrlr(const QString &s){settings.insert("ctrlr",s);emit ctrlrChanged();}
void IniMAME::setMouse(const bool &s){settings.insert("mouse",s);emit mouseChanged();}
void IniMAME::setJoystick(const bool &s){settings.insert("joystick",s);emit joystickChanged();}
void IniMAME::setLightgun(const bool &s){settings.insert("lightgun",s);emit lightgunChanged();}
void IniMAME::setMultiKeyboard(const bool &s){settings.insert("multikeyboard",s);emit multiKeyboardChanged();}
void IniMAME::setMultiMouse(const bool &s){settings.insert("multimouse",s);emit multiMouseChanged();}
void IniMAME::setSteadyKey(const bool &s){settings.insert("steadykey",s);emit steadyKeyChanged();}
void IniMAME::setUiActive(const bool &s){settings.insert("ui_active",s);emit uiActiveChanged();}
void IniMAME::setOffScreenReload(const bool &s){settings.insert("offscreen_reload",s);emit offScreenReloadChanged();}
void IniMAME::setJoystickMap(const QString &s){settings.insert("joystick_map",s);emit joystickMapChanged();}
void IniMAME::setJoystickDeadzone(const QString &s){settings.insert("joystick_deadzone",s);emit joystickDeadzoneChanged();}
void IniMAME::setJoystickSaturation(const QString &s){settings.insert("joystick_saturation",s);emit joystickSaturationChanged();}
void IniMAME::setNatural(const bool &s){settings.insert("natural",s);emit naturalChanged();}
void IniMAME::setJoystickContradictory(const bool &s){settings.insert("joystick_contradictory",s);emit joystickContradictoryChanged();}
void IniMAME::setCoinImpulse(const int &s){settings.insert("coin_impulse",s);emit coinImpulseChanged();}
void IniMAME::setPaddleDevice(const QString &s){settings.insert("paddle_device",s);emit paddleDeviceChanged();}
void IniMAME::setAdstickDevice(const QString &s){settings.insert("adstick_device",s);emit adstickDeviceChanged();}
void IniMAME::setPedalDevice(const QString &s){settings.insert("pedal_device",s);emit pedalDeviceChanged();}
void IniMAME::setDialDevice(const QString &s){settings.insert("dial_device",s);emit dialDeviceChanged();}
void IniMAME::setTrackballDevice(const QString &s){settings.insert("trackball_device",s);emit trackballDeviceChanged();}
void IniMAME::setLightgunDevice(const QString &s){settings.insert("lightgun_device",s);emit lightgunDeviceChanged();}
void IniMAME::setPositionalDevice(const QString &s){settings.insert("positional_device",s);emit positionalDeviceChanged();}
void IniMAME::setMouseDevice(const QString &s){settings.insert("mouse_device",s);emit mouseDeviceChanged();}
void IniMAME::setVerbose(const bool &s){settings.insert("verbose",s);emit verboseChanged();}
void IniMAME::setCommLocalHost(const QString &s){settings.insert("comm_localhost",s);emit commLocalHostChanged();}
void IniMAME::setCommLocalPort(const QString &s){settings.insert("comm_localport",s);emit commLocalPortChanged();}
void IniMAME::setCommRemoteHost(const QString &s){settings.insert("comm_remotehost",s);emit commRemoteHostChanged(); }
void IniMAME::setCommRemotePort(const QString &s){settings.insert("comm_remoteport",s);emit commRemotePortChanged();}
void IniMAME::setDrc(const bool &s){settings.insert("drc",s);emit drcChanged();}
void IniMAME::setDrcUseC(const bool &s){settings.insert("drc_use_c",s);emit drcUseCChanged();}
void IniMAME::setDrcLogUml(const bool &s){settings.insert("drcloguml",s);emit drcLogUMLChanged();}
void IniMAME::setDrcLogNative(const bool &s){settings.insert("drclognative",s);emit drcLogNativeChanged();}
void IniMAME::setBios(const QString &s){settings.insert("bios",s);emit biosChanged();}
void IniMAME::setCheat(const QString &s){settings.insert("cheat",s);emit cheatChanged();}
void IniMAME::setSkipGameInfo(const bool &s){settings.insert("skipgameinfo",s);emit skipGameInfoChanged();}
void IniMAME::setUiFont(const QString &s){settings.insert("uifont",s);emit uiFontChanged();}
void IniMAME::setRamSize(const QString &s){settings.insert("ramsize",s);emit ramSizeChanged();}
void IniMAME::setConfirmQuit(const bool &s){settings.insert("confirm_quit",s);emit confirmQuitChanged();}
void IniMAME::setUiMouse(const bool &s){settings.insert("ui_mouse",s);emit uiMouseChanged();}
void IniMAME::setAutoBootCommand(const QString &s){settings.insert("autoboot_command",s);emit autoBootCommandChanged();}
void IniMAME::setAutoBootDelay(const int &s){settings.insert("autoboot_delay",s);emit autoBootDelayChanged();}
void IniMAME::setAutoBootScript(const QString &s){settings.insert("autoboot_script",s);emit autoBootScriptChanged();}
void IniMAME::setHttp(const bool &s){settings.insert("http",s);emit httpChanged();}
void IniMAME::setHttpPort(const QString &s){settings.insert("http_port",s);emit httpPortChanged();}
void IniMAME::setHttpPath(const QString &s){settings.insert("http_path",s);emit httpPathChanged();}
void IniMAME::setConsole(const bool &s){settings.insert("console",s);emit consoleChanged();}
void IniMAME::setMultiThreading(const bool &s){settings.insert("multithreading",s);emit multiThreadingChanged();}
void IniMAME::setNumProcessors(const int &s){settings.insert("numprocessors",s);emit numProcessorsChanged();}
void IniMAME::setVideo(const QString &s){settings.insert("video",s);emit videoChanged();}
void IniMAME::setNumScreens(const int &s){settings.insert("numscreens",s);emit numScreensChanged();}
void IniMAME::setWindow(const bool &s){settings.insert("window",s);emit windowChanged();}
void IniMAME::setMaximize(const bool &s){settings.insert("maximize",s);emit maximizeChanged();}
void IniMAME::setKeepAspect(const bool &s){settings.insert("keepaspect",s);emit keepAspectChanged();}
void IniMAME::setUnevenStretch(const bool &s){settings.insert("unevenstretch",s);emit unevenStretchChanged();}
void IniMAME::setWaitVSync(const bool &s){settings.insert("waitvsync",s);emit waitVSyncChanged();}
void IniMAME::setSyncRefresh(const bool &s){settings.insert("syncrefresh",s);emit syncRefreshChanged();}
void IniMAME::setScreen(const QString &s){settings.insert("screen",s);emit screenChanged();}
void IniMAME::setAspect(const QString &s){settings.insert("aspect",s);emit aspectChanged();}
void IniMAME::setResolution(const QString &s){settings.insert("resolution",s);emit resolutionChanged();}
void IniMAME::setView(const QString &s){settings.insert("view",s);emit viewChanged();}
void IniMAME::setSwitchRes(const bool &s){settings.insert("switchres",s);emit switchResChanged();}
void IniMAME::setFilter(const bool &s){settings.insert("filter",s);emit filterChanged();}
void IniMAME::setPrescale(const QString &s){settings.insert("prescale",s);emit prescaleChanged();}
void IniMAME::setGlForcePow2Texture(const bool &s){settings.insert("glforcepow2texture",s);emit glForcePow2TextureChanged();}
void IniMAME::setGlNoTextureRect(const bool &s){settings.insert("glnotexturerect",s);emit glNoTextureRectChanged();}
void IniMAME::setGlVbo(const bool &s){settings.insert("gl_vbo",s);emit glVboChanged();}
void IniMAME::setGlPbo(const bool &s){settings.insert("gl_pbo",s);emit glPboChanged();}
void IniMAME::setGlGlsl(const bool &s){settings.insert("gl_glsl",s);emit glGlslChanged();}
void IniMAME::setGlGlslFilter(const QString &s){settings.insert("gl_glsl_filter",s);emit glGlslFilterChanged();}
void IniMAME::setSound(const QString &s){settings.insert("sound",s);emit soundChanged();}
void IniMAME::setAudioLatency(const QString &s){settings.insert("audio_latency",s);emit audioLatencyChanged();}
void IniMAME::setSDLVideoFPS(const bool &s){settings.insert("sdlvideofps",s);emit sdlVideoFPSChanged();}
void IniMAME::setCenterH(const bool &s){settings.insert("centerh",s);emit centerHChanged();}
void IniMAME::setCenterV(const bool &s){settings.insert("centerv",s);emit centerVChanged();}
void IniMAME::setScaleMode(const QString &s){settings.insert("scalemode",s);emit scaleModeChanged();}
void IniMAME::setUseAllHeads(const bool &s){settings.insert("useallheads",s);emit useAllHeadsChanged();}
void IniMAME::setKeymap(const bool &s){settings.insert("keymap",s);emit keymapChanged();}
void IniMAME::setKeymapFile(const QString &s){settings.insert("keymap_file",s);emit keymapFileChanged();}
void IniMAME::setSixAxis(const bool &s){settings.insert("sixaxis",s);emit sixAxisChanged();}




