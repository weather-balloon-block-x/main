#ifndef MG811_h
#define MG811_h

#include "Arduino.h"

#define DC_GAIN (8.5)

class MG811 {
    public:
        MG811(int analogPort, float zeroPoint, float reactionVoltage);
        int getAnalog();
        int getPPM();
    private:
        int _analogPort;
        float _calibrationCurve[3];
};

#endif