QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
QT += quick
CONFIG += qt plugin
TEMPLATE = lib
TARGET = gaming_supermodel
DEFINES += GAMING_SUPERMODEL_LIBRARY
DESTDIR = ../../modules/gaming
HEADERS += gaming_supermodel_global.h \
    gaming_supermodel.h
SOURCES += gaming_supermodel.cpp
RESOURCES += qml/qml.qrc
OTHER_FILES += metadata.json

DISTFILES += \
    ../../../../../system/data/gamexml/model3.xml