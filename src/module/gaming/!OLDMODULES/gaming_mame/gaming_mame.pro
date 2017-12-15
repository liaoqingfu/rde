QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
QT += quick
CONFIG += qt plugin
TEMPLATE = lib
DEFINES += GAMING_MAME_LIBRARY
TARGET = gaming_mame
DESTDIR=../../modules/gaming/
HEADERS += gaming_mame_global.h \
    gaming_mame.h \
    compiler.h
SOURCES += gaming_mame.cpp \
    compiler.cpp
OTHER_FILES += metadata.json
RESOURCES += qml/qml.qrc
#include(ini/ini.pri)
DISTFILES += \
    ../../../../../../../home/ralf/.config/Eocene/mame.conf \
    ../../qml/TEMPMAMEConfig/ConfigWindow.qml \
    ../../qml/TEMPMAMEConfig/ProgramInfoPanel.qml \
    ../../qml/TEMPMAMEConfig/ProcessBar.qml
