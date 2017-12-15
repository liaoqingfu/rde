#--------------------------------------------------------------------------------------------------
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
#--------------------------------------------------------------------------------------------------
QT += quick network #concurrent
CONFIG += qt plugin
TEMPLATE = lib
TARGET = Network
DEFINES += NETWORK_LIBRARY
DESTDIR=../../modules/
#--------------------------------------------------------------------------------------------------
HEADERS += network_global.h \
    network.h \
    Model.h
SOURCES += network.cpp
#--INCLUDES----------------------------------------------------------------------------------------
include(Configuration/Configuration.pri)
include(Interface/Interface.pri)
include(Session/Session.pri)
#--------------------------------------------------------------------------------------------------
RESOURCES += qml/qml.qrc
#--------------------------------------------------------------------------------------------------
OTHER_FILES += metadata.json
#--EOF---------------------------------------------------------------------------------------------
DISTFILES += \
    ../../qml/Network/AccessPointDelegate.qml \
    ../../qml/Network/AccessPointView.qml \
    ../../qml/Network/InterfaceDelegate.qml \
    ../../qml/Network/InterfaceView.qml \
    ../../qml/Network/Window.qml \
    ../../qml/Network/Dock.qml \
    ../../qml/Network/ConfigurationView.qml \
    ../../qml/Network/ConfigurationDelegate.qml