#ifndef ML8511_h
#define ML8511_h

#include "Arduino.h"

class ML8511 {
    public:
        ML8511(int port);
        float getIntensity();
        float map(float x, float in_min, float in_max, float out_min, float out_max);
    private:
        int _port;
};

#endif