#ifndef PORT_H
#define PORT_H

#include <QObject>
#include <QSerialPort>
class Port : public QSerialPort
{
    Q_OBJECT
public:
    explicit Port(QObject *parent = nullptr);
private:
signals:

public slots:

};

#endif // PORT_H
