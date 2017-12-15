#--[FLAGS]-----------------------------------------------------------------------------------------
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
#--------------------------------------------------------------------------------------------------
QT += quick
CONFIG += qt plugin
TEMPLATE = lib
TARGET = display_xss
DEFINES += DISPLAY_XSS_LIBRARY
DESTDIR = ../../modules/display
#--------------------------------------------------------------------------------------------------
HEADERS += display_xss_global.h \
    display_xss.h
SOURCES += display_xss.cpp
#--------------------------------------------------------------------------------------------------
OTHER_FILES += metadata.json