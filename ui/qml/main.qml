import QtQuick 2.11
import QtQuick.Window 2.11
import QtCharts 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ChartView {
        id: cw1
        animationDuration: 1000
        animationOptions: ChartView.AllAnimations
        title: "Line"
        anchors.fill: parent
        antialiasing: true

        ValueAxis {
            id: xAxis
            min: 0
            max: 25
        }
        ValueAxis {
            id: yAxis
            min: 0
            max: 25
        }


        LineSeries {
            id:ls1
            property int aX: 0
            name: "LineSeries"
            axisX: xAxis
            axisY: yAxis
           //XYPoint { x: ls1.aX; y: 3 }
        }
        Component.onCompleted: {
            cw1.zoomOut(0.3)
        }

    }

    Connections {
          target: root
          onToQml : {
              console.log(idName," = ",value)
              ls1.append(ls1.aX,value);
              ls1.aX++;

          }
      }
    MouseArea{
        anchors.fill: parent
        onWheel: {
            if(wheel.angleDelta.y<0)
                cw1.scrollRight(50)
            else
                cw1.scrollLeft(50)
        }

        onClicked: {
            Qt.quit();
            (yAxis.max<=ls1.aX)?cw1.scrollRight(200):''
            ls1.aX++
            //ls1.append(ls1.aX,port.getDataByName(''))
            console.log(port.getDataByName('q'))
        }
    }
}
