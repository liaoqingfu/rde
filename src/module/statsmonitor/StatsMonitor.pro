#--------------------------------------------------------------------------------------------------
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
#--------------------------------------------------------------------------------------------------
QT += quick concurrent
CONFIG += qt plugin
TEMPLATE = lib
TARGET = StatsMonitor
DEFINES += STATSMONITOR_LIBRARY
DESTDIR = ../../modules/
#--------------------------------------------------------------------------------------------------
HEADERS += statsmonitor_global.h \
    statsmonitor.h
SOURCES += statsmonitor.cpp
RESOURCES += qml/qml.qrc
#--------------------------------------------------------------------------------------------------
OTHER_FILES += metadata.json