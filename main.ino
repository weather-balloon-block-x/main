#include "src/DS18B20/DS18B20.h"

#include <DallasTemperature.h>
#include <OneWire.h>

DS18B20 temp(4);

SoftwareSerial aprs(8, 9);

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println(temp.getTemp());
}
