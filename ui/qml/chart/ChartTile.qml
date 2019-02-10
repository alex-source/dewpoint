import QtQuick 2.0
import QtCharts 2.2
Item {
        anchors.fill: parent
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
                }


        }

        function appendPoint(n,v){
        }
//        onAppendPoint:{
//        console.log(500)
//        }

}
