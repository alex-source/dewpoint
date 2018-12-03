#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QObject>
#include <QDebug>
#include <QString>
#include "angels/arduino.h"
#include "angels/singletonconnect.h"
#include "angels/mysql.h"
#include "space/qmlspace.h"
int main(int argc, char *argv[])
{
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

        QApplication app(argc, argv);

        Arduino arduino;

        MySql mysql;
        QmlSpace space;
        QList<double> list;
        mysql.getColumn("value",list);

        int m = 2000;//dimension factor
        int n = 0;// step counter
        double a = 0;//
        for(auto &v:list){
                a = a + v;
                n++;

            if (n == m){
                    emit space.toQml("temp",QString::number(a/m));

                    qDebug()<<a/m;
                    a  = 0;
                    n =0;
                }

        }

        QObject::connect(&arduino,&Arduino::output,[&space](QString idName,QString value){
            emit space.toQml(idName, value);
        });
        QObject::connect(&arduino,&Arduino::output,[&mysql](QString idName,QString value){
            mysql.appendValue(idName,value.toDouble());
        });

        return app.exec();
}
