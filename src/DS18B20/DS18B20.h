#ifndef DS18B20_h
#define DS18B20_h

// include libraries
#include "Arduino.h"
#include <Wire.h>
#include <DallasTemperature.h>
#include <OneWire.h>

class DS18B20 {
    public:
        //public code
        DS18B20(int oneWirePort);
        float getTemp();
    private:
        //private code
        OneWire _wire;
        DallasTemperature _sensor;
};

#endif
