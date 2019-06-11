#include "src/DS18B20/DS18B20.h"

#include <SoftwareSerial.h>
#include <Adafruit_MPRLS.h>
#include <DallasTemperature.h>
#include <OneWire.h>

DS18B20 temp(4);
Adafruit_MPRLS pressure(-1, -1); 

//SoftwareSerial aprs(8, 9);

void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
}

void loop() {
  Serial.print(temp.getTemp());
  Serial.print(",");
  Serial.print(pressure.readPressure());
  Serial.println();
}
