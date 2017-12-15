#--------------------------------------------------------------------------------------------------
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
#--------------------------------------------------------------------------------------------------
QT += quick
CONFIG += qt plugin
TEMPLATE = lib
TARGET = gaming_wine
DEFINES += GAMING_WINE_LIBRARY
DESTDIR = ../../modules/gaming
#--------------------------------------------------------------------------------------------------
HEADERS += gaming_wine_global.h \
    gaming_wine.h
SOURCES += gaming_wine.cpp
#--------------------------------------------------------------------------------------------------
RESOURCES += qml/qml.qrc
OTHER_FILES += metadata.json
#--EOF---------------------------------------------------------------------------------------------

DISTFILES += \
    ../../../../../system/data/gamexml/wine.xml