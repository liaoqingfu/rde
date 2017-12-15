#include "bluetoothdevicemodel.h"
#include <QDebug>
/*                                                                                               */
BluetoothDeviceModel::BluetoothDeviceModel():Model()
{
    m_currentIndex=0;
}
/*                                                                                               */
QHash<int, QByteArray> BluetoothDeviceModel::roleNames() const
{
    QHash<int,QByteArray> hash;
    hash[0]="Name";
    hash[1]="IconName";
    hash[2]="SignalStrength";
    return hash;
}
/*                                                                                               */
QVariant BluetoothDeviceModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()){
        switch(Roles(role)){
        case Name:return Scanner::devices.at(index.row()).name();
        case IconName:return "default";
            //case IconName:return getIconName(Scanner::devices.at(index.row()));
        case SignalStrength:return Scanner::devices.at(index.row()).rssi();
        }
    }
    return QVariant();
}
/*                                                                                               */
void BluetoothDeviceModel::setCurrentIndex(const int &index)
{
    m_currentIndex=index;

    qDebug() << "Selected device " << Scanner::devices.at(index).name();
    //m_devices.at()


    //qDebug() << m_deviceManager->vector.at(index)->address();

    emit addressChanged();
}
/*                                                                                               */
//void BluetoothDeviceModel::startConnection()
//{
//    qDebug() << "Start connection...";
//    //m_deviceManager->vector.at(m_currentIndex)->startConnection();
//}
/*                                                                                               */
//QString BluetoothDeviceModel::getIconName(const QBluetoothDeviceInfo &info)const
//{
//    switch(info.majorDeviceClass()){
//    case QBluetoothDeviceInfo::MiscellaneousDevice:{
//        switch(QBluetoothDeviceInfo::MinorMiscellaneousClass(info.minorDeviceClass())){
//        case QBluetoothDeviceInfo::UncategorizedMiscellaneous:break;
//        }

//        //return "";//new Device(info,"presence_unknown",this);
//    }
//    case QBluetoothDeviceInfo::ComputerDevice:{
//        switch(QBluetoothDeviceInfo::MinorComputerClass(info.minorDeviceClass())){
//        case QBluetoothDeviceInfo::UncategorizedComputer:return "";//new ComputerDevice(info,"presence_unknown",this);
//        case QBluetoothDeviceInfo::DesktopComputer:return "computer";//new DesktopComputer(info,this);
//        case QBluetoothDeviceInfo::ServerComputer:return "";//new ServerComputer(info,this);
//        case QBluetoothDeviceInfo::LaptopComputer:return "computer-laptop";//new LaptopComputer(info,this);
//        case QBluetoothDeviceInfo::HandheldClamShellComputer:return "";//new HandheldClamShellComputer(info,this);
//        case QBluetoothDeviceInfo::HandheldComputer:return "tablet";//new HandheldComputer(info,this);
//        case QBluetoothDeviceInfo::WearableComputer:return "";//new WearableComputer(info,this);
//        }
//    }
//    case QBluetoothDeviceInfo::PhoneDevice:{
//        switch(QBluetoothDeviceInfo::MinorPhoneClass(info.minorDeviceClass())){
//        case QBluetoothDeviceInfo::UncategorizedPhone:return "";//new PhoneDevice(info,"presence_unknown",this);
//        case QBluetoothDeviceInfo::CellularPhone:return "phone";//new CellularPhone(info,this);
//        case QBluetoothDeviceInfo::CordlessPhone:return "";//new CordlessPhone(info,this);
//        case QBluetoothDeviceInfo::SmartPhone:return "smartphone";//new SmartPhone(info,this);
//        case QBluetoothDeviceInfo::WiredModemOrVoiceGatewayPhone:return "";//new WiredModemOrVoiceGatewayPhone(info,this);
//        case QBluetoothDeviceInfo::CommonIsdnAccessPhone:return "";//new CommonIsdnAccessPhone(info,this);
//        }
//    }
//    case QBluetoothDeviceInfo::LANAccessDevice:{
//        switch(QBluetoothDeviceInfo::MinorNetworkClass(info.minorDeviceClass())){
//        case QBluetoothDeviceInfo::NetworkFullService:break;
//        case QBluetoothDeviceInfo::NetworkLoadFactorOne:break;
//        case QBluetoothDeviceInfo::NetworkLoadFactorTwo:break;
//        case QBluetoothDeviceInfo::NetworkLoadFactorThree:break;
//        case QBluetoothDeviceInfo::NetworkLoadFactorFour:break;
//        case QBluetoothDeviceInfo::NetworkLoadFactorFive:break;
//        case QBluetoothDeviceInfo::NetworkLoadFactorSix:break;
//        case QBluetoothDeviceInfo::NetworkNoService:break;
//            //return "";//new Device(info,"presence_unknown",this);
//        }
//    }
//    case QBluetoothDeviceInfo::AudioVideoDevice:{
//        switch(QBluetoothDeviceInfo::MinorAudioVideoClass(info.minorDeviceClass())){
//        case QBluetoothDeviceInfo::UncategorizedAudioVideoDevice:return "";//new AudioVideoDevice(info,"presence_unknown",this);
//        case QBluetoothDeviceInfo::WearableHeadsetDevice:return "audio-headset";//new WearableHeadsetDevice(info,this);
//        case QBluetoothDeviceInfo::HandsFreeDevice:return "";//new HandsFreeDevice(info,this);
//        case QBluetoothDeviceInfo::Microphone:return "audio-input-microphone";//new Microphone(info,this);
//        case QBluetoothDeviceInfo::Loudspeaker:return "";//new Loudspeaker(info,this);
//        case QBluetoothDeviceInfo::Headphones:return "audio-headphones";//new Headphones(info,this);
//        case QBluetoothDeviceInfo::PortableAudioDevice:return "";//new PortableAudioDevice(info,this);
//        case QBluetoothDeviceInfo::CarAudio:return "";//new CarAudio(info,this);
//        case QBluetoothDeviceInfo::SetTopBox:return "";//new SetTopBox(info,this);
//        case QBluetoothDeviceInfo::HiFiAudioDevice:return "";//new HiFiAudioDevice(info,this);
//        case QBluetoothDeviceInfo::Vcr:return "";//new VCR(info,this);
//        case QBluetoothDeviceInfo::VideoCamera:return "";//new VideoCamera(info,this);
//        case QBluetoothDeviceInfo::Camcorder:return "";//new Camcorder(info,this);
//        case QBluetoothDeviceInfo::VideoMonitor:return "";//new VideoMonitor(info,this);
//        case QBluetoothDeviceInfo::VideoDisplayAndLoudspeaker:return "video-display";//new VideoDisplayAndLoudspeaker(info,this); //crash
//        case QBluetoothDeviceInfo::VideoConferencing:return "";//new VideoConferencing(info,this);
//        case QBluetoothDeviceInfo::GamingDevice:return "";//new GamingDevice(info,this);
//        }
//    }
//    case QBluetoothDeviceInfo::PeripheralDevice:{
//        switch(QBluetoothDeviceInfo::MinorPeripheralClass(info.minorDeviceClass())){
//        case QBluetoothDeviceInfo::UncategorizedPeripheral:return "";//new PeripheralDevice(info,"presence_unknown",this);
//        case QBluetoothDeviceInfo::KeyboardPeripheral:return "input-keyboard";//new KeyboardPeripheral(info,this);
//        case QBluetoothDeviceInfo::PointingDevicePeripheral:return "input-mouse";//new PointingDevicePeripheral(info,this);
//        case QBluetoothDeviceInfo::KeyboardWithPointingDevicePeripheral:return "";//new KeyboardWithPointingDevicePeripheral(info,this);
//        case QBluetoothDeviceInfo::JoystickPeripheral:return "";//new JoystickPeripheral(info,this);
//        case QBluetoothDeviceInfo::GamepadPeripheral:return "input-gaming";//new GamepadPeripheral(info,this);
//        case QBluetoothDeviceInfo::RemoteControlPeripheral:return "";//new RemoteControlPeripheral(info,this);
//        case QBluetoothDeviceInfo::SensingDevicePeripheral:return "";//new SensingDevicePeripheral(info,this);
//        case QBluetoothDeviceInfo::DigitizerTabletPeripheral:return "";//new DigitizerTabletPeripheral(info,this);
//        case QBluetoothDeviceInfo::CardReaderPeripheral:return "";//new CardReaderPeripheral(info,this);
//        }
//    }
//    case QBluetoothDeviceInfo::ImagingDevice:{
//        switch(QBluetoothDeviceInfo::MinorImagingClass(info.minorDeviceClass())){
//        case QBluetoothDeviceInfo::UncategorizedImagingDevice:return "";//new ImagingDevice(info,"presence_unknown",this);
//        case QBluetoothDeviceInfo::ImageDisplay:return "";//new ImageDisplay(info,this);
//        case QBluetoothDeviceInfo::ImageCamera:return "";//new ImageCamera(info,this);
//        case QBluetoothDeviceInfo::ImageScanner:return "scanner";//new ImageScanner(info,this);
//        case QBluetoothDeviceInfo::ImagePrinter:return "printer";//new ImagePrinter(info,this);
//        }
//    }
//    case QBluetoothDeviceInfo::WearableDevice:{
//        switch(QBluetoothDeviceInfo::MinorWearableClass(info.minorDeviceClass())){
//        case QBluetoothDeviceInfo::UncategorizedWearableDevice:return "";//new WearableDevice(info,"presence_unknown",this);
//        case QBluetoothDeviceInfo::WearableWristWatch:return "";//new WearableWristWatch(info,this);
//        case QBluetoothDeviceInfo::WearablePager:return "";//new WearablePager(info,this);
//        case QBluetoothDeviceInfo::WearableJacket:return "";//new WearableJacket(info,this);
//        case QBluetoothDeviceInfo::WearableHelmet:return "";//new WearableHelmet(info,this);
//        case QBluetoothDeviceInfo::WearableGlasses:return "";//new WearableGlasses(info,this);
//        }
//    }
//    case QBluetoothDeviceInfo::ToyDevice:{
//        switch(QBluetoothDeviceInfo::MinorToyClass(info.minorDeviceClass())){
//        case QBluetoothDeviceInfo::UncategorizedToy:return "";//new ToyDevice(info,"presence_unknown",this);
//        case QBluetoothDeviceInfo::ToyRobot:return "";//new ToyRobot(info,this);
//        case QBluetoothDeviceInfo::ToyVehicle:return "";//new ToyVehicle(info,this);
//        case QBluetoothDeviceInfo::ToyDoll:return "";//new ToyDoll(info,this);
//        case QBluetoothDeviceInfo::ToyController:return "";//new ToyController(info,this);
//        case QBluetoothDeviceInfo::ToyGame:return "";//new ToyGame(info,this);
//        }
//    }
//    case QBluetoothDeviceInfo::HealthDevice:{
//        switch(QBluetoothDeviceInfo::MinorHealthClass(info.minorDeviceClass())){
//        case QBluetoothDeviceInfo::UncategorizedHealthDevice:return "";//new HealthDevice(info,"presence_unknown",this);
//        case QBluetoothDeviceInfo::HealthBloodPressureMonitor:return "";//new HealthBloodPressureMonitor(info,this);
//        case QBluetoothDeviceInfo::HealthThermometer:return "";//new HealthThermometer(info,this);
//        case QBluetoothDeviceInfo::HealthWeightScale:return "";//new HealthWeightScale(info,this);
//        case QBluetoothDeviceInfo::HealthGlucoseMeter:return "";//new HealthGlucoseMeter(info,this);
//        case QBluetoothDeviceInfo::HealthPulseOximeter:return "";//new HealthPulseOximeter(info,this);
//        case QBluetoothDeviceInfo::HealthDataDisplay:return "";//new HealthDataDisplay(info,this);
//        case QBluetoothDeviceInfo::HealthStepCounter:return "";//new HealthStepCounter(info,this);
//        }
//    }
//    case QBluetoothDeviceInfo::UncategorizedDevice:{
//    }
//    }
//    //return QString;
//}
/*                                                                                               */
//QVector<QBluetoothDeviceInfo> BluetoothDeviceModel::m_devices;