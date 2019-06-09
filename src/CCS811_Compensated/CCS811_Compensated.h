#ifndef CCS811_Compensated_h
#define CCS811_Compensated_h

#include "Arduino.h"
#include <Wire.h>
#include <SparkFunCCS811.h>
#include <SparkFunBME280.h>

struct qualityAndClimateData {
    public:
        uint16_t tvoc, co2;
        float temp, pressure, humidity;
};

class CCS811Compensated {
    public:
        CCS811Compensated(int ccs811Addr, int bme280Addr);

        boolean readData();
        qualityAndClimateData data;
    private:
        CCS811 _ccs811;
        BME280 _bme280;
};

#endif