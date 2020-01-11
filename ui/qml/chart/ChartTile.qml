import QtQuick 2.0
import QtCharts 2.2
Item {

        anchors.fill: parent
        ChartView {
                id: cw1
                animationDuration: 100
                animationOptions: ChartView.AllAnimations
                title: "Line"
                anchors.fill: parent
                antialiasing: true

                ValueAxis {
                        id: xAxis
                        min: 0
                        max: 250
                }
                ValueAxis {
                        id: yAxis
                        min: -5
                        max: 25
                }


                LineSeries {
                        id:ls1
                        property int aX: 0
                        name: "LineSeries"
                        axisX: xAxis
                        axisY: yAxis
                        XYPoint { x: 0; y: 0 }
                        onHovered:
                        {
                            console.log(point);
                            console.log(point.x);
                            console.log(point.y);
                            console.log(state);
                        }
                }
                LineSeries {
                    id:ls2
                    property int aX: 0
                    name: "LineSeries2"
                    axisX: xAxis
                    axisY: yAxis
                        XYPoint { x: ls2.aX; y: 0 }
                        onHovered:
                        {
                            console.log(point);
                            console.log(point.x);
                            console.log(point.y);
                            console.log(state);
                        }

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

        function appendPoint(n){
            var arr = n.split(":")
            ls1.aX=ls1.aX+1;
            ls2.aX=ls2.aX+1;
            console.log(arr[0],arr[1])
            if(arr[0] ==0)
                ls1.append(ls1.aX,arr[1])
            if(arr[0]==1)
                ls2.append(ls2.aX,arr[1])

        }

        function changScale(v)

        {
         xAxis.max = xAxis.max+v
        }

}
