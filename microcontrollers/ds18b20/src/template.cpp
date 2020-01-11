#include "template.h"
#include "SoftwareSerial/src/SoftwareSerial.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include "Arduino.h"
int incomingByte = 0;
#define ONE_WIRE_BUS 4

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

void setup(){
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    sensors.begin();
}

void loop(){
    sensors.requestTemperatures();
      Serial.print(sensors.getTempCByIndex(0));
      Serial.print("-");

    delay(2000);
    incomingByte = Serial.read();
    if(incomingByte<0){
        digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    }
    else {
        digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)
    }

}
