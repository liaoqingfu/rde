#--[FLAGS]-----------------------------------------------------------------------------------------
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_LFLAGS_RELEASE -= -O1
#--------------------------------------------------------------------------------------------------
QT += quick bluetooth
CONFIG += qt plugin
TEMPLATE = lib
TARGET = Bluetooth
DEFINES += BLUETOOTH_LIBRARY
DESTDIR = ../../modules
#--------------------------------------------------------------------------------------------------
HEADERS += bluetooth_global.h \
    ProviderDevice.h \
    bluetooth.h \
    devicemanager.h \
    device.h \
    devicemodel.h \
    Model.h \
    adapter.h
SOURCES += bluetooth.cpp \
    devicemanager.cpp \
    device.cpp \
    devicemodel.cpp \
    adapter.cpp
#--[INCLUDES]--------------------------------------------------------------------------------------
include(AudioVideoDevice/AudioVideoDevice.pri)
include(ComputerDevice/ComputerDevice.pri)
include(HealthDevice/HealthDevice.pri)
include(ImagingDevice/ImagingDevice.pri)
include(PeripheralDevice/PeripheralDevice.pri)
include(PhoneDevice/PhoneDevice.pri)
include(ToyDevice/ToyDevice.pri)
include(WearableDevice/WearableDevice.pri)
#--[RESOURCES]-------------------------------------------------------------------------------------
RESOURCES+=qml/qml.qrc
OTHER_FILES += metadata.json
#--[EOF]-------------------------------------------------------------------------------------------
DISTFILES += \
    ../../qml/TEMPBluetooth/DeviceDelegate.qml \
    ../../qml/TEMPBluetooth/DeviceList.qml \
    ../../qml/TEMPBluetooth/ServiceDelegate.qml \
    ../../qml/TEMPBluetooth/ServiceList.qml \
    ../../qml/TEMPBluetooth/Window.qml \
    ../../qml/TEMPBluetooth/DeviceInfoPanel.qml \
    ../../qml/TEMPBluetooth/DeviceListPanel.qml \
    ../../qml/TEMPBluetooth/DeviceListToolBar.qml