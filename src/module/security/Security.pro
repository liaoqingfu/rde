#--------------------------------------------------------------------------------------------------
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
#--------------------------------------------------------------------------------------------------
QT += quick
CONFIG += qt plugin
TEMPLATE = lib
TARGET = Security
DEFINES += SECURITY_LIBRARY
DESTDIR=../../modules/
#--------------------------------------------------------------------------------------------------
HEADERS += security_global.h \
    security.h \
    window.h
SOURCES += security.cpp \
    window.cpp
#--------------------------------------------------------------------------------------------------
include(clam/clam.pri)
#--------------------------------------------------------------------------------------------------
OTHER_FILES += metadata.json
RESOURCES += qml/qml.qrc
DISTFILES += \
    ../../qml/Security/Window.qml