import QtQuick 2.0
//-------------------------------------------------------------------------------------------------
Rectangle {
    id:button
    anchors.top: parent.top
    anchors.bottom: parent.bottom
    width:height
    radius:4
    border.width: 1
    border.color: "black"
    //---------------------------------------------------------------------------------------------
    gradient:Gradient{
        GradientStop {position:0;color:"lightgray"}
        GradientStop {position:1;color:"black"}
    }
    //---------------------------------------------------------------------------------------------
    onEnabledChanged: {
        if(enabled){
            button.state="Normal"
        }
        else{
            button.state="Disabled"
        }
    }
    //---------------------------------------------------------------------------------------------
    MouseArea{
        id:mouse
        //hoverEnabled:true
        anchors.fill:parent;
        //onHoveredChanged:if(containsMouse){button.state="Hovered"}else{button.state="Normal"}
        onPressed:{button.state="Pressed"}
        onReleased:if(containsMouse){button.state="Hovered"}else{button.state="Normal"}
    }
    //---------------------------------------------------------------------------------------------
    Image{
        id:icon
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
    }
    //---------------------------------------------------------------------------------------------
    states:[
        State{name:"Normal";PropertyChanges{target:button;scale:1;opacity:0.9}},
        //State{name:"Hovered";PropertyChanges{target:button;opacity:1}},
        State{name:"Pressed";PropertyChanges{target:button;scale:0.9;opacity:0.7}},
        //State{name:"Disabled";PropertyChanges{target:button;scale:1;opacity:0.4}}
        State{name:"Disabled";PropertyChanges{target:button;opacity:0.5}}
    ]
    //---------------------------------------------------------------------------------------------
    transitions:Transition{NumberAnimation{properties:"scale,opacity";duration:30}}
    //---------------------------------------------------------------------------------------------
    onStateChanged: {
        if(state=="Normal"){
            button.enabled=true;
            //   releaseSound.play();
        }
        //else if(state=="Hovered"){

        //}
        else if (state=="Pressed"){
            //pressSound.play();
        }
        else if (state=="Disabled"){
            button.enabled=false;
        }
    }
    //---------------------------------------------------------------------------------------------
    state:"Normal"
    //---------------------------------------------------------------------------------------------
    property alias icon:icon
    property alias mouse:mouse
}
//-------------------------------------------------------------------------------------------------