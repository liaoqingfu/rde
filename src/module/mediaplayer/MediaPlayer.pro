#--------------------------------------------------------------------------------------------------
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
#--------------------------------------------------------------------------------------------------
QT += quick multimedia sql concurrent
CONFIG += qt plugin
TEMPLATE = lib
TARGET = MediaPlayer
DEFINES += MEDIAPLAYER_LIBRARY
DESTDIR = ../../modules
#--------------------------------------------------------------------------------------------------
HEADERS += mediaplayer.h \
    mediaplayer_global.h \
    Model.h \
    probe.h
    #ProviderCover.h \
SOURCES += mediaplayer.cpp \
    probe.cpp
#--[INCLUDES]--------------------------------------------------------------------------------------
include(Core/Core.pri)
include(Disc/Disc.pri)
include(Library/Library.pri)
include(Playlists/Playlists.pri)
include(Streams/Streams.pri)
#--[RESOURCES]-------------------------------------------------------------------------------------
RESOURCES += qml/qml.qrc
OTHER_FILES += metadata.json
#--[EOF]-------------------------------------------------------------------------------------------

DISTFILES += \
    ../../qml/MediaPlayer/Disc/CDTrackDelegate.qml \
    ../../qml/MediaPlayer/Disc/DiscPanel.qml \
    ../../qml/MediaPlayer/Library/LibraryImporter.qml \
    ../../qml/MediaPlayer/Library/LibraryItemDelegate.qml \
    ../../qml/MediaPlayer/Library/LibraryPanel.qml \
    ../../qml/MediaPlayer/Library/LibraryPanelBar.qml \
    ../../qml/MediaPlayer/Library/LibraryView.qml \
    ../../qml/MediaPlayer/Playlist/PlaylistBar.qml \
    ../../qml/MediaPlayer/Playlist/PlaylistBarDelegate.qml \
    ../../qml/MediaPlayer/Playlist/PlaylistContentDelegate.qml \
    ../../qml/MediaPlayer/Playlist/PlaylistContentView.qml \
    ../../qml/MediaPlayer/Playlist/PlaylistPanel.qml \
    ../../qml/MediaPlayer/Streams/StreamDelegate.qml \
    ../../qml/MediaPlayer/Streams/StreamsPanel.qml \
    ../../qml/MediaPlayer/CorePlaylist.qml \
    ../../qml/MediaPlayer/Dock.qml \
    ../../qml/MediaPlayer/ExtraControls.qml \
    ../../qml/MediaPlayer/Info.qml \
    ../../qml/MediaPlayer/MediaControls.qml \
    ../../qml/MediaPlayer/MoreControls.qml \
    ../../qml/MediaPlayer/ProgressSlider.qml \
    ../../qml/MediaPlayer/TabDelegate.qml \
    ../../qml/MediaPlayer/Visualizer.qml \
    ../../qml/MediaPlayer/VisualizerMeter.qml \
    ../../qml/MediaPlayer/Window.qml \
    ../../qml/MediaPlayer/CorePlaylistDelegate.qml
