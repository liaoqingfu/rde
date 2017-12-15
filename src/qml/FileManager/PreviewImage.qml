import QtQuick 2.0
Image {
    fillMode: Image.PreserveAspectFit
    source:"file://"+FileManager.selectedFile
    //Component.onCompleted: Voice.speak("image")
}