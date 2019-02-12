#include "template.h"
#include "SoftwareSerial/src/SoftwareSerial.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include "Arduino.h"
// сигнальный провод подключен к 2 пину на Arduino
#define ONE_WIRE_BUS 4

// настроим библиотеку 1-Wire для связи с датчиком
OneWire oneWire(ONE_WIRE_BUS);

// создадим объект для работы с библиотекой DallasTemperature
DallasTemperature sensors(&oneWire);

void setup(){
  Serial.begin(9600);
  sensors.begin();
}

void loop(){
//  // отправляем запрос на измерение температуры
  sensors.requestTemperatures();
//  // покажем температуру в мониторе Serial порта
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print("-");
  delay(1200);
}
