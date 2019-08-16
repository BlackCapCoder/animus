#include "ModLED.h"
//TODO this is a dummy mod, remove this once the build system is up
CModLED::CModLED(void)
{
  // nothing
}

void CModLED::Begin(void)
{
  CModTemplate::Begin();
  ModGUID = 10; // GUID of this specific mod

  if (Global.HasUSB)
  {

  }
  InitiateLED();
}

void CModLED::InitiateLED(void) // this should only be called once per boot up
{
  LEDCount = 36;

  uint8_t ledPin = GetData(LED_PIN_MEM);

  ledPin = IS_LEFT ? 254 : 255;

  if (ledPin == 255) // this be janky due to hardware problems
  {
    LEDCount = GetData(LED_COUNT_MEM);
    FastLED.addLeds<NEOPIXEL, 11>(LEDs, LEDCount);
    RefreshLED();
  }
  else
  {
    LEDCount = GetData(LED_COUNT_MEM);
    FastLED.addLeds<NEOPIXEL, 26>(LEDs, LEDCount);
    RefreshLED();
  }
}

bool cvs[6][7] = {0};
unsigned short counter = 0;

const byte ledpos[36*2] =
  { 0,0 , 0,1 , 0,2 , 0,3 , 0,4
  , 1,4 , 1,3 , 1,2 , 1,1 , 1,0
  , 2,0 , 2,1 , 2,2 , 2,3 , 2,4
  , 3,4 , 3,3 , 3,2 , 3,1 , 3,0
  , 4,0 , 6,3 , 4,1 , 4,2 , 4,3
  , 4,4 , 5,3 , 5,2 , 5,1 , 5,0
  , 6,0 , 6,1 , 6,2 , 5,5 , 5,4
  , 6,4
  };

byte oldNumKeysDown = 0;
void CModLED::RefreshLED(void)
{
  if (oldNumKeysDown != Global.numKeysDown) {
    oldNumKeysDown = Global.numKeysDown;

    for (byte i = 0; i < 36; i++) {
      byte x = ledpos[i*2];
      byte y = ledpos[i*2+1];
      if (Global.KeyStateCoolDown[x][y] == Global.RefreshDelayDown - 1) cvs[y][x] = true;
    }
  } else if (counter % 70 == 0) {
    byte h = (counter/140) % 256;
    for (byte i = 0; i < 36; i++) {
      byte x = ledpos[i*2];
      byte y = ledpos[i*2+1];
      LEDs[i] = CHSV (h+i*2, 255, Global.KeyStateCoolDown[x][y] > 0 || cvs[y][x]? Global.LEDBrightness : 0);
    }
    FastLED.show();
  }
}

void CModLED::LoadData(void)
{
  CModTemplate::LoadData();

  if (Global.HasUSB)
  {

  }
  RefreshLED();
}

void CModLED::Loop(void)
{
  CModTemplate::Loop();

  if (Animus.Async1MSDelay())
  {
    counter++;

    if (counter % 140 == 0) {
      // GOL
      bool nextState [6][7] = { false };

      for (byte i = 0; i < Global.ROW; i++) {
        for (byte j = 0; j < Global.COL; j++) {
          byte cnt = 0;

          for (int y = -1; y < 2; y++)
            for (int x = -1; x < 2; x++)
              if ( !(x == 0 && y == 0) && cvs[(i+x)%Global.ROW][(j+y)%Global.COL] )
                cnt++;

          nextState[i][j]
            = ( cvs[i][j] && !(cnt < 2 || cnt > 3))
           || (!cvs[i][j] && cnt == 3);

        }
      }

      for (byte i = 0; i < Global.ROW; i++) {
        for (byte j = 0; j < Global.COL; j++) {
          cvs[i][j] = nextState[i][j];
        }
      }
    }

    RefreshLED ();
  }
}

void CModLED::PressCoords(byte x, byte y)
{
  CModTemplate::PressCoords(x, y);

}

void CModLED::PrePress(byte val, byte type)
{
  CModTemplate::PrePress(val, type);
  if (Global.HasUSB)
  {

  }
}
void CModLED::PressKey(byte val, byte type)
{
  CModTemplate::PressKey(val, type);
  if (type == 38) // LED brightness adjust
  {
    short adjust = val - 127;
    if (Global.LEDBrightness + adjust < 0)
    {
      Global.LEDBrightness = 0;
    }
    else if (Global.LEDBrightness + adjust > LED_MAX_BRIGHTNESS)
    {
      Global.LEDBrightness = LED_MAX_BRIGHTNESS;
    }
    else
    {
      Global.LEDBrightness = Global.LEDBrightness + adjust;
    }
    RefreshLED();
  }

}
void CModLED::ReleaseKey(byte val, byte type)
{
  CModTemplate::ReleaseKey(val, type);

}

void CModLED::SerialComms(byte mode)
{
  CModTemplate::SerialComms(mode);
}


CModLED ModLED;
