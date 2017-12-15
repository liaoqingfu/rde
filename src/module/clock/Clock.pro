#--------------------------------------------------------------------------------------------------
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
#--------------------------------------------------------------------------------------------------
QT += quick concurrent
CONFIG += qt plugin
TARGET = Clock
TEMPLATE = lib
DEFINES += CLOCK_LIBRARY
DESTDIR = ../../modules
#--------------------------------------------------------------------------------------------------
HEADERS += clock_global.h \
    clock.h \
    eventmodel.h \
    event.h
SOURCES += clock.cpp \
    eventmodel.cpp \
    event.cpp
#--------------------------------------------------------------------------------------------------
RESOURCES += qml/qml.qrc
OTHER_FILES += metadata.json

DISTFILES += \
    ../../qml/Clock/Window.qml \
    ../../qml/Clock/EventDelegate.qml