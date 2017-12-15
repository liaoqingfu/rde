#--[FLAGS]-----------------------------------------------------------------------------------------
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
#--[CONFIG]----------------------------------------------------------------------------------------
QT += dbus gui quick
TEMPLATE = app
DESTDIR = /rde/bin
#--[SOURCES]---------------------------------------------------------------------------------------
HEADERS += Model.h \
    application.h \
    service.h
SOURCES += main.cpp \
    application.cpp \
    service.cpp
#--[INCLUDES]--------------------------------------------------------------------------------------
include(Audio/Audio.pri)
#include(Bluetooth/Bluetooth.pri)
include(Display/Display.pri)
include(Environment/Environment.pri)
include(Module/Module.pri)
include(Network/Network.pri)
include(Screen/Screen.pri)
include(UI/UI.pri)
include(Error/Error.pri)
#--[RESOURCES]-------------------------------------------------------------------------------------
RESOURCES+=qml/qml.qrc
DISTFILES += \
    ../qml/Config/Window.qml \
    ../qml/Error/ErrorPreview.qml \
    ../qml/Error/Window.qml \
    ../qml/Config/AbstractPage.qml \
    ../qml/Config/PageModule.qml \
    ../qml/Config/PageScreens.qml \
    ../qml/Config/PageModules.qml \
    ../qml/Config/ScreenDelegate.qml \
    ../qml/Config/ModuleDelegate.qml \
    ../qml/Config/PageUI.qml \
    ../qml/Config/PageEnvironment.qml \
    ../qml/Config/PageAudio.qml \
    ../qml/Config/AudioDeviceDelegate.qml \
    ../qml/Config/PageGamepad.qml \
    ../qml/Config/GamepadDelegate.qml \
    ../qml/Config/GamepadPreview.qml \
    ../qml/Config/ButtonImage.qml \
    ../qml/Config/DPad.qml \
    ../qml/Gamepad/Gamepad.qml \
    ../qml/Gamepad/LeftThumbstick.qml \
    ../qml/Gamepad/JoystickViewer.qml \
    ../qml/Gamepad/DPad.qml \
    ../qml/Gamepad/ButtonImage.qml \
    ../qml/Gamepad/RightThumbstick.qml \
    ../qml/Config/PageTabBar.qml \
    ../qml/Config/PageTabDelegate.qml \
    ../qml/Config/PageBluetooth.qml \
    ../qml/Config/PageNetwork.qml \
    ../qml/Config/NetworkConfigurationDelegate.qml \
    ../qml/Config/AbstractPage.qml \
    ../qml/Config/AudioDeviceDelegate.qml \
    ../qml/Config/BluetoothDeviceDelegate.qml \
    ../qml/Config/BluetoothDeviceInfoPanel.qml \
    ../qml/Config/GamepadDelegate.qml \
    ../qml/Config/ModuleDelegate.qml \
    ../qml/Config/NetworkConfigurationDelegate.qml \
    ../qml/Config/PageAudio.qml \
    ../qml/Config/PageBluetooth.qml \
    ../qml/Config/PageEnvironment.qml \
    ../qml/Config/PageGamepad.qml \
    ../qml/Config/PageModules.qml \
    ../qml/Config/PageNetwork.qml \
    ../qml/Config/PageScreens.qml \
    ../qml/Config/PageTabBar.qml \
    ../qml/Config/PageTabDelegate.qml \
    ../qml/Config/PageUI.qml \
    ../qml/Config/ScreenDelegate.qml \
    ../qml/Config/Window.qml \
    ../qml/Config/BluetoothDeviceListPanel.qml \
    ../qml/Config/BluetoothDeviceListToolBar.qml \
    ../qml/Config/PageVoice.qml \
    ../qml/Config/VoiceEngineDelegate.qml \
    Background/Background.pri \
    ../qml/Config/PageDisplay.qml \
    ../qml/Config/DisplayDelegate.qml \
    ../qml/Error/MessageDelegate.qml \
    ../qml/Gaming/OLDWindow.qml