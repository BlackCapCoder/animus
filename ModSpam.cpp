#include "ModSpam.h"

CModSpam::CModSpam(void)
{
  // nothing
}

void CModSpam::Begin(void)
{
  CModTemplate::Begin();
  ModGUID = 30; // GUID of this specific mod

  if (Global.HasUSB)
  {

  }
}

void CModSpam::LoadData(void)
{
  CModTemplate::LoadData();

  if (Global.HasUSB)
  {

  }
}

void CModSpam::Loop(void)
{
  CModTemplate::Loop();

  if (Animus.Async1MSDelay())
  {
    if (!active) return;
    Animus.PressKey(letter + 6, 0);
    Animus.ReleaseKey(letter + 6, 0);
    letter = (letter + 1) % 26;
  }
}

void CModSpam::PressCoords(byte x, byte y)
{
  CModTemplate::PressCoords(x, y);
  // Serial.println(String(x) + "," + String(y));
  // if (x == 6 && y == 3 && Global.isLeft) {
  //   Animus.PressKey(1, 3);
  // }
}

void CModSpam::PrePress(byte val, byte type)
{
  CModTemplate::PrePress(val, type);
    if (Global.HasUSB)
    {

    }
}
void CModSpam::PressKey(byte val, byte type)
{
  CModTemplate::PressKey(val, type);

  if (Global.HasUSB)
  {

  }
}
void CModSpam::ReleaseKey(byte val, byte type)
{
  CModTemplate::ReleaseKey(val, type);

  if (Global.HasUSB)
  {

  }
}

void CModSpam::SerialComms(byte mode)
{
  CModTemplate::SerialComms(mode);
}


CModSpam ModSpam;
