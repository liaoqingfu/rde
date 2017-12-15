#--[FLAGS]-----------------------------------------------------------------------------------------
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
#--------------------------------------------------------------------------------------------------
QT += quick #concurrent
CONFIG += qt plugin
TEMPLATE = lib
TARGET = Gallery
DEFINES += GALLERY_LIBRARY
DESTDIR = ../../modules
#--------------------------------------------------------------------------------------------------
HEADERS += gallery_global.h \
    gallery.h \
    imagemodel.h \
    Model.h \
    ProviderImage.h
SOURCES += gallery.cpp \
    imagemodel.cpp
#--------------------------------------------------------------------------------------------------
RESOURCES += qml/qml.qrc
OTHER_FILES += metadata.json
