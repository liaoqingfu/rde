#--------------------------------------------------------------------------------------------------
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
#--------------------------------------------------------------------------------------------------
QT += quick concurrent
CONFIG += qt plugin
TARGET = Launcher
TEMPLATE = lib
DEFINES += LAUNCHER_LIBRARY
DESTDIR=../../modules
#--------------------------------------------------------------------------------------------------
HEADERS += launcher_global.h \
    launcher.h \
    desktopfilesmodel.h \
    desktopfile.h
SOURCES += launcher.cpp \
    desktopfilesmodel.cpp \
    desktopfile.cpp
#--------------------------------------------------------------------------------------------------
RESOURCES += qml/qml.qrc
#--------------------------------------------------------------------------------------------------
OTHER_FILES += metadata.json
#--------------------------------------------------------------------------------------------------