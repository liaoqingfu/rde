import QtQuick 2.0
import org.rde.network 1.0
ListView{
    //orientation:ListView.Horizontal
    model:InterfaceModel{id:interfaceModel}
    delegate:InterfaceDelegate{}
    clip:true
    boundsBehavior: Flickable.StopAtBounds
    snapMode: ListView.SnapToItem
}