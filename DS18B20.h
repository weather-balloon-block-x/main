#ifndef DS18B20_h
#define DS18B20_h

#include "Arduino.h"
#include <Wire.h>
#include <DallasTemperature.h>
#include <OneWire.h>

class DS18B20 {
    public:
        DS18B20(int oneWirePort);
        float getTemp();
    private:
        OneWire _wire;
        DallasTemperature _sensor;
};

#endif