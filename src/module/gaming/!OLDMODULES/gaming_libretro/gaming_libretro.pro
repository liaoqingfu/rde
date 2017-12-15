#--------------------------------------------------------------------------------------------------
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
#--------------------------------------------------------------------------------------------------
QT += quick
CONFIG += qt plugin
TEMPLATE = lib
TARGET = gaming_libretro
DEFINES += GAMING_LIBRETRO_LIBRARY
DESTDIR = ../../modules/gaming
#--------------------------------------------------------------------------------------------------
HEADERS += gaming_libretro_global.h \
    gaming_libretro.h
SOURCES += gaming_libretro.cpp
#--------------------------------------------------------------------------------------------------
RESOURCES += qml/qml.qrc
OTHER_FILES += metadata.json
#--EOF---------------------------------------------------------------------------------------------