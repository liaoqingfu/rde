import org.rde.ui 1.0
import QtQuick 2.0
import QtQuick.Layouts 1.3
Item{
    anchors.fill: parent
    RowLayout{
        anchors{left:parent.left;right:parent.right;top:parent.top;bottom:parent.verticalCenter}
        Item{
            id:enginePanel
            anchors{top:parent.top;bottom:parent.bottom}
            width:200
            Layout.minimumWidth:200
            Layout.maximumWidth:200
            Header{
                id:engineHeader
                label.text:"Engines"
            }
            EngineView{
                id:engineView
                anchors{left:parent.left;right:parent.right;top:engineHeader.bottom;bottom:parent.bottom}
            }
        }
        Item{
            id:localePanel
            anchors{top:parent.top;bottom:parent.bottom}
            Layout.minimumWidth:200
            Layout.maximumWidth:200
            Header{
                id:localeHeader
                label.text:"Locales"
            }
            LanguageView{
                id:languageView
                anchors{left:parent.left;right:parent.right;top:localeHeader.bottom;bottom:parent.bottom}
            }
        }
        VoiceTable{
            id:voiceTable
            anchors{top:parent.top;bottom:parent.bottom}
            Layout.fillWidth: true
        }
    }
    SettingsPanel{
        id:settingsPanel
        anchors{left:parent.left;right:parent.right;top:parent.verticalCenter;bottom:parent.bottom}
    }
}