#include "CCS811_Compensated.h"

CCS811Compensated::CCS811Compensated(int ccs811Addr, int bme280Addr) : _ccs811(CCS811(ccs811Addr)), _bme280(BME280()) {
    CCS811Core::status returnCode = _ccs811.begin();
    Serial.println("CCS811 Ready");

    if (returnCode != CCS811Core::SENSOR_SUCCESS) {
        Serial.println("CCS811 Error");
    }
    
    _bme280.settings.commInterface = I2C_MODE;
    _bme280.settings.I2CAddress = bme280Addr;
    _bme280.settings.runMode = 3; //Normal mode
    _bme280.settings.tStandby = 0;
    _bme280.settings.filter = 4;
    _bme280.settings.tempOverSample = 5;
    _bme280.settings.pressOverSample = 5;
    _bme280.settings.humidOverSample = 5;
    Serial.println("BME280 Ready");
}

boolean CCS811Compensated::readData() {
    if (_ccs811.dataAvailable()) {
        data = {0};
        //Calling this function updates the global tVOC and eCO2 variables
        _ccs811.readAlgorithmResults();

        data.tvoc = _ccs811.getTVOC();
        data.co2 = _ccs811.getCO2();

        data.temp = _bme280.readTempC();
        data.pressure = _bme280.readFloatPressure();
        data.humidity = _bme280.readFloatHumidity();

        _ccs811.setEnvironmentalData(data.humidity, data.temp);
    }
}
