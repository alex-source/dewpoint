#ifndef ARDUINO_H
#define ARDUINO_H

#include <QObject>
#include <QSerialPort>


class Arduino : public QSerialPort
{
    Q_OBJECT
public:
    explicit Arduino(QObject *parent = nullptr);
private:
    QSerialPort* arduino;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QString name;
    bool isAvailable;
    QString frame;


    void work();

    void portList();
    void portConformity();
    void portSetup();
signals:
    void output(QString value);
//    void output();


public slots:
    void update();
};

#endif // ARDUINO_H
