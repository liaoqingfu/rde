#--------------------------------------------------------------------------------------------------
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
#--------------------------------------------------------------------------------------------------
QT += quick
CONFIG += qt plugin
TEMPLATE = lib
TARGET = Screensaver
DEFINES += SCREENSAVER_LIBRARY
DESTDIR = ../../modules
#--------------------------------------------------------------------------------------------------
HEADERS += screensaver_global.h \
    screensaver.h \
    screensavermodel.h \
    Model.h \
    session.h
SOURCES += screensaver.cpp \
    screensavermodel.cpp \
    session.cpp
#--------------------------------------------------------------------------------------------------
OTHER_FILES += metadata.json