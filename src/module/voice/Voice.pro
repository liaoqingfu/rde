#--------------------------------------------------------------------------------------------------
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
#--------------------------------------------------------------------------------------------------
QT += quick texttospeech
CONFIG += qt plugin
TARGET = Voice
TEMPLATE = lib
DEFINES += VOICE_LIBRARY
DESTDIR = ../../modules
#--------------------------------------------------------------------------------------------------
HEADERS += voice_global.h \
    voice.h \
    voicemodel.h \
    Model.h \
    enginemodel.h \
    languagemodel.h
SOURCES += voice.cpp \
    voicemodel.cpp \
    enginemodel.cpp \
    languagemodel.cpp
#--------------------------------------------------------------------------------------------------
RESOURCES += qml/qml.qrc
OTHER_FILES += metadata.json

DISTFILES += \
    ../../qml/Voice/Dock.qml
    ../../qml/Voice/Window.qml