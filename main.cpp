#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QObject>
#include <QDebug>
#include <QString>
#include "angels/arduino.h"
#include "space/qmlspace.h"
int main(int argc, char *argv[])
{
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

        QApplication app(argc, argv);

        Arduino arduino;

        QmlSpace space;
        QObject::connect(&arduino,&Arduino::output,[&space](QString idName,QString value){
                emit space.toQml(idName, value);
        });
//        QObject::connect(&arduino,&Arduino::output,[](QString idName,QString value){
//                MySql::getInstance()->appendValue(idName,value.toDouble());
//        });

        return app.exec();
}
