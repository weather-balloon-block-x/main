#include "SRC/PM25/PM25.h"
#include "src/CCS811_Compensated/CCS811_Compensated.h"
#include "src/DS18B20/DS18B20.h"
#include "src/MG811/MG811.h"
#include "src/ML8511/ML8511.h"
#include <ULP.h>

#include <SoftwareSerial.h>
#include <Wire.h>
#include <SparkFunCCS811.h>
#include <SparkFunBME280.h>
#include <Adafruit_MPRLS.h>
#include <DallasTemperature.h>
#include <OneWire.h>

PM25 pm25(2, 3);
CCS811Compensated airQuality(0x5B, 0x77);
DS18B20 temp(4);
MG811 co2(A0, 0.5875, 0.030);
O3 ozone(A2, A7, -56.45);
ML8511 uv(A1);
Adafruit_MPRLS pressure(-1, -1); 

//SoftwareSerial aprs(8, 9);

void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
  Wire.begin();
  Serial.println("Ready");
  ozone.zero();
  Serial.println("Ready");
  pressure.begin();
  Serial.println("Ready");
}

void loop() {
  pm25.readData();
  //airQuality.readData();
  Serial.print((int) pm25.data.pm25_env);
  Serial.print(",");
  //Serial.println(airQuality.data.tvoc);
  Serial.print(temp.getTemp());
  Serial.print(",");
  Serial.print(co2.getPPM());
  Serial.print(",");
  Serial.print(ozone.getConc(1, 20.0));
  Serial.print(",");
  Serial.print(uv.getIntensity());
  Serial.print(",");
  Serial.println();
  //Serial.print(pressure.readPressure());
}
