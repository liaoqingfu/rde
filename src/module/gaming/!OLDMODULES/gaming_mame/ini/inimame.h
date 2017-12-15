#ifndef INIMAME_H
#define INIMAME_H
#include "ini.h"
class IniMAME : public Ini
{
    Q_OBJECT
    Q_PROPERTY(bool readConfig READ getReadConfig WRITE setReadConfig NOTIFY readConfigChanged)
    Q_PROPERTY(bool writeConfig READ getWriteConfig WRITE setWriteConfig NOTIFY writeConfigChanged)
    Q_PROPERTY(QString rompath READ getRomPath WRITE setRomPath NOTIFY romPathChanged)
    Q_PROPERTY(QString hashPath READ getHashPath WRITE setHashPath NOTIFY hashPathChanged)
    Q_PROPERTY(QString samplePath READ getSamplePath WRITE setSamplePath NOTIFY samplePathChanged)
    Q_PROPERTY(QString artPath READ getArtPath WRITE setArtPath NOTIFY artPathChanged)
    Q_PROPERTY(QString ctrlrPath READ getCtrlrPath WRITE setCtrlrPath NOTIFY ctrlrPathChanged)
    Q_PROPERTY(QString iniPath READ getIniPath WRITE setIniPath NOTIFY iniPathChanged)
    Q_PROPERTY(QString fontPath READ getFontPath WRITE setFontPath NOTIFY fontPathChanged)
    Q_PROPERTY(QString cheatPath READ getCheatPath WRITE setCheatPath NOTIFY cheatPathChanged)
    Q_PROPERTY(QString crosshairPath READ getCrosshairPath WRITE setCrosshairPath NOTIFY crosshairPathChanged)
    Q_PROPERTY(QString cfgDir READ getCfgDir WRITE setCfgDir NOTIFY cfgDirChanged)
    Q_PROPERTY(QString nvramDir READ getNvramDir WRITE setNvramDir NOTIFY nvramDirChanged)
    Q_PROPERTY(QString inputDir READ getInputDir WRITE setInputDir NOTIFY inputDirChanged)
    Q_PROPERTY(QString stateDir READ getStateDir WRITE setStateDir NOTIFY stateDirChanged)
    Q_PROPERTY(QString inputDir READ getInputDir WRITE setInputDir NOTIFY inputDirChanged)
    Q_PROPERTY(QString snapshotDir READ getSnapshotDir WRITE setSnapshotDir NOTIFY snapshotDirChanged)
    Q_PROPERTY(QString diffDir READ getDiffDir WRITE setDiffDir NOTIFY diffDirChanged)
    Q_PROPERTY(QString commentDir READ getCommentDir WRITE setCommentDir NOTIFY commentDirChanged)
    Q_PROPERTY(QString state READ getState WRITE setState NOTIFY stateChanged)
    Q_PROPERTY(bool autoSave READ getAutoSave WRITE setAutoSave NOTIFY autoSaveChanged)
    Q_PROPERTY(QString playback READ getPlayback WRITE setPlayback NOTIFY playbackChanged)
    Q_PROPERTY(QString record READ getRecord WRITE setRecord NOTIFY recordChanged)
    Q_PROPERTY(QString mngWrite READ getMngWrite WRITE setMngWrite NOTIFY mngWriteChanged)
    Q_PROPERTY(QString aviWrite READ getAviWrite WRITE setAviWrite NOTIFY aviWriteChanged)
    Q_PROPERTY(QString wavWrite READ getWavWrite WRITE setAviWrite NOTIFY aviWriteChanged)
    Q_PROPERTY(QString snapName READ getSnapName WRITE setSnapName NOTIFY snapNameChanged)
    Q_PROPERTY(QString snapSize READ getSnapSize WRITE setSnapSize NOTIFY snapSizeChanged)
    Q_PROPERTY(QString snapView READ getSnapView WRITE setSnapView NOTIFY snapViewChanged)
    Q_PROPERTY(bool snapBilinear READ getSnapBilinear WRITE setSnapBilinear NOTIFY snapBilinearChanged)
    Q_PROPERTY(QString stateName READ getStateName WRITE setStateName NOTIFY stateNameChanged)
    Q_PROPERTY(bool burnin READ getBurnin WRITE setBurnin NOTIFY burninChanged)
    Q_PROPERTY(bool autoFrameSkip READ getAutoFrameSkip WRITE setAutoFrameSkip NOTIFY autoFrameSkipChanged)
    Q_PROPERTY(int frameSkip READ getFrameSkip WRITE setFrameSkip NOTIFY frameSkipChanged)
    Q_PROPERTY(int secondsToRun READ getSecondsToRun WRITE setSecondsToRun NOTIFY secondsToRunChanged)
    Q_PROPERTY(bool throttle READ getThrottle WRITE setThrottle NOTIFY throttleChanged)
    Q_PROPERTY(bool sleep READ getSleep WRITE setSleep NOTIFY sleepChanged)
    Q_PROPERTY(int speed READ getSpeed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(bool refreshSpeed READ getRefreshSpeed WRITE setRefreshSpeed NOTIFY refreshSpeedChanged)
    Q_PROPERTY(bool rotate READ getRotate WRITE setRotate NOTIFY rotateChanged)
    Q_PROPERTY(bool ror READ getRor WRITE setRor NOTIFY rorChanged)
    Q_PROPERTY(bool rol READ getRol WRITE setRol NOTIFY rolChanged)
    Q_PROPERTY(bool autoRor READ getAutoRor WRITE setAutoRor NOTIFY autoRorChanged)
    Q_PROPERTY(bool autoRol READ getAutoRol WRITE setAutoRol NOTIFY autoRolChanged)
    Q_PROPERTY(bool flipX READ getFlipX WRITE setFlipX NOTIFY flipXChanged)
    Q_PROPERTY(bool flipY READ getFlipY WRITE setFlipY NOTIFY flipYChanged)
    Q_PROPERTY(bool artworkCrop READ getArtworkCrop WRITE setArtworkCrop NOTIFY artworkCropChanged)
    Q_PROPERTY(bool useBackdrops READ getUseBackdrops WRITE setUseBackdrops NOTIFY useBackdropsChanged)
    Q_PROPERTY(bool useOverlays READ getUseOverlays WRITE setUseOverlays NOTIFY useOverlaysChanged)
    Q_PROPERTY(bool useBezels READ getUseBezels WRITE setUseBezels NOTIFY useBezelsChanged)
    Q_PROPERTY(bool useCPanels READ getUseCPanels WRITE setUseCPanels NOTIFY useCPanelsChanged)
    Q_PROPERTY(bool useMarquees READ getUseMarquees WRITE setUseMarquees NOTIFY useMarqueesChanged)
    Q_PROPERTY(int brightness READ getBrightness WRITE setBrightness NOTIFY brightnessChanged)
    Q_PROPERTY(int contrast READ getContrast WRITE setContrast NOTIFY contrastChanged)
    Q_PROPERTY(int gamma READ getGamma WRITE setGamma NOTIFY gammaChanged)
    Q_PROPERTY(int pauseBrightness READ getPauseBrightness WRITE setPauseBrightness NOTIFY pauseBrightnessChanged)
    Q_PROPERTY(QString effect READ getEffect WRITE setEffect NOTIFY effectChanged)
    Q_PROPERTY(bool antiAlias READ getAntiAlias WRITE setAntiAlias NOTIFY antiAliasChanged)
    Q_PROPERTY(int beam READ getBeam WRITE setBeam NOTIFY beamChanged)
    Q_PROPERTY(QString flicker READ getFlicker WRITE setFlicker NOTIFY flickerChanged)
    Q_PROPERTY(QString sampleRate READ getSampleRate WRITE setSampleRate NOTIFY sampleRateChanged)
    Q_PROPERTY(bool samples READ getSamples WRITE setSamples NOTIFY samplesChanged)
    Q_PROPERTY(int volume READ getVolume WRITE setVolume NOTIFY volumeChanged)
    Q_PROPERTY(bool coinLockout READ getCoinLockout WRITE setCoinLockout NOTIFY coinLockoutChanged)
    Q_PROPERTY(QString ctrlr READ getCtrlr WRITE setCtrlr NOTIFY ctrlrChanged)
    Q_PROPERTY(bool mouse READ getMouse WRITE setMouse NOTIFY mouseChanged)
    Q_PROPERTY(bool joystick READ getJoystick WRITE setJoystick NOTIFY joystickChanged)
    Q_PROPERTY(bool lightgun READ getLightgun WRITE setLightgun NOTIFY lightgunChanged)
    Q_PROPERTY(bool multiKeyboard READ getMultiKeyboard WRITE setMultiKeyboard NOTIFY multiKeyboardChanged)
    Q_PROPERTY(bool multiMouse READ getMultiMouse WRITE setMultiMouse NOTIFY multiMouseChanged)
    Q_PROPERTY(bool steadyKey READ getSteadyKey WRITE setSteadyKey NOTIFY steadyKeyChanged)
    Q_PROPERTY(bool uiActive READ getUiActive WRITE setUiActive NOTIFY uiActiveChanged)
    Q_PROPERTY(bool offScreenReload READ getOffScreenReload WRITE setOffScreenReload NOTIFY offScreenReloadChanged)
    Q_PROPERTY(QString joystickMap READ getJoystickMap WRITE setJoystickMap NOTIFY joystickMapChanged)
    Q_PROPERTY(QString joystickDeadzone READ getJoystickDeadzone WRITE setJoystickDeadzone NOTIFY joystickDeadzoneChanged)
    Q_PROPERTY(QString joystickSaturation READ getJoystickSaturation WRITE setJoystickSaturation NOTIFY joystickSaturationChanged)
    Q_PROPERTY(bool natural READ getNatural WRITE setNatural NOTIFY naturalChanged)
    Q_PROPERTY(bool joystickContradictory READ getJoystickContradictory WRITE setJoystickContradictory NOTIFY joystickContradictoryChanged)
    Q_PROPERTY(int coinImpulse READ getCoinImpulse WRITE setCoinImpulse NOTIFY coinImpulseChanged)
    Q_PROPERTY(QString paddleDevice READ getPaddleDevice WRITE setPaddleDevice NOTIFY paddleDeviceChanged)
    Q_PROPERTY(QString adstickDevice READ getAdstickDevice WRITE setAdstickDevice NOTIFY adstickDeviceChanged)
    Q_PROPERTY(QString pedalDevice READ getPedalDevice WRITE setPedalDevice NOTIFY pedalDeviceChanged)
    Q_PROPERTY(QString dialDevice READ getDialDevice WRITE setDialDevice NOTIFY dialDeviceChanged)
    Q_PROPERTY(QString trackballDevice READ getTrackballDevice WRITE setTrackballDevice NOTIFY trackballDeviceChanged)
    Q_PROPERTY(QString lightgunDevice READ getLightgunDevice WRITE setLightgunDevice NOTIFY lightgunDeviceChanged)
    Q_PROPERTY(QString positionalDevice READ getPositionalDevice WRITE setPositionalDevice NOTIFY positionalDeviceChanged)
    Q_PROPERTY(QString mouseDevice READ getMouseDevice WRITE setMouseDevice NOTIFY mouseDeviceChanged)
    Q_PROPERTY(bool verbose READ getVerbose WRITE setVerbose NOTIFY verboseChanged)
    //Q_PROPERTY(QString log READ getLog WRITE setLog NOTIFY logChanged)
    //Q_PROPERTY(QString osLog READ getOsLog WRITE setOsLog NOTIFY osLogChanged)
    //Q_PROPERTY(QString debug READ getDebug WRITE setDebug NOTIFY debugChanged)
    //Q_PROPERTY(QString updateInPause READ getUpdateInPause WRITE setUpdateInPause NOTIFY updateInPauseChanged)
    //Q_PROPERTY(QString debugScript READ getDebugScript WRITE setDebugScript NOTIFY debugScriptChanged)
    Q_PROPERTY(QString commLocalHost READ getCommLocalHost WRITE setCommLocalHost NOTIFY commLocalHostChanged)
    Q_PROPERTY(QString commLocalPort READ getCommLocalPort WRITE setCommLocalPort NOTIFY commLocalPortChanged)
    Q_PROPERTY(QString commRemoteHost READ getCommRemoteHost WRITE setCommRemoteHost NOTIFY commRemoteHostChanged)
    Q_PROPERTY(QString commRemotePort READ getCommRemotePort WRITE setCommRemotePort NOTIFY commRemotePortChanged)
    Q_PROPERTY(bool drc READ getDrc WRITE setDrc NOTIFY drcChanged)
    Q_PROPERTY(bool drcUseC READ getDrcUseC WRITE setDrcUseC NOTIFY drcUseCChanged)
    Q_PROPERTY(bool drcLogUml READ getDrcLogUml WRITE setDrcLogUml NOTIFY drcLogUMLChanged)
    Q_PROPERTY(bool drcLogNative READ getDrcLogNative WRITE setDrcLogNative NOTIFY drcLogNativeChanged)
    Q_PROPERTY(QString bios READ getBios WRITE setBios NOTIFY biosChanged)
    Q_PROPERTY(QString cheat READ getCheat WRITE setCheat NOTIFY cheatChanged)
    Q_PROPERTY(bool skipGameInfo READ getSkipGameInfo WRITE setSkipGameInfo NOTIFY skipGameInfoChanged)
    Q_PROPERTY(QString uiFont READ getUiFont WRITE setUiFont NOTIFY uiFontChanged)
    Q_PROPERTY(QString ramSize READ getRamSize WRITE setRamSize NOTIFY ramSizeChanged)
    Q_PROPERTY(bool confirmQuit READ getConfirmQuit WRITE setConfirmQuit NOTIFY confirmQuitChanged)
    Q_PROPERTY(bool uiMouse READ getUiMouse WRITE setUiMouse NOTIFY uiMouseChanged)
    Q_PROPERTY(QString autoBootCommand READ getAutoBootCommand WRITE setAutoBootCommand NOTIFY autoBootCommandChanged)
    Q_PROPERTY(int autoBootDelay READ getAutoBootDelay WRITE setAutoBootDelay NOTIFY autoBootDelayChanged)
    Q_PROPERTY(QString autoBootScript READ getAutoBootScript WRITE setAutoBootScript NOTIFY autoBootScriptChanged)
    Q_PROPERTY(bool http READ getHttp WRITE setHttp NOTIFY httpChanged)
    Q_PROPERTY(QString httpPort READ getHttpPort WRITE setHttpPort NOTIFY httpPortChanged)
    Q_PROPERTY(QString httpPath READ getHttpPath WRITE setHttpPath NOTIFY httpPathChanged)
    Q_PROPERTY(bool console READ getConsole WRITE setConsole NOTIFY consoleChanged)
    Q_PROPERTY(bool multiThreading READ getMultiThreading WRITE setMultiThreading NOTIFY multiThreadingChanged)
    Q_PROPERTY(int numProcessors READ getNumProcessors WRITE setNumProcessors NOTIFY numProcessorsChanged)
    Q_PROPERTY(QString video READ getVideo WRITE setVideo NOTIFY videoChanged)
    Q_PROPERTY(int numScreens READ getNumScreens WRITE setNumScreens NOTIFY numScreensChanged)
    Q_PROPERTY(bool window READ getWindow WRITE setWindow NOTIFY windowChanged)
    Q_PROPERTY(bool maximize READ getMaximize WRITE setMaximize NOTIFY maximizeChanged)
    Q_PROPERTY(bool keepAspect READ getKeepAspect WRITE setKeepAspect NOTIFY keepAspectChanged)
    Q_PROPERTY(bool unevenStretch READ getUnevenStretch WRITE setUnevenStretch NOTIFY unevenStretchChanged)
    Q_PROPERTY(bool waitVSync READ getWaitVSync WRITE setWaitVSync NOTIFY waitVSyncChanged)
    Q_PROPERTY(bool syncRefresh READ getSyncRefresh WRITE setSyncRefresh NOTIFY syncRefreshChanged)
    Q_PROPERTY(QString screen READ getScreen WRITE setScreen NOTIFY screenChanged)
    Q_PROPERTY(QString aspect READ getAspect WRITE setAspect NOTIFY aspectChanged)
    Q_PROPERTY(QString resolution READ getResolution WRITE setResolution NOTIFY resolutionChanged)
    Q_PROPERTY(QString view READ getView WRITE setView NOTIFY viewChanged)
    Q_PROPERTY(bool switchRes READ getSwitchRes WRITE setSwitchRes NOTIFY switchResChanged)
    Q_PROPERTY(bool filter READ getFilter WRITE setFilter NOTIFY filterChanged)
    Q_PROPERTY(QString prescale READ getPrescale WRITE setPrescale NOTIFY prescaleChanged)
    Q_PROPERTY(bool glForcePow2Texture READ getGlForcePow2Texture WRITE setGlForcePow2Texture NOTIFY glForcePow2TextureChanged)
    Q_PROPERTY(bool glNoTextureRect READ getGlNoTextureRect WRITE setGlNoTextureRect NOTIFY glNoTextureRectChanged)
    Q_PROPERTY(bool glVbo READ getGlVbo WRITE setGlVbo NOTIFY glVboChanged)
    Q_PROPERTY(bool glPbo READ getGlPbo WRITE setGlPbo NOTIFY glPboChanged)
    Q_PROPERTY(bool glGlsl READ getGlGlsl WRITE setGlGlsl NOTIFY glGlslChanged)
    Q_PROPERTY(QString glGlslFilter READ getGlGlslFilter WRITE setGlGlslFilter NOTIFY glGlslFilterChanged)
    //    Q_PROPERTY(QString glslShaderMame0 READ getGlslShaderMame0 WRITE setGlslShaderMame0 NOTIFY glslShaderMame0Changed)
    //    Q_PROPERTY(QString glslShaderMame1 READ getGlslShaderMame1 WRITE setGlslShaderMame0 NOTIFY glslShaderMame1Changed)
    //    Q_PROPERTY(QString glslShaderMame2 READ getGlslShaderMame2 WRITE setGlslShaderMame0 NOTIFY glslShaderMame2Changed)
    //    Q_PROPERTY(QString glslShaderMame3 READ getGlslShaderMame3 WRITE setGlslShaderMame0 NOTIFY glslShaderMame3Changed)
    //    Q_PROPERTY(QString glslShaderMame4 READ getGlslShaderMame4 WRITE setGlslShaderMame0 NOTIFY glslShaderMame4Changed)
    //    Q_PROPERTY(QString glslShaderMame5 READ getGlslShaderMame5 WRITE setGlslShaderMame0 NOTIFY glslShaderMame5Changed)
    //    Q_PROPERTY(QString glslShaderMame6 READ getGlslShaderMame6 WRITE setGlslShaderMame0 NOTIFY glslShaderMame6Changed)
    //    Q_PROPERTY(QString glslShaderMame7 READ getGlslShaderMame7 WRITE setGlslShaderMame0 NOTIFY glslShaderMame7Changed)
    //    Q_PROPERTY(QString glslShaderMame8 READ getGlslShaderMame8 WRITE setGlslShaderMame0 NOTIFY glslShaderMame8Changed)
    //    Q_PROPERTY(QString glslShaderMame9 READ getGlslShaderMame9 WRITE setGlslShaderMame0 NOTIFY glslShaderMame9Changed)
    //    Q_PROPERTY(QString glslShaderScreen0 READ getGlslShaderScreen0 WRITE setGlslShaderScreen0 NOTIFY glslShaderScreen0Changed)
    //    Q_PROPERTY(QString glslShaderScreen1 READ getGlslShaderScreen1 WRITE setGlslShaderScreen0 NOTIFY glslShaderScreen1Changed)
    //    Q_PROPERTY(QString glslShaderScreen2 READ getGlslShaderScreen2 WRITE setGlslShaderScreen0 NOTIFY glslShaderScreen2Changed)
    //    Q_PROPERTY(QString glslShaderScreen3 READ getGlslShaderScreen3 WRITE setGlslShaderScreen0 NOTIFY glslShaderScreen3Changed)
    //    Q_PROPERTY(QString glslShaderScreen4 READ getGlslShaderScreen4 WRITE setGlslShaderScreen0 NOTIFY glslShaderScreen4Changed)
    //    Q_PROPERTY(QString glslShaderScreen5 READ getGlslShaderScreen5 WRITE setGlslShaderScreen0 NOTIFY glslShaderScreen5Changed)
    //    Q_PROPERTY(QString glslShaderScreen6 READ getGlslShaderScreen6 WRITE setGlslShaderScreen0 NOTIFY glslShaderScreen6Changed)
    //    Q_PROPERTY(QString glslShaderScreen7 READ getGlslShaderScreen7 WRITE setGlslShaderScreen0 NOTIFY glslShaderScreen7Changed)
    //    Q_PROPERTY(QString glslShaderScreen8 READ getGlslShaderScreen8 WRITE setGlslShaderScreen0 NOTIFY glslShaderScreen8Changed)
    //    Q_PROPERTY(QString glslShaderScreen9 READ getGlslShaderScreen9 WRITE setGlslShaderScreen0 NOTIFY glslShaderScreen9Changed)
    Q_PROPERTY(QString sound READ getSound WRITE setSound NOTIFY soundChanged)
    Q_PROPERTY(QString audioLatency READ getAudioLatency WRITE setAudioLatency NOTIFY audioLatencyChanged)
    Q_PROPERTY(bool sdlVideoFPS READ getSDLVideoFPS WRITE setSDLVideoFPS NOTIFY sdlVideoFPSChanged)
    Q_PROPERTY(bool centerH READ getCenterH WRITE setCenterH NOTIFY centerHChanged)
    Q_PROPERTY(bool centerV READ getCenterV WRITE setCenterV NOTIFY centerVChanged)
    Q_PROPERTY(QString scaleMode READ getScaleMode WRITE setScaleMode NOTIFY scaleModeChanged)
    Q_PROPERTY(bool useAllHeads READ getUseAllHeads WRITE setUseAllHeads NOTIFY useAllHeadsChanged)
    Q_PROPERTY(bool keymap READ getKeymap WRITE setKeymap NOTIFY keymapChanged)
    Q_PROPERTY(QString keymapFile READ getKeymapFile WRITE setKeymapFile NOTIFY keymapFileChanged)
    //    Q_PROPERTY(QString joyIndex1 READ getJoyIndex1 WRITE setJoyIndex1 NOTIFY joyIndex1Changed)
    //    Q_PROPERTY(QString joyIndex2 READ getJoyIndex2 WRITE setJoyIndex2 NOTIFY joyIndex2Changed)
    //    Q_PROPERTY(QString joyIndex3 READ getJoyIndex3 WRITE setJoyIndex3 NOTIFY joyIndex3Changed)
    //    Q_PROPERTY(QString joyIndex4 READ getJoyIndex4 WRITE setJoyIndex4 NOTIFY joyIndex4Changed)
    //    Q_PROPERTY(QString joyIndex5 READ getJoyIndex5 WRITE setJoyIndex5 NOTIFY joyIndex5Changed)
    //    Q_PROPERTY(QString joyIndex6 READ getJoyIndex6 WRITE setJoyIndex6 NOTIFY joyIndex6Changed)
    //    Q_PROPERTY(QString joyIndex7 READ getJoyIndex7 WRITE setJoyIndex7 NOTIFY joyIndex7Changed)
    //    Q_PROPERTY(QString joyIndex8 READ getJoyIndex8 WRITE setJoyIndex8 NOTIFY joyIndex8Changed)
    Q_PROPERTY(bool sixAxis READ getSixAxis WRITE setSixAxis NOTIFY sixAxisChanged)
    //    Q_PROPERTY(QString mouseIndex1 READ getMouseIndex1 WRITE setMouseIndex1 NOTIFY mouseIndex1Changed)
    //    Q_PROPERTY(QString mouseIndex2 READ getMouseIndex2 WRITE setMouseIndex2 NOTIFY mouseIndex2Changed)
    //    Q_PROPERTY(QString mouseIndex3 READ getMouseIndex3 WRITE setMouseIndex3 NOTIFY mouseIndex3Changed)
    //    Q_PROPERTY(QString mouseIndex4 READ getMouseIndex4 WRITE setMouseIndex4 NOTIFY mouseIndex4Changed)
    //    Q_PROPERTY(QString mouseIndex5 READ getMouseIndex5 WRITE setMouseIndex5 NOTIFY mouseIndex5Changed)
    //    Q_PROPERTY(QString mouseIndex6 READ getMouseIndex6 WRITE setMouseIndex6 NOTIFY mouseIndex6Changed)
    //    Q_PROPERTY(QString mouseIndex7 READ getMouseIndex7 WRITE setMouseIndex7 NOTIFY mouseIndex7Changed)
    //    Q_PROPERTY(QString mouseIndex8 READ getMouseIndex8 WRITE setMouseIndex8 NOTIFY mouseIndex8Changed)
    //    Q_PROPERTY(QString keybIndex1 READ getKeybIndex1 WRITE setKeybIndex1 NOTIFY keybIndex1Changed)
    //    Q_PROPERTY(QString keybIndex2 READ getKeybIndex2 WRITE setKeybIndex2 NOTIFY keybIndex2Changed)
    //    Q_PROPERTY(QString keybIndex3 READ getKeybIndex3 WRITE setKeybIndex3 NOTIFY keybIndex3Changed)
    //    Q_PROPERTY(QString keybIndex4 READ getKeybIndex4 WRITE setKeybIndex4 NOTIFY keybIndex4Changed)
    //    Q_PROPERTY(QString keybIndex5 READ getKeybIndex5 WRITE setKeybIndex5 NOTIFY keybIndex5Changed)
    //    Q_PROPERTY(QString keybIndex6 READ getKeybIndex6 WRITE setKeybIndex6 NOTIFY keybIndex6Changed)
    //    Q_PROPERTY(QString keybIndex7 READ getKeybIndex7 WRITE setKeybIndex7 NOTIFY keybIndex7Changed)
    //    Q_PROPERTY(QString keybIndex8 READ getKeybIndex8 WRITE setKeybIndex8 NOTIFY keybIndex8Changed)
    Q_PROPERTY(QString videoDriver READ getVideoDriver WRITE setVideoDriver NOTIFY videoDriverChanged)
    Q_PROPERTY(QString renderDriver READ getRenderDriver WRITE setRenderDriver NOTIFY renderDriverChanged)
    Q_PROPERTY(QString audioDriver READ getAudioDriver WRITE setAudioDriver NOTIFY audioDriverChanged)
    Q_PROPERTY(QString glLib READ getGlLib WRITE setGlLib NOTIFY glLibChanged)

public:
    explicit IniMAME(QObject *parent = 0);
    bool getReadConfig()const;
    void setReadConfig(const bool &s);
    bool getWriteConfig()const;
    void setWriteConfig(const bool &s);
    QString getRomPath()const;
    void setRomPath(const QString &s);
    QString getHashPath()const;
    void setHashPath(const QString &s);
    QString getSamplePath()const;
    void setSamplePath(const QString &s);
    QString getArtPath()const;
    void setArtPath(const QString &s);
    QString getCtrlrPath()const;
    void setCtrlrPath(const QString &s);
    QString getIniPath()const;
    void setIniPath(const QString &s);
    QString getFontPath()const;
    void setFontPath(const QString &s);
    QString getCheatPath()const;
    void setCheatPath(const QString &s);
    QString getCrosshairPath()const;
    void setCrosshairPath(const QString &s);
    QString getCfgDir()const;
    void setCfgDir(const QString &s);
    QString getNvramDir()const;
    void setNvramDir(const QString &s);
    QString getInputDir()const;
    void setInputDir(const QString &s);
    QString getStateDir()const;
    void setStateDir(const QString &s);
    QString getSnapshotDir()const;
    void setSnapshotDir(const QString &s);
    QString getDiffDir()const;
    void setDiffDir(const QString &s);
    QString getCommentDir()const;
    void setCommentDir(const QString &s);
    QString getState()const;
    void setState(const QString &s);
    bool getAutoSave()const;
    void setAutoSave(const bool &s);
    QString getPlayback()const;
    void setPlayback(const QString &s);
    QString getRecord()const;
    void setRecord(const QString &s);
    QString getMngWrite()const;
    void setMngWrite(const QString &s);
    QString getAviWrite()const;
    void setAviWrite(const QString &s);
    QString getWavWrite()const;
    void setWavWrite(const QString &s);
    QString getSnapName()const;
    void setSnapName(const QString &s);
    QString getSnapSize()const;
    void setSnapSize(const QString &s);
    QString getSnapView()const;
    void setSnapView(const QString &s);
    bool getSnapBilinear()const;
    void setSnapBilinear(const bool &s);
    QString getStateName()const;
    void setStateName(const QString &s);
    bool getBurnin()const;
    void setBurnin(const bool &s);
    bool getAutoFrameSkip()const;
    void setAutoFrameSkip(const bool &s);
    int getFrameSkip()const;
    void setFrameSkip(const int &s);
    int getSecondsToRun()const;
    void setSecondsToRun(const int &s);
    bool getThrottle()const;
    void setThrottle(const bool &s);
    bool getSleep()const;
    void setSleep(const bool &s);
    int getSpeed()const;
    void setSpeed(const int &s);
    bool getRefreshSpeed()const;
    void setRefreshSpeed(const bool &s);
    bool getRotate()const;
    void setRotate(const bool &s);
    bool getRol()const;
    void setRol(const bool &s);
    bool getRor()const;
    void setRor(const bool &s);
    bool getAutoRol()const;
    void setAutoRol(const bool &s);
    bool getAutoRor()const;
    void setAutoRor(const bool &s);
    bool getFlipX()const;
    void setFlipX(const bool &s);
    bool getFlipY()const;
    void setFlipY(const bool &s);
    bool getArtworkCrop()const;
    void setArtworkCrop(const bool &s);
    bool getUseBackdrops()const;
    void setUseBackdrops(const bool &s);
    bool getUseOverlays()const;
    void setUseOverlays(const bool &s);
    bool getUseBezels()const;
    void setUseBezels(const bool &s);
    bool getUseCPanels()const;
    void setUseCPanels(const bool &s);
    bool getUseMarquees()const;
    void setUseMarquees(const bool &s);
    int getBrightness()const;
    void setBrightness(const int &s);
    int getGamma()const;
    void setGamma(const int &s);
    int getContrast()const;
    void setContrast(const int &s);
    int getPauseBrightness()const;
    void setPauseBrightness(const int &s);
    QString getEffect()const;
    void setEffect(const QString &s);
    bool getAntiAlias()const;
    void setAntiAlias(const bool &s);
    int getBeam()const;
    void setBeam(const int &s);
    QString getFlicker()const;
    void setFlicker(const QString &s);
    QString getSampleRate()const;
    void setSampleRate(const QString &s);
    bool getSamples()const;
    void setSamples(const bool &s);
    int getVolume()const;
    void setVolume(const int &s);
    bool getCoinLockout()const;
    void setCoinLockout(const bool &s);
    QString getCtrlr()const;
    void setCtrlr(const QString &s);
    bool getMouse()const;
    void setMouse(const bool &s);
    bool getJoystick()const;
    void setJoystick(const bool &s);
    bool getLightgun()const;
    void setLightgun(const bool &s);
    bool getMultiKeyboard()const;
    void setMultiKeyboard(const bool &s);
    bool getMultiMouse()const;
    void setMultiMouse(const bool &s);
    bool getSteadyKey()const;
    void setSteadyKey(const bool &s);
    bool getUiActive()const;
    void setUiActive(const bool &s);
    bool getOffScreenReload()const;
    void setOffScreenReload(const bool &s);
    QString getJoystickMap()const;
    void setJoystickMap(const QString &s);
    QString getJoystickDeadzone()const;
    void setJoystickDeadzone(const QString &s);
    QString getJoystickSaturation()const;
    void setJoystickSaturation(const QString &s);
    bool getNatural()const;
    void setNatural(const bool &s);
    bool getJoystickContradictory()const;
    void setJoystickContradictory(const bool &s);
    int getCoinImpulse()const;
    void setCoinImpulse(const int &s);
    QString getPaddleDevice()const;
    void setPaddleDevice(const QString &s);
    QString getAdstickDevice()const;
    void setAdstickDevice(const QString &s);
    QString getPedalDevice()const;
    void setPedalDevice(const QString &s);
    QString getDialDevice()const;
    void setDialDevice(const QString &s);
    QString getTrackballDevice()const;
    void setTrackballDevice(const QString &s);
    QString getLightgunDevice()const;
    void setLightgunDevice(const QString &s);
    QString getPositionalDevice()const;
    void setPositionalDevice(const QString &s);
    QString getMouseDevice()const;
    void setMouseDevice(const QString &s);
    bool getVerbose()const;
    void setVerbose(const bool &s);
    QString getCommLocalHost()const;
    void setCommLocalHost(const QString &s);
    QString getCommLocalPort()const;
    void setCommLocalPort(const QString &s);
    QString getCommRemoteHost()const;
    void setCommRemoteHost(const QString &s);
    QString getCommRemotePort()const;
    void setCommRemotePort(const QString &s);
    bool getDrc()const;
    bool getDrcUseC()const;
    bool getDrcLogUml()const;
    bool getDrcLogNative()const;
    QString getBios()const;
    bool getCheat()const;
    bool getSkipGameInfo()const;
    QString getUiFont()const;
    QString getRamSize()const;
    bool getConfirmQuit()const;
    bool getUiMouse()const;
    QString getAutoBootCommand()const;
    int getAutoBootDelay()const;
    QString getAutoBootScript()const;
    bool getHttp()const;
    QString getHttpPort()const;
    QString getHttpPath()const;
    bool getConsole()const;
    bool getMultiThreading()const;
    int getNumProcessors()const;
    QString getVideo()const;
    int getNumScreens()const;
    bool getWindow()const;
    bool getMaximize()const;
    bool getKeepAspect()const;
    bool getUnevenStretch()const;
    bool getWaitVSync()const;
    bool getSyncRefresh()const;
    QString getScreen()const;
    QString getAspect()const;
    QString getResolution()const;
    QString getView()const;
    bool getSwitchRes()const;
    bool getFilter()const;
    QString getPrescale()const;
    bool getGlForcePow2Texture()const;
    bool getGlNoTextureRect()const;
    bool getGlVbo()const;
    bool getGlPbo()const;
    bool getGlGlsl()const;
    QString getGlGlslFilter()const;
    QString getSound()const;
    QString getAudioLatency()const;
    bool getSDLVideoFPS()const;
    bool getCenterH()const;
    bool getCenterV()const;
    QString getScaleMode()const;
    bool getUseAllHeads()const;
    bool getKeymap()const;
    QString getKeymapFile()const;
    bool getSixAxis()const;
    QString getVideoDriver()const;
    QString getRenderDriver()const;
    QString getAudioDriver()const;
    QString getGlLib()const;



























































































    void setDrc(const bool &s);
    void setDrcUseC(const bool &s);
    void setDrcLogUml(const bool &s);
    void setDrcLogNative(const bool &s);
    void setBios(const QString &s);
    void setCheat(const QString &s);
    void setSkipGameInfo(const bool &s);
    void setUiFont(const QString &s);
    void setRamSize(const QString &s);
    void setConfirmQuit(const bool &s);
    void setUiMouse(const bool &s);
    void setAutoBootCommand(const QString &s);
    void setAutoBootDelay(const int &s);
    void setAutoBootScript(const QString &s);
    void setHttp(const bool &s);
    void setHttpPort(const QString &s);
    void setHttpPath(const QString &s);
    void setConsole(const bool &s);
    void setMultiThreading(const bool &s);
    void setNumProcessors(const int &s);
    void setVideo(const QString &s);
    void setNumScreens(const int &s);
    void setWindow(const bool &s);
    void setMaximize(const bool &s);
    void setKeepAspect(const bool &s);
    void setUnevenStretch(const bool &s);
    void setWaitVSync(const bool &s);
    void setSyncRefresh(const bool &s);
    void setScreen(const QString &s);
    void setAspect(const QString &s);
    void setResolution(const QString &s);
    void setView(const QString &s);
    void setSwitchRes(const bool &s);
    void setFilter(const bool &s);
    void setPrescale(const QString &s);
    void setGlForcePow2Texture(const bool &s);
    void setGlNoTextureRect(const bool &s);
    void setGlVbo(const bool &s);
    void setGlPbo(const bool &s);
    void setGlGlsl(const bool &s);
    void setGlGlslFilter(const QString &s);
    void setSound(const QString &s);
    void setAudioLatency(const QString &s);
    void setSDLVideoFPS(const bool &s);
    void setCenterH(const bool &s);
    void setCenterV(const bool &s);
    void setScaleMode(const QString &s);
    void setUseAllHeads(const bool &s);
    void setKeymap(const bool &s);
    void setKeymapFile(const QString &s);
    void setSixAxis(const bool &s);
    void setVideoDriver(const QString &s);
    void setRenderDriver(const QString &s);
    void setAudioDriver(const QString &s);
    void setGlLib(const QString &s);

private:
    void readSettingsReady();

signals:
    void readConfigChanged();
    void writeConfigChanged();
    void romPathChanged();
    void hashPathChanged();
    void samplePathChanged();
    void artPathChanged();
    void ctrlrPathChanged();
    void iniPathChanged();
    void fontPathChanged();
    void cheatPathChanged();
    void crosshairPathChanged();
    void cfgDirChanged();
    void nvramDirChanged();
    void inputDirChanged();
    void stateDirChanged();
    void snapshotDirChanged();
    void diffDirChanged();
    void commentDirChanged();
    void stateChanged();
    void autoSaveChanged();
    void playbackChanged();
    void recordChanged();
    void mngWriteChanged();
    void aviWriteChanged();
    void wavWriteChanged();
    void snapNameChanged();
    void snapSizeChanged();
    void snapViewChanged();
    void snapBilinearChanged();
    void stateNameChanged();
    void burninChanged();
    void autoFrameSkipChanged();
    void frameSkipChanged();
    void secondsToRunChanged();
    void throttleChanged();
    void sleepChanged();
    void speedChanged();
    void refreshSpeedChanged();
    void rotateChanged();
    void rorChanged();
    void rolChanged();
    void autoRorChanged();
    void autoRolChanged();
    void flipXChanged();
    void flipYChanged();
    void artworkCropChanged();
    void useBackdropsChanged();
    void useOverlaysChanged();
    void useBezelsChanged();
    void useCPanelsChanged();
    void useMarqueesChanged();
    void brightnessChanged();
    void contrastChanged();
    void gammaChanged();
    void pauseBrightnessChanged();
    void effectChanged();
    void beamChanged();
    void flickerChanged();
    void sampleRateChanged();
    void samplesChanged();
    void volumeChanged();
    void coinLockoutChanged();
    void ctrlrChanged();
    void mouseChanged();
    void joystickChanged();
    void lightgunChanged();
    void multiKeyboardChanged();
    void multiMouseChanged();
    void steadyKeyChanged();
    void uiActiveChanged();
    void offScreenReloadChanged();
    void joystickMapChanged();
    void joystickDeadzoneChanged();
    void joystickSaturationChanged();
    void naturalChanged();
    void joystickContradictoryChanged();
    void coinImpulseChanged();
    void paddleDeviceChanged();
    void adstickDeviceChanged();
    void pedalDeviceChanged();
    void dialDeviceChanged();
    void trackballDeviceChanged();
    void lightgunDeviceChanged();
    void positionalDeviceChanged();
    void mouseDeviceChanged();
    void verboseChanged();
    void logChanged();
    void osLogChanged();
    void debugChanged();
    void updateInPauseChanged();
    void debugScriptChanged();
    void sdlVideoFPSChanged();
    void commLocalHostChanged();
    void commLocalPortChanged();
    void commRemoteHostChanged();
    void commRemotePortChanged();
    void antiAliasChanged();
    void drcChanged();
    void drcUseCChanged();
    void drcLogUMLChanged();
    void drcLogNativeChanged();
    void biosChanged();
    void cheatChanged();
    void skipGameInfoChanged();
    void uiFontChanged();
    void ramSizeChanged();
    void confirmQuitChanged();
    void uiMouseChanged();
    void autoBootCommandChanged();
    void autoBootDelayChanged();
    void autoBootScriptChanged();
    void httpChanged();
    void httpPortChanged();
    void httpPathChanged();
    void consoleChanged();
    void multiThreadingChanged();
    void numProcessorsChanged();
    void videoChanged();
    void numScreensChanged();
    void windowChanged();
    void maximizeChanged();
    void keepAspectChanged();
    void unevenStretchChanged();
    void waitVSyncChanged();
    void syncRefreshChanged();
    void screenChanged();
    void aspectChanged();
    void resolutionChanged();
    void viewChanged();
    void switchResChanged();
    void filterChanged();
    void prescaleChanged();
    void glForcePow2TextureChanged();
    void glNoTextureRectChanged();
    void glVboChanged();
    void glPboChanged();
    void glGlslChanged();
    void glGlslFilterChanged();
    void soundChanged();
    void audioLatencyChanged();
    void centerHChanged();
    void centerVChanged();
    void scaleModeChanged();
    void useAllHeadsChanged();
    void keymapChanged();
    void keymapFileChanged();
    void sixAxisChanged();
    void videoDriverChanged();
    void renderDriverChanged();
    void audioDriverChanged();
    void glLibChanged();
};
#endif
