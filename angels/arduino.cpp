#include <QDebug>
#include <QSerialPortInfo>
#include <QTimer>

#include "arduino.h"

Arduino::Arduino(QObject *parent)
{
    Q_UNUSED(parent);
    isAvailable = false;
    name = "";
    arduino = this;
    connect(arduino,&QSerialPort::readyRead,this,&Arduino::update);
    run();
}

void Arduino::run()
{
    portList();
    portConformity();
    portSetup();
}

void Arduino::portList()
{
    qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        qDebug()<<"Name: " << serialPortInfo.portName();
        qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
        if(serialPortInfo.hasVendorIdentifier()){
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
        }
        qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
        if(serialPortInfo.hasProductIdentifier()){
            qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
        }
    }
}

void Arduino::portConformity()
{
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
                if(serialPortInfo.productIdentifier() == arduino_uno_product_id){
                    name = serialPortInfo.portName();
                    isAvailable = true;
                }
            }
        }
    }
}

void Arduino::portSetup()
{
    if(isAvailable){
        // open and configure the serialport
        arduino->setPortName(name);
        arduino->open(QSerialPort::ReadOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
    }else{
        // give error message if not available
        qDebug()<<"Couldn't find the Arduino!";
    }
}

void Arduino::update()
{
    frame=frame+arduino->readAll();
    QStringList l;
    l = frame.split("-");
    if(l.size() == 2)
        //qDebug()<<">>"<<l.first();
        emit output("temp",l.first());
    frame = l.last();
}
