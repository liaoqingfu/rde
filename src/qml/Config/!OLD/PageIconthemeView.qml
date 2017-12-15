import QtQuick 2.0
import LemonaDE 1.0
ListView{
    model:IconThemeModel{id:iconThemeModel}
    //model:ModuleModel{id:moduleModel}
    delegate:PageIconthemeDelegate{}
    boundsBehavior: ListView.StopAtBounds
    snapMode: ListView.SnapToItem
}