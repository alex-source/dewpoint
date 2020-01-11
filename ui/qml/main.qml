import QtQuick 2.11
import QtQuick.Window 2.11
import QtCharts 2.2
import "../qml/chart"

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ChartTile{
        id:chrtTl
    }
    Connections {
        target: root
        onToQml:{
            chrtTl.appendPoint(value)
        }
    }

    Item {
        anchors.fill: parent
        focus: true
        Keys.onPressed: {
            if (event.key == Qt.Key_Left) {
                chrtTl.changScale(-200)
            }
            if (event.key == Qt.Key_Right) {
                chrtTl.changScale(200)
            }
        }
    }
}
