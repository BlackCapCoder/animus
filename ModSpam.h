#ifndef ANIMUS_MOD_MODEXAMPLE
#define ANIMUS_MOD_MODEXAMPLE
#include "ModTemplate.h"
#include "Animus.h"

class CModSpam : public CModTemplate
{
private:
public:
  CModSpam(void);
  void Begin(void);
  void LoadData(void);
  void Loop(void);
  void PressCoords(byte x, byte y);
  void PrePress(byte val, byte type);
  void PressKey(byte val, byte type);
  void ReleaseKey(byte val, byte type);
  void SerialComms(byte mode);

  byte letter = 0;
  bool active = false;
};
extern CModSpam ModSpam;

#endif
