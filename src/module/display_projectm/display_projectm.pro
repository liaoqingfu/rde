#--[FLAGS]-----------------------------------------------------------------------------------------
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
#--------------------------------------------------------------------------------------------------
QT += quick
CONFIG += qt plugin
TEMPLATE = lib
TARGET = display_projectm
DEFINES += DISPLAY_PROJECTM_LIBRARY
DESTDIR = ../../modules
#--------------------------------------------------------------------------------------------------
HEADERS += display_projectm_global.h \
    display_projectm.h
SOURCES += display_projectm.cpp
#--------------------------------------------------------------------------------------------------
OTHER_FILES += metadata.json