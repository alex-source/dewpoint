#ifndef MQTT_H
#define MQTT_H
#include <QtMqtt/QMqttClient>

class Mqtt : public QMqttClient
{
public:
    Mqtt();

private:
    QString host;
    QString topic;
    QString message;
    quint16 port;
};

#endif // MQTT_H
