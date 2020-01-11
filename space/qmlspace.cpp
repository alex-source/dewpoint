#include "qmlspace.h"

#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QObject>
#include <QDebug>
#include <angels/broadcast.h>
QmlSpace::QmlSpace(QObject *parent) : QQmlApplicationEngine(parent)
{
        connect(&Broadcast::getInstance(),&Broadcast::arduino,this,&QmlSpace::toQml);
        this->load(QUrl(QStringLiteral("qrc:/ui/qml/main.qml")));
        if (this->rootObjects().isEmpty())
                qDebug()<< "\x1b[34;47m"<<this->objectName()<<"\x1b[0m";
        this->rootContext()->setContextProperty("root", this);


}
