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
      }
    }
