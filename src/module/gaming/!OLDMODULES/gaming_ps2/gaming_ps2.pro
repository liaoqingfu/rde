QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
QT += quick
CONFIG += qt plugin
TEMPLATE = lib
TARGET = gaming_ps2
DEFINES += GAMING_PS2_LIBRARY
DESTDIR = ../../modules/gaming
HEADERS += gaming_ps2_global.h \
    gaming_ps2.h
SOURCES += gaming_ps2.cpp
RESOURCES += qml/qml.qrc
OTHER_FILES += metadata.json

DISTFILES += \
    ../../../../../system/data/gamexml/ps2.xml