import QtQuick 2.7
import QtGraphicalEffects 1.0
import org.rde.ui 1.0
Item{
    id:item
    anchors{left:parent.left;right:parent.right}
    height:gameList.height/5
    scale:activeFocus?1.2:1
    opacity:activeFocus?1:0.3
    Behavior on scale{NumberAnimation{duration:50}}
    Behavior on opacity{NumberAnimation{duration:50}}

//    Rectangle{
//        anchors{fill:parent;margins:30}
//        z:0
//        radius:8
//        color:'red'


//    }


    Image{
        id:logo
        z:1
        width:parent.width-8
        height:parent.height-8
        sourceSize{width:width;height:height}
        anchors.centerIn: parent
        fillMode:Image.PreserveAspectFit
        smooth:true
        mipmap:true
        source:'image://GameLogo/'+Module+'/'+Name
        MouseArea{
            width: parent.paintedWidth
            height:parent.paintedHeight
            anchors.centerIn:parent
            onClicked:gameList.currentIndex=index
            onDoubleClicked:gameWindow.startGame(Module,Name)
        }
    }
    DropShadow{
        source:logo
        anchors.fill:logo
        horizontalOffset:8
        verticalOffset:8
        radius:8
        samples:8
        visible:parent.activeFocus?false:true
    }
    property alias logo:logo
    //property alias frame:framel
}