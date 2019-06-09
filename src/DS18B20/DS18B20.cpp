#include "DS18B20.h"

DS18B20::DS18B20(int oneWirePort) : _wire(OneWire(oneWirePort)), _sensor(DallasTemperature(&_wire)) {
    _sensor.begin();
}

float DS18B20::getTemp() {
    return _sensor.getTempCByIndex(0);
}