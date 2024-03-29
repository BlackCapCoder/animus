#ifndef ANIMUS
#define ANIMUS
#include "AnimusKeyboard.h"
#include "Mod.h"


#define BAUD 19200
#define DRIVER_VERSION "Animus Nova x3.0"

class CAnimus
{
private:
  void MillisLoop(void);
  unsigned long PreviousMillis = 0;
  unsigned long CurrentMillis = 0;
  bool ReadyMillis = false;
  byte RefreshCounter = 0;
public:
  CAnimus(void);
  void Begin(void);
  void Loop(void);
  void PrePress(byte val, byte type);
  void PressCoords(byte x, byte y);
  void PressKey(byte val, byte type);
  void ReleaseKey(byte val, byte type);
  void SwitchLayer(bool increment);
  void RotateLayer(byte val);
  void KeyScan(void);
  bool Async1MSDelay(void);

};
extern CAnimus Animus;

#endif
