#include "chart.h"
#include "QDebug"

Chart::Chart(QObject *parent) : QObject(parent)
{


}

void Chart::ttt()
{
    QList<double> list;
//    MySql::getInstance()->getColumn("value",list);

    int m = 2000;//dimension factor
    int n = 0;// step counter
    double a = 0;//
    for(auto &v:list){
            a = a + v;
            n++;

            if (n == m){
                    emit appendPoint("temp",a/m);
                    qDebug()<<a/m;
                    a  = 0;
                    n =0;
            }
    }

}
