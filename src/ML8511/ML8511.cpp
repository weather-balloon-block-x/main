#include "ML8511.h"

ML8511::ML8511(int port) {
    _port = port;
    Serial.println("ML8511 Ready");
}

float ML8511::getIntensity() {
    return map(analogRead(_port) * (5/1024), 0.99, 2.9, 0.0, 15.0);
}

float ML8511::map(float x, float in_min, float in_max, float out_min, float out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}