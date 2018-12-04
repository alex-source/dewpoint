#include "port.h"

Port::Port(QObject *parent) : QObject(parent)
{

}

QVariant Port::getDataByName(QString name)
{
    QVariant res;
    res = QVariant::fromValue(generator.bounded(1,5));
    return res;
}
