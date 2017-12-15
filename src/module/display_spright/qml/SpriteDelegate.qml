//import QtQuick 2.0
import org.neon.ui 1.0
ListDelegate{
    label.text:Name
    mouse{
        onClicked:spriteList.currentIndex=index;
        onDoubleClicked:arenaItem.addFighter(Name)
    }
    icon.source:"file:/games/spright/"+Name+"/icon.png"
}