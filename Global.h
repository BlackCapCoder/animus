#define IS_LEFT 1

#define DEFAULT_ROW 12
#define DEFAULT_COL 12
#define I2C_HOST_ADDRESS 7
#define I2C_GUEST_ADDRESS 8

#ifndef ANIMUS_GLOBAL
#define ANIMUS_GLOBAL
#include "Arduino.h"

class CGlobal
{
private:
public:
  byte ModCount = 0; // always starts at 0
  byte RefreshDelayDown = 10; // default value, overriden on EEPROM load
  byte RefreshDelayUp   = 10; // default value, overriden on EEPROM load
  byte ROW = DEFAULT_ROW; // default value, overriden on EEPROM load
  byte COL = DEFAULT_COL; // default value, overriden on EEPROM load
  byte LAY = 1; // default value, overriden on EEPROM load

  byte VPins[DEFAULT_ROW]; // default value, overriden on EEPROM load
  byte HPins[DEFAULT_COL]; // default value, overriden on EEPROM load


  byte KeyLayer = 0;
  byte TempLayer = 0;


  byte KeyState[DEFAULT_COL][DEFAULT_ROW];
  byte KeyStateCoolDown[DEFAULT_COL][DEFAULT_ROW];
  byte PreviousState[DEFAULT_COL][DEFAULT_ROW];
  byte LayerState[DEFAULT_COL][DEFAULT_ROW];

  bool HasUSB = false; // state of USB host addressing, useful for split keyboards, note that this does not work if USB is disconnected whilst device is still powered (IE battery packs)
  bool RequiresLoadData = false; // I am soo sorry for the spaghetti


  byte LEDBrightness = 127;
  byte numKeysDown = 0;

  CGlobal(void);
};
extern CGlobal Global;

#endif
