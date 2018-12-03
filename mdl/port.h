#ifndef PORT_H
#define PORT_H

#include <QObject>
#include <QVariant>
#include <QRandomGenerator>
class Port : public QObject
{
    Q_OBJECT
public:
    explicit Port(QObject *parent = nullptr);

    Q_INVOKABLE QVariant getDataByName(QString name);
private:
    QRandomGenerator generator;
signals:

public slots:

};

#endif // PORT_H
