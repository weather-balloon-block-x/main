#include "MG811.h"

MG811::MG811(int analogPort, float zeroPoint, float reactionVoltage) :
  _calibrationCurve{2.602, zeroPoint, reactionVoltage/(2.602-3)} {
    _analogPort = analogPort;
}

int MG811::getAnalog() {
    return analogRead(_analogPort);
}

int MG811::getPPM() {
    float voltage = getAnalog() * (5/1024) / DC_GAIN;

    if (voltage >= _calibrationCurve[1]) return -1;
    else return pow(10, (voltage - _calibrationCurve[1]) / _calibrationCurve[2] + _calibrationCurve[0]);
}