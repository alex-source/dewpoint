#include "qmlspace.h"

#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QObject>
#include "mdl/port.h"
#include "angels/arduino.h"
#include "angels/singletonconnect.h"

QmlSpace::QmlSpace(QObject *parent) : QQmlApplicationEngine(parent)
{
        this->load(QUrl(QStringLiteral("qrc:/main.qml")));
        if (this->rootObjects().isEmpty())
                qDebug()<< "\x1b[34;47m"<<this->objectName()<<"\x1b[0m";
        this->rootContext()->setContextProperty("root", this);

}
