QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
QT += quick concurrent gamepad
CONFIG += qt plugin
TARGET = Gamepad
TEMPLATE = lib
DEFINES += GAMEPAD_LIBRARY
DESTDIR = ../../modules
HEADERS += gamepad_global.h \
    gamepad.h \
    gamepadmodel.h \
    Model.h
SOURCES += gamepad.cpp \
    gamepadmodel.cpp
RESOURCES += qml/qml.qrc
OTHER_FILES += metadata.json