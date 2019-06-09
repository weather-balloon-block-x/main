#ifndef PM25_h
#define PM25_h

#include "Arduino.h"
#include "SoftwareSerial.h"

struct pms5003data {
  uint16_t framelen;
  uint16_t pm10_standard, pm25_standard, pm100_standard;
  uint16_t pm10_env, pm25_env, pm100_env;
  uint16_t particles_03um, particles_05um, particles_10um, particles_25um, particles_50um, particles_100um;
  uint16_t unused;
  uint16_t checksum;
};

class PM25 {
    public:
        PM25(int rxPin, txPin);
        pms5003data readData;
    private:
        SoftwareSerial _pm25Serial;*p
}

#endif