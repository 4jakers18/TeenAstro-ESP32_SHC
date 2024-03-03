# 1 "/tmp/tmpsrw3yqth"
#include <Arduino.h>
# 1 "/home/jake/TeenAstroSHC/TeenAstroSHC/TeenAstroSHC.ino"
# 28 "/home/jake/TeenAstroSHC/TeenAstroSHC/TeenAstroSHC.ino"
#include "SmartConfig.h"
#include "SmartController.h"
#include <TeenAstroMountStatus.h>



const char SHCVersion[] = SHCFirmwareVersionMajor "." SHCFirmwareVersionMinor "." SHCFirmwareVersionPatch;
const int pin[7] = { B_PIN0,B_PIN1,B_PIN2,B_PIN3,B_PIN4,B_PIN5,B_PIN6 };
const bool active[7] = { B_PIN_UP_0,B_PIN_UP_1,B_PIN_UP_2,B_PIN_UP_3,B_PIN_UP_4,B_PIN_UP_5,B_PIN_UP_6 };

SmartHandController HdCrtlr;
TeenAstroMountStatus ta_MountStatus;
void setup(void);
void loop();
#line 41 "/home/jake/TeenAstroSHC/TeenAstroSHC/TeenAstroSHC.ino"
void setup(void)
{

#ifdef ARDUINO_NodeMCU_32S
  HdCrtlr.setup(SHCVersion, pin, active, SERIAL_BAUD, SmartHandController::OLED::OLED_SSD1306, 1);
  return;

#endif

#ifdef ARDUINO_TTGO_LoRa32_V1
  HdCrtlr.setup(SHCVersion, pin, active, SERIAL_BAUD, SmartHandController::OLED::OLED_SSD1309, 2);
  return;
#else
  int value = analogRead(A_SCREEN);
  if (value < 200)
  {
    HdCrtlr.setup(SHCVersion, pin, active, SERIAL_BAUD, SmartHandController::OLED::OLED_SH1106, 1);
  }
  else if (value < 400)
  {
    HdCrtlr.setup(SHCVersion, pin, active, SERIAL_BAUD, SmartHandController::OLED::OLED_SSD1306, 1);
  }
  else
  {
    HdCrtlr.setup(SHCVersion, pin, active, SERIAL_BAUD, SmartHandController::OLED::OLED_SSD1309, 2);
  }
#endif
}

void loop()
{
  HdCrtlr.update();
}