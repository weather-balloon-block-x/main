#include "src/APRS/APRS.h"

#include "SRC/PM25/PM25.h"
#include "src/CCS811_Compensated/CCS811_Compensated.h"
#include "src/DS18B20/DS18B20.h"
#include "src/MG811/MG811.h"
#include <MQ131.h>

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

SoftwareSerial aprs(8, 9);

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
