#include "PM25.h"
#include "CCS811_Compensated.h"
#include "DS18B20.h"
#include "MG811.h"
#include "MQ131.h"

#include <SoftwareSerial.h>
#include <Wire.h>
#include <SparkFunCCS811.h>
#include <SparkFunBME280.h>
#include <DallasTemperature.h>
#include <OneWire.h>

PM25 pm25(2, 3);
CCS811Compensated airQuality(0x5B, 0x77);
DS18B20 temp(4);
MG811 co2(A0, 0.5875, 0.030);
MQ131 ozone(2,A0, LOW_CONCENTRATION, 10000);

void setup() {
  Serial.begin(115200);
  ozone.calibrate();
}

void loop() {
  pm25.readData();
  airQuality.readData();
  Serial.println(temp.getTemp());
  Serial.println(co2.getPPM());
  Serial.println(ozone.getO3(PPB));
}
