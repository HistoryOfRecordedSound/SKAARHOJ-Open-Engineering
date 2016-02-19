#include <SkaarhojDueEEPROM.h>
#include <Streaming.h>
#include <Wire.h>

SkaarhojDueEEPROM EEPROM;

void setup() {
  delay(2000);
  Serial.begin(115200);
  Serial << F("\n\nSerial started\n");

  randomSeed(analogRead(1) + analogRead(2) + analogRead(3));

  Wire.begin();


  /*
    Serial << F("Test EEPROM with linear values:\n");
    for (uint16_t a = 0; a < 512; a++)  {
      EEPROM.write(a, (a & 0xFF));
      delay(4);   // after a write, make a break.
    }

    for (uint16_t a = 0; a < 512; a++)  {
      uint8_t b = EEPROM.read(a);
      if ((a & 0xFF) != b)  {
        Serial << a << F(": ") << b << F("!=") << (a & 0xFF) << F(" ERROR!\n");
      } else {
        Serial << a << F(": ") << _DECPADL(b, 3, " ") << F(" OK\n");
      }
    }

    delay(1000);

    Serial << F("Test EEPROM with random values at linear addresses:\n");
    for (uint16_t a = 0; a < 512; a++)  {
      uint8_t randomValue = random(0, 256);


      EEPROM.write(a , randomValue);
      delay(4);    // Delays between write and read on less that 4 ms may/will result in false readings!
      uint8_t b = EEPROM.read(a);
      if (randomValue != b)  {
        Serial << a << F(": ") << b << F("!=") << randomValue << F(" ERROR!\n");
      } else {
        Serial << a << F(": ") << _DECPADL(b, 3, " ") << F(" OK\n");
      }
      delay(0);
    }


    delay(1000);

    Serial << F("Test EEPROM with random values at random addresses:\n");
    for (uint16_t a = 0; a < 100; a++)  {
      uint8_t randomValue = random(0, 256);


      EEPROM.write(randomValue , randomValue);
      delay(4);	// Delays between write and read on less that 4 ms may/will result in false readings!
      uint8_t b = EEPROM.read(randomValue);
      if (randomValue != b)  {
        Serial << a << F(": ") << b << F("!=") << randomValue << F(" ERROR!\n");
      } else {
        Serial << a << F(": ") << _DECPADL(b, 3, " ") << F(" OK\n");
      }
      delay(0);
    }

    */



  uint8_t valueWriteArray[30];
  uint8_t valueReadArray[30];

  for (uint16_t a = 0; a < 30; a++) {   // testing from 0-1024

    for (uint8_t i = 0; i < 30; i++) {
      valueWriteArray[i] = random(0, 256);
      valueReadArray[i] = 0;
    }

    Serial << "Page: " << (a << 5) << "\n";
    EEPROM.writePage(a << 5, valueWriteArray);
    delay(10);
    EEPROM.readPage(a << 5, valueReadArray);

    for (uint8_t i = 0; i < 30; i++) {
      if (valueWriteArray[i] != valueReadArray[i])  {
        Serial << i << ": " << valueWriteArray[i] << "!=" << valueReadArray[i] << " - ERROR!\n";
      } else {
//        Serial << i << ": " << valueWriteArray[i] << "=" << valueReadArray[i] << " - OK\n";
      }
    }

  }






}

void loop() {
}
