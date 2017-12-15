import QtQuick 2.0
import BluetoothManager 1.0
import org.rde.ui 1.0
Item{
    Panel{}
    ListView {
        model:BluetoothManagerServiceModel{id:serviceModel}
        delegate:ServiceDelegate{}
    }
}
