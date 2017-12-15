QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
QT += quick
CONFIG += qt plugin
TEMPLATE = lib
TARGET = gaming_uae
DEFINES += GAMING_UAE_LIBRARY
DESTDIR = ../../modules/gaming
HEADERS += gaming_uae_global.h \
    gaming_uae.h
SOURCES += gaming_uae.cpp
RESOURCES += qml/qml.qrc
OTHER_FILES += metadata.json

DISTFILES += \
    ../../../../../system/data/gamexml/uae.xml