#include "mqtt.h"

#include <QDebug>

Mqtt::Mqtt():  QMqttClient()
{
    host = "broker.hivemq.com";
    topic = "qtmqtt/tpc321";
    message = "hello world";
    port = 1883;
    this->setHostname(host);
    this->setPort(port);


    connect(this, &QMqttClient::stateChanged, this, [this](){
        qDebug()<<"state"<<this->state();

        auto subscription = this->subscribe(topic);
        if (!subscription) {
            qDebug()<<"Could not subscribe. Is there a valid connection?";
        }
this->publish(topic,"333");
    });
    connect(this, &QMqttClient::messageReceived, this, [](const QByteArray &message, const QMqttTopicName &topic) {
        qDebug()<<topic.name()<<message;

    });


  this->connectToHost();
}
