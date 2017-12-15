#--------------------------------------------------------------------------------------------------
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
#--------------------------------------------------------------------------------------------------
QT += quick #sql
CONFIG += qt plugin
TARGET = WebBrowser
TEMPLATE = lib
DEFINES += WEBBROWSER_LIBRARY
DESTDIR=../../modules
#--------------------------------------------------------------------------------------------------
HEADERS += webbrowser_global.h \
    webbrowser.h \
    bookmarkmodel.h \
    Model.h
SOURCES += webbrowser.cpp \
    bookmarkmodel.cpp
#--------------------------------------------------------------------------------------------------
RESOURCES += qml/qml.qrc
#--------------------------------------------------------------------------------------------------
OTHER_FILES += metadata.json
#--------------------------------------------------------------------------------------------------
DISTFILES += \
    ../../qml/TEMPWebBrowser/Window.qml \
    ../../qml/TEMPWebBrowser/BookmarkPanel.qml \
    ../../qml/TEMPWebBrowser/WebPageDisplay.qml \
    ../../qml/WebBrowser/Window.qml \
    ../../qml/WebBrowser/WebPageDisplay.qml \
    ../../qml/WebBrowser/BookmarkPanel.qml