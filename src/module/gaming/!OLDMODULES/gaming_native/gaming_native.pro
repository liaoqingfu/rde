QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
QT += quick
CONFIG += qt plugin
TARGET = gaming_native
TEMPLATE = lib
DEFINES += GAMING_NATIVE_LIBRARY
DESTDIR = ../../modules/gaming
HEADERS += gaming_native_global.h \
    gaming_native.h
SOURCES += gaming_native.cpp
RESOURCES += qml/qml.qrc
OTHER_FILES += metadata.json