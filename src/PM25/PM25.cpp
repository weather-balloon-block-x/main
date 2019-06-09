#include "PM25.h"

PM25::PM25(int rxPin, int txPin) : _pm25Serial(SoftwareSerial(rxPin,txPin)) {
    _pm25Serial.begin(9600);
}

boolean PM25::readData() {
    if (! _pm25Serial.available()) {
        return false;
      }

      // Read a byte at a time until we get to the special '0x42' start-byte
      if (_pm25Serial.peek() != 0x42) {
        _pm25Serial.read();
        return false;
      }

      // Now read all 32 bytes
      if (_pm25Serial.available() < 32) {
        return false;
      }

      uint8_t buffer[32];
      uint16_t sum = 0;
      _pm25Serial.readBytes(buffer, 32);

      // get checksum ready
      for (uint8_t i=0; i<30; i++) {
        sum += buffer[i];
      }

      /* debugging
      for (uint8_t i=2; i<32; i++) {
        Serial.print("0x"); Serial.print(buffer[i], HEX); Serial.print(", ");
      }
      Serial.println();
      */

      // The data comes in endian'd, this solves it so it works on all platforms
      uint16_t buffer_u16[15];
      for (uint8_t i=0; i<15; i++) {
        buffer_u16[i] = buffer[2 + i*2 + 1];
        buffer_u16[i] += (buffer[2 + i*2] << 8);
      }

      // put it into a nice struct :)
      memcpy((void *)&data, (void *)buffer_u16, 30);

      if (sum != data.checksum) {
        Serial.println("Checksum failure");
        return false;
      }
      // success!
      return true;
}
