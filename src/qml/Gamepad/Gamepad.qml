import QtQuick 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1
Rectangle{
    id: background
    color:'darkblue'
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
                    //active: RGamepad.buttonL2 != 0
                }
                ProgressBar {
                    id: buttonL2Value
                    width: leftTrigger.width

                    //value:RGamepad.buttonL2
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
                    //active: RGamepad.buttonSelect
                }
                ButtonImage {
                    id: guideButton
                    anchors.centerIn: parent
                    source: "xboxControllerButtonGuide.png"
                    //active: RGamepad.buttonGuide
                }
                ButtonImage {
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: guideButton.right
                    anchors.leftMargin: 8
                    id: startButton
                    source: "xboxControllerStart.png"
                    //active: RGamepad.buttonStart
                }
            }
            ColumnLayout {
                id: buttonR2Item
                Layout.alignment: Qt.AlignRight
                ButtonImage {
                    id: rightTrigger
                    Layout.alignment: Qt.AlignCenter
                    source: "xboxControllerRightTrigger.png"
                    //active: RGamepad.buttonR2 != 0
                }

                ProgressBar {
                    id: buttonR2Value
                    width: rightTrigger.width
                    //value: RGamepad.buttonR2
                }
            }
        }

        RowLayout {
            id: middleRow
            ButtonImage {
                id: buttonL1
                source: "xboxControllerLeftShoulder.png"
                //active: RGamepad.buttonL1
            }
            Item {
                id: spacer1
                Layout.fillWidth: true
            }

            ButtonImage {
                id: buttonR1
                source: "xboxControllerRightShoulder.png"
                //active: RGamepad.buttonR1
            }
        }

        RowLayout {
            id: bottomRow
            width: parent.width
            DPad {
                id: dPad
                Layout.alignment: Qt.AlignLeft
                //gamepad: RGamepad
            }

            LeftThumbstick {
                id: leftThumbstick
                Layout.alignment: Qt.AlignLeft
                //gamepad: RGamepad
            }

            Item {
                id: spacer2
                Layout.fillWidth: true
            }

            RightThumbstick {
                id: rightThumbstick
                Layout.alignment: Qt.AlignRight
                //gamepad: RGamepad
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
                    //active: RGamepad.buttonA
                }
                ButtonImage {
                    id: buttonB
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    source: "xboxControllerButtonB.png";
                    //active: RGamepad.buttonB
                }
                ButtonImage {
                    id: buttonX
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    source: "xboxControllerButtonX.png";
                    //active: RGamepad.buttonX
                }
                ButtonImage {
                    id: buttonY
                    anchors.top: parent.top
                    anchors.horizontalCenter: parent.horizontalCenter
                    source: "xboxControllerButtonY.png";
                    //active: RGamepad.buttonY
                }
            }
        }
    }
    //    Connections {
    //        target: GamepadManager
    //        onGamepadConnected: gamepad.deviceId = deviceId
    //    }
    //    Gamepad {
    //        id: gamepad
    //        deviceId: GamepadManager.connectedGamepads.length > 0 ? GamepadManager.connectedGamepads[0] : -1
    //    }
}