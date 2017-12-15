#--[FLAGS]-----------------------------------------------------------------------------------------
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
#--------------------------------------------------------------------------------------------------
QT += quick concurrent sql multimedia
CONFIG += qt plugin
TARGET = Gaming
TEMPLATE = lib
DEFINES += GAMING_LIBRARY
DESTDIR=../../modules
#--------------------------------------------------------------------------------------------------
HEADERS += gaming_global.h \
    gaming.h \
    Model.h \
    window.h \
    game.h \
    librarymodel.h

SOURCES += gaming.cpp \
    window.cpp \
    game.cpp \
    librarymodel.cpp

#--[INCLUDES]--------------------------------------------------------------------------------------
include(Module/Module.pri)
include(Provider/Provider.pri)
include(Music/Music.pri)
include(Info/Info.pri)
#--[RESOURCES]-------------------------------------------------------------------------------------
RESOURCES+=qml/qml.qrc
#--[METADATA]--------------------------------------------------------------------------------------
OTHER_FILES += metadata.json

DISTFILES += \
    ../../qml/Gaming/Window.qml \
    ../../qml/Gaming/BusyWindow.qml \
    ../../qml/Gaming/WikiView.qml \
    ../../qml/Gaming/SystemView.qml \
    ../../qml/Gaming/MusicView.qml \
    ../../qml/Gaming/MusicViewDelegate.qml \
    ../../qml/Gaming/ReviewView.qml \
    ../../qml/Gaming/HistoryView.qml \
    ../../qml/Gaming/GameList.qml \
    ../../qml/Gaming/FilterBox.qml \
    ../../qml/Gaming/InfoPanel.qml \
    ../../qml/Gaming/ArtView.qml \
    ../../qml/Gaming/GameListDelegate.qml \
    ../../qml/Gaming/GameListBar.qml \
    ../../qml/Gaming/CountBox.qml