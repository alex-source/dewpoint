#include "port.h"

Port::Port(QObject *parent) : QObject(parent)
{

}

QVariant Port::getDataByName(QString name)
{
    Q_UNUSED( name);
    QVariant res;
    res = QVariant::fromValue(generator.bounded(1,5));
    return res;
}
