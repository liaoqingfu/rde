#--[FLAGS]-----------------------------------------------------------------------------------------
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
#--------------------------------------------------------------------------------------------------
QT += quick multimedia concurrent gamepad
CONFIG += qt plugin
TEMPLATE = lib
TARGET = display_spright
DEFINES += DISPLAY_SPRIGHT_LIBRARY
DESTDIR = ../../modules
#--------------------------------------------------------------------------------------------------
HEADERS += display_spright_global.h \
    display_spright.h \
    fightermanager.h \
    fighter.h \
    unit.h
# \
    #Model.h \
    #arenaitem.h \
    #player.h \
    #archive.h
SOURCES += display_spright.cpp \
    fightermanager.cpp \
    fighter.cpp \
    unit.cpp
    # \
    #arenaitem.cpp \
    #player.cpp \
    #archive.cpp
#--------------------------------------------------------------------------------------------------
#include(Character/Character.pri)
#include(Fighter/Fighter.pri)
#include(Attack/Attack.pri)
#include(Element/Element.pri)
#include(Outfit/Outfit.pri)
#include(Weapon/Weapon.pri)
#include(Item/Item.pri)
#--------------------------------------------------------------------------------------------------
RESOURCES += qml/qml.qrc
OTHER_FILES += metadata.json
#--------------------------------------------------------------------------------------------------