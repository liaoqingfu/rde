import QtQuick 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1
//import org.rde.ui 1.0
Item {
    id: background
    anchors.fill: parent

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 8
        RowLayout {
            id: topRow
            width: parent.width
            ColumnLayout {
                id: buttonL2Item
                Layout.alignment: Qt.AlignLeft
                ButtonImage {
                    id: leftTrigger
                    Layout.alignment: Qt.AlignCenter
                    source: "xboxControllerLeftTrigger.png"
                    active: gamepad.buttonL2 != 0
                }
                ProgressBar {
                    id: buttonL2Value
                    width: leftTrigger.width
                    value: gamepad.buttonL2
                }
            }

            Item {
                id: centerButtons
                Layout.alignment: Qt.AlignCenter
                Layout.fillWidth: true
                height: guideButton.height
                width: guideButton.width + 16 + backButton.width + startButton.width
                ButtonImage {
                    id: backButton
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: guideButton.left
                    anchors.rightMargin: 8
                    source: "xboxControllerBack.png"
                    active: gamepad.buttonSelect
                }
                ButtonImage {
                    id: guideButton
                    anchors.centerIn: parent
                    source: "xboxControllerButtonGuide.png"
                    active: gamepad.buttonGuide
                }
                ButtonImage {
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: guideButton.right
                    anchors.leftMargin: 8
                    id: startButton
                    source: "xboxControllerStart.png"
                    active: gamepad.buttonStart
                }
            }


            ColumnLayout {
                id: buttonR2Item
                Layout.alignment: Qt.AlignRight
                ButtonImage {
                    id: rightTrigger
                    Layout.alignment: Qt.AlignCenter
                    source: "xboxControllerRightTrigger.png"
                    active: gamepad.buttonR2 != 0
                }

                ProgressBar {
                    id: buttonR2Value
                    width: rightTrigger.width
                    value: gamepad.buttonR2
                }
            }
        }

        RowLayout {
            id: middleRow
            ButtonImage {
                id: buttonL1
                source: "xboxControllerLeftShoulder.png"
                active: gamepad.buttonL1
            }
            Item {
                id: spacer1
                Layout.fillWidth: true
            }

            ButtonImage {
                id: buttonR1
                source: "xboxControllerRightShoulder.png"
                active: gamepad.buttonR1
            }
        }

        RowLayout {
            id: bottomRow
            width: parent.width
            DPad {
                id: dPad
                Layout.alignment: Qt.AlignLeft
                gamepad: gamepad
            }

            LeftThumbstick {
                id: leftThumbstick
                Layout.alignment: Qt.AlignLeft
                gamepad: gamepad
            }

            Item {
                id: spacer2
                Layout.fillWidth: true
            }

            RightThumbstick {
                id: rightThumbstick
                Layout.alignment: Qt.AlignRight
                gamepad: gamepad
            }

            Item {
                width: 200
                height: 200
                Layout.alignment: Qt.AlignRight
                ButtonImage {
                    id: buttonA
                    anchors.bottom: parent.bottom
                    anchors.horizontalCenter: parent.horizontalCenter
                    source: "xboxControllerButtonA.png";
                    active: gamepad.buttonA
                }
                ButtonImage {
                    id: buttonB
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    source: "xboxControllerButtonB.png";
                    active: gamepad.buttonB
                }
                ButtonImage {
                    id: buttonX
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    source: "xboxControllerButtonX.png";
                    active: gamepad.buttonX
                }
                ButtonImage {
                    id: buttonY
                    anchors.top: parent.top
                    anchors.horizontalCenter: parent.horizontalCenter
                    source: "xboxControllerButtonY.png";
                    active: gamepad.buttonY
                }
            }
        }
    }
}

//Connections {
//    target: GamepadManager
//    onGamepadConnected: gamepad.deviceId = deviceId
//}

//Gamepad {
//    id: gamepad
//    deviceId: GamepadManager.connectedGamepads.length > 0 ? GamepadManager.connectedGamepads[0] : -1
//}
//}



/*
Item{



    width:800
    height:600



        Image{
            id:dpad
            source:'dpad.png'
            fillMode: Image.PreserveAspectFit
        }

        Image{
            id:selectButton
            source:'select.png'
            fillMode: Image.PreserveAspectFit
        }
        Image{
            id:startButton
            source:'start.png'
            fillMode: Image.PreserveAspectFit
        }
        Image{
            id:guideButton
            source:'guide.png'
            fillMode: Image.PreserveAspectFit
        }

        Image{
            id:buttonA
            source:'buttona.png'
            fillMode: Image.PreserveAspectFit
        }
        Image{
            id:buttonB
            source:'buttonb.png'
            fillMode: Image.PreserveAspectFit
        }
        Image{
            id:buttonX
            source:'buttonx.png'
            fillMode: Image.PreserveAspectFit
        }
        Image{
            id:buttonY
            source:'buttony.png'
            fillMode: Image.PreserveAspectFit
        }
    }
}

/*

import QtQuick 2.2

import QtQuick.Window 2.0
import QtGamepad 1.0

Window {
    id: applicationWindow1
    visible: true
    width: 800
    height: 600
    title: qsTr("QtGamepad Example")
    color: "#363330"


*/