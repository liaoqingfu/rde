#--------------------------------------------------------------------------------------------------
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
#--------------------------------------------------------------------------------------------------
QT += quick concurrent
CONFIG += qt plugin
TARGET = FileManager
TEMPLATE = lib
DEFINES += FILEMANAGER_LIBRARY
DESTDIR=../../modules
#--------------------------------------------------------------------------------------------------
HEADERS += filemanager_global.h \
    filemanager.h \
    volumemodel.h \
    Model.h \
    textpreview.h \
    volume.h
SOURCES += filemanager.cpp \
    volumemodel.cpp \
    textpreview.cpp \
    volume.cpp
#--------------------------------------------------------------------------------------------------
RESOURCES += qml/qml.qrc
#--------------------------------------------------------------------------------------------------
OTHER_FILES += metadata.json
#--------------------------------------------------------------------------------------------------

DISTFILES += \
    ../../qml/FileManager/FolderDelegate.qmlc \
    ../../qml/FileManager/FolderPanel.qmlc \
    ../../qml/FileManager/FolderTableView.qmlc \
    ../../qml/FileManager/Window.qmlc \
    ../../qml/FileManager/FolderDelegate.qml \
    ../../qml/FileManager/FolderPanel.qml \
    ../../qml/FileManager/FolderTableView.qml \
    ../../qml/FileManager/Main.qml \
    ../../qml/FileManager/PathBox.qml \
    ../../qml/FileManager/PreviewAnimation.qml \
    ../../qml/FileManager/PreviewAudio.qml \
    ../../qml/FileManager/PreviewImage.qml \
    ../../qml/FileManager/PreviewPanel.qml \
    ../../qml/FileManager/PreviewText.qml \
    ../../qml/FileManager/PreviewVideo.qml \
    ../../qml/FileManager/VolumeDelegate.qml \
    ../../qml/FileManager/VolumeHeading.qml \
    ../../qml/FileManager/VolumePanel.qml \
    ../../qml/FileManager/VolumeView.qml \
    ../../qml/FileManager/Window.qml

