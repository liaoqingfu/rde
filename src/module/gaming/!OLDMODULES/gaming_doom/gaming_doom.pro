QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
QT += quick
CONFIG += qt plugin
TARGET = gaming_doom
TEMPLATE = lib
DEFINES += GAMING_NATIVE_LIBRARY
DESTDIR = ../../modules/gaming
HEADERS += gaming_doom_global.h \
    gaming_doom.h \
    mapmodel.h \
    Model.h \
    modmodel.h \
    map.h \
    mod.h \
    file.h
SOURCES += gaming_doom.cpp \
    mapmodel.cpp \
    modmodel.cpp \
    map.cpp \
    mod.cpp \
    file.cpp
RESOURCES += qml/qml.qrc
OTHER_FILES += metadata.json

DISTFILES +=