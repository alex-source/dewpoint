#include <QDebug>
#include <QSerialPortInfo>
#include "arduino.h"
#include "angels/monitor.h"
#include "angels/broadcast.h"
//#include <QProcess>

Arduino::Arduino(QObject *parent)
{
    Q_UNUSED(parent);
    isAvailable = false;
    name = "";
    arduino = this;
    connect(arduino,&QSerialPort::readyRead,this,&Arduino::update);
    work();
}

void Arduino::work()
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
        arduino->open(QSerialPort::ReadWrite);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
    }else{
        // give error message if not available
        Monitor::getInstance().error("qwe");
        qDebug()<<"Couldn't find the Arduino!";
    }
}

void Arduino::update()
{
    frame=frame+arduino->readAll();
    QStringList l;
    l = frame.split("@");
    if(l.size() == 2)
//        qDebug()<<">>"<<l.first().remove(QRegExp("[\\n\\t\\r]"));
       emit Broadcast::getInstance().arduino(l.first().remove(QRegExp("[\\n\\t\\r]")));
//        emit output("temp",l.first());
    frame = l.last();
//QString buffer;
//buffer = "10010";
//   qDebug()<<arduino->write( buffer.toStdString().c_str(), buffer.size() );
//   arduino->write( QByteArray(1,1));
}
//sudo chmod a+rw /dev/ttyACM0
//  381  avrdude -c arduino -p m328p -P /dev/ttyACM0 -b 115200 -U flash:w:template.hex:i
