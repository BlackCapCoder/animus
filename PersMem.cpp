#include "PersMem.h"


CMem::CMem(void)
{

}

void CMem::Begin(void)
{
  LoadData();
}

void CMem::LoadData(void)
{
  // loads EEPROM data to SRAM
  Global.COL = GetColCount();
  if (Global.COL == 255) // if EEPROM data is not set, then load default values
  {
    SetEEPROM(MEM_ROW_6 , 0);
    SetEEPROM(MEM_ROW_7 , 0);
    SetEEPROM(MEM_ROW_8 , 0);
    SetEEPROM(MEM_ROW_9 , 0);
    SetEEPROM(MEM_ROW_10, 0);
    SetEEPROM(MEM_ROW_11, 0);
    SetEEPROM(MEM_ROW_12, 0);
    SetEEPROM(MEM_ROW_13, 0);
    SetEEPROM(MEM_ROW_14, 0);
    SetEEPROM(MEM_ROW_15, 0);
    SetEEPROM(MEM_ROW_16, 0);
    SetEEPROM(MEM_ROW_17, 0);
    SetEEPROM(MEM_ROW_18, 0);
    SetEEPROM(MEM_ROW_19, 0);
    SetEEPROM(MEM_COL_7 , 0);
    SetEEPROM(MEM_COL_8 , 0);
    SetEEPROM(MEM_COL_9 , 0);
    SetEEPROM(MEM_COL_10, 0);
    SetEEPROM(MEM_COL_11, 0);
    SetEEPROM(MEM_COL_12, 0);
    SetEEPROM(MEM_COL_13, 0);
    SetEEPROM(MEM_COL_14, 0);
    SetEEPROM(MEM_COL_15, 0);
    SetEEPROM(MEM_COL_16, 0);
    SetEEPROM(MEM_COL_17, 0);
    SetEEPROM(MEM_COL_18, 0);
    SetEEPROM(MEM_COL_19, 0);

    if (IS_LEFT) {
      SetEEPROM(MEM_ROW_0 , 6);
      SetEEPROM(MEM_ROW_1 , 22);
      SetEEPROM(MEM_ROW_2 , 8);
      SetEEPROM(MEM_ROW_3 , 17);
      SetEEPROM(MEM_ROW_4 , 15);
      SetEEPROM(MEM_ROW_5 , 14);

      SetEEPROM(MEM_COL_0 , 5);
      SetEEPROM(MEM_COL_1 , 2);
      SetEEPROM(MEM_COL_2 , 9);
      SetEEPROM(MEM_COL_3 , 18);
      SetEEPROM(MEM_COL_4 , 16);
      SetEEPROM(MEM_COL_5 , 12);
      SetEEPROM(MEM_COL_6 , 19);
    } else {
      SetEEPROM(MEM_ROW_0 , 6);
      SetEEPROM(MEM_ROW_1 , 22);
      SetEEPROM(MEM_ROW_2 , 8);
      SetEEPROM(MEM_ROW_3 , 17);
      SetEEPROM(MEM_ROW_4 , 15);
      SetEEPROM(MEM_ROW_5 , 14);

      SetEEPROM(MEM_COL_0 , 12);
      SetEEPROM(MEM_COL_1 , 19);
      SetEEPROM(MEM_COL_2 , 9);
      SetEEPROM(MEM_COL_3 , 18);
      SetEEPROM(MEM_COL_4 , 16);
      SetEEPROM(MEM_COL_5 , 2);
      SetEEPROM(MEM_COL_6 , 5);
    }

    SetEEPROM(MEM_DYNAMIC_ADDR , 19);
    SetEEPROM(MEM_BOARD_TYPE   , 0);
    SetEEPROM(MEM_ROW_COUNT    , 6);
    SetEEPROM(MEM_COL_COUNT    , 7);
    SetEEPROM(MEM_IS_USBHOST   , IS_LEFT);

    SetEEPROM(MEM_REFRESH_RATE_DOWN , 20);
    SetEEPROM(MEM_REFRESH_RATE_UP   , 20);
    SetEEPROM(MEM_NKRO_MODE         , 1);

    Global.COL = GetColCount();
    Global.ROW = GetRowCount();

    if (IS_LEFT)
    {
      constexpr byte keys[] =
      {
      // esc       `         1         2        3       4      5
         41,   0,  53,   0,  30,   0,  31,  0,  32, 0,  33, 0, 34,   0,
         43,   0,  20,   0,  26,   0,   8,  0,  21, 0,  23, 0,  0, 255,
         41,   0,   4,   0,  22,   0,   7,  0,   9, 0,  10, 0,  0, 255,
          0, 255,  29,   0,  27,   0,   6,  0,  25, 0,   5, 0,  1,   3,
          0,  38, 117,  38, 137,  38, 157, 38, 227, 0, 224, 0, 41,   0,
          0,   0,   0,   0,   0,   0,   0,  0,   0, 0,  44, 0,  0,   0,

         41,   0,  53,   0,  30,   0,  31,  0,  32, 0,  33, 0, 34,   0,
         43,   0,  20,   0,  26,   0,   8,  0,  21, 0,  23, 0,  0, 255,
         41,   0,   4,   0,  22,   0,   7,  0,   9, 0,  10, 0,  0, 255,
          0, 255,  29,   0,  27,   0,   6,  0,  25, 0,   5, 0,  1,   3,
          0,  38, 117,  38, 137,  38, 157, 38, 227, 0, 224, 0, 41,   0,
          0,   0,   0,   0,   0,   0,   0,  0,   0, 0,  44, 0,  0,   0,

         41,   0,  53,   0,  30,   0,  31,  0,  32, 0,  33, 0, 34,   0,
        157,  38,  43,   0,  20,   0,  26,  0,   8, 0,  21, 0, 23,   0,
        137,  38,  42,   0,   4,   0,  22,  0,   7, 0,   9, 0, 10,   0,
        117,  38,   0, 255,  29,   0,  27,  0,   6, 0,  25, 0,  5,   0,
          0,  38,   0, 255,   0, 255,   2,  3,   1, 3,  25, 0, 41,   0,
          0,   0,   0,   0,   0,   0,   0,  0,   0, 0,   6, 0,  0,   0
      //  5         2         9        18       16      12     19
      };

      SetEEPROM (MEM_LAY_COUNT, 3);

      for (int i = 0; i < 252; i++)
        EEPROM.update(i, keys[i]);

      SetKey (5, 5, 1, 4 + ('c' - 'a'), 0);
      SetKey (5, 4, 1, 4 + ('v' - 'a'), 0);
      SetKey (6, 3, 0, 1, 3);
    } else {
      constexpr byte keys[] =
      {
      // =        -        0        9        8        7        6
        46,   0, 45,   0, 39,  0,  38,  0,  37,  0,  36,  0,  35,   0,
        48,   0, 19,   0, 18,  0,  12,  0,  24,  0,  28,  0,  47,   0,
        52,   0, 51,   0, 15,  0,  14,  0,  13,  0,  11,  0,  49,   0,
         0, 255, 56,   0, 55,  0,  54,  0,  16,  0,  17,  0,   0, 255,
        79,   0, 82,   0, 81,  0,  80,  0, 230,  0,  40, 20, 231,   0,
         0,   0,  0,   0,  0,  0,   0,  0,   0,  0,  42, 21,   0,   0,

        46,   0, 45,   0, 39,  0,  38,  0,  37,  0,  36,  0,  35,   0,
        48,   0, 19,   0, 18,  0,  12,  0,  24,  0,  28,  0,  47,   0,
        52,   0, 51,   0, 15,  0,  14,  0,  13,  0,  11,  0,  49,   0,
         0, 255, 56,   0, 55,  0,  54,  0,  16,  0,  17,  0,   0, 255,
        79,   0, 82,   0, 81,  0,  80,  0, 230,  0,  40, 20, 231,   0,
         0,   0,  0,   0,  0,  0,   0,  0,   0,  0,  42, 21,   0,   0,

        46,   0, 45,   0, 39,  0,  38,  0,  37,  0,  36,  0,  35,   0,
        48,   0, 47,   0, 51,  0,  19,  0,  24,  0,   9,  0,  13,   0,
        49,   0, 52,   0,  1, 37, 131, 34, 125, 35, 131, 35, 125,  34,
         0, 255,  0, 255, 56,  0,  55,  0,  54,  0,  15,  0,  14,   0,
         0, 255,  0, 255,  0, 31,   1, 31, 226,  0,  42, 21, 231,   0,
         0,   0,  0,   0,  0,  0,   0,  0,   0,  0, 228,  0,   0,   0
      // 12      19        9       18       16        2        5
      };

      SetEEPROM (MEM_LAY_COUNT, 3);

      for (int i = 0; i < 252; i++)
        EEPROM.update(i, keys[i]);

      SetKey (5, 5, 1, 4 + ('m' - 'a'), 0);
      SetKey (5, 4, 1, 4 + ('n' - 'a'), 0);
    }
  }

  Global.COL              = GetColCount();
  Global.ROW              = GetRowCount();
  Global.RefreshDelayDown = GetRefreshRateDown();
  Global.RefreshDelayUp   = GetRefreshRateUp();
  Global.LAY              = GetLayCount();

  for (byte i = 0; i < Global.ROW; i++)
    Global.VPins[i] = GetRowPin(i);

  for (byte i = 0; i < Global.COL; i++)
    Global.HPins[i] = GetColPin(i);

  Global.HasUSB = GetUSBHostType();

  Global.RequiresLoadData = true;
  // loads mod EEPROM addresses to SRAM


  // resets pin statuses
  for (int i = 0; i < Global.ROW; i++)
  {
    pinMode(Global.VPins[i], INPUT);
    digitalWrite(Global.VPins[i], HIGH);
  }

  for (int i = 0; i < Global.COL; i++)
  {
    pinMode(Global.HPins[i], INPUT);
    digitalWrite(Global.HPins[i], LOW);
  }

  for (int i = 0; i < Global.ROW; i++)
  {
    for (int j = 0; j < Global.COL; j++)
    {
      Global.KeyState[j][i] = 0;
      Global.PreviousState[j][i] = 0;
      Global.KeyStateCoolDown[j][i] = 0;
    }
  }
}

void CMem::Loop(void)
{

}

// Start of Setters

// don't use EEPROM.update elsewhere to maintain platform agnosticity
void CMem::SetEEPROM(short address, byte data) // this updates the eeprom
{
  EEPROM.update(address, data);
}

void CMem::SetEEPROMForced(short address, byte data) // this hard rewrites the eeprom
{
  EEPROM.write(address, data);
}

void CMem::CommitEEPROM(void)
{
  #if defined (ARDUINO_SAMD_ZERO) // only run this if in SAMD21
  EEPROM.commit();
  #endif
}

void CMem::SetKey(byte x, byte y, byte z, byte inputChar, byte inputType)
{
  SetEEPROM(((x + (y * Global.COL) + (z * Global.COL * Global.ROW)) * 2), inputChar);
  SetEEPROM(((x + (y * Global.COL) + (z * Global.COL * Global.ROW)) * 2) + 1, inputType);
}

void CMem::SetRowCount(byte input)
{
  SetEEPROM(MEM_ROW_COUNT, input);

}

void CMem::SetColCount(byte input)
{
  SetEEPROM(MEM_COL_COUNT, input);

}

void CMem::SetLayCount(byte input)
{
  SetEEPROM(MEM_LAY_COUNT, input);

}

void CMem::SetRowPin(byte rowNo, byte pinNo)
{
  SetEEPROM(MEM_ROW_0 + rowNo, pinNo);

}

void CMem::SetColPin(byte colNo, byte pinNo)
{
  SetEEPROM(MEM_COL_0 + colNo, pinNo);

}

void CMem::SetBoardType(byte input)
{
  SetEEPROM(MEM_BOARD_TYPE, input);

}

void CMem::SetNKROType(byte input)
{
  SetEEPROM(MEM_NKRO_MODE, input);

}

void CMem::SetUSBHostType(byte input)
{
  SetEEPROM(MEM_IS_USBHOST, input);
}

void CMem::SetRefreshRateDown(byte input)
{
  SetEEPROM(MEM_REFRESH_RATE_DOWN, input);
}

void CMem::SetRefreshRateUp(byte input)
{
  SetEEPROM(MEM_REFRESH_RATE_UP, input);
}

// End of Setters

//Start of Getters

// do not use EEPROM.read elsewhere to maintain platform agnosticity
byte CMem::GetEEPROM(short address)
{
  return EEPROM.read(address);
}

byte CMem::GetKeyData(byte x, byte y, byte z)
{
  return GetEEPROM(((x + (y * Global.COL) + (z * Global.COL * Global.ROW)) * 2));
}

byte CMem::GetKeyType(byte x, byte y, byte z)
{
  return GetEEPROM(((x + (y * Global.COL) + (z * Global.COL * Global.ROW)) * 2) + 1);


}

byte CMem::GetRowCount()
{
  return GetEEPROM(MEM_ROW_COUNT);
}

byte CMem::GetColCount()
{
  return GetEEPROM(MEM_COL_COUNT);
}

byte CMem::GetLayCount()
{
  return GetEEPROM(MEM_LAY_COUNT);
}

byte CMem::GetRowPin(byte rowNo)
{
  return GetEEPROM(MEM_ROW_0 + rowNo);
}

byte CMem::GetColPin(byte colNo)
{
  return GetEEPROM(MEM_COL_0 + colNo);

}

byte CMem::GetBoardType()
{
  return GetEEPROM(MEM_BOARD_TYPE);
}

byte CMem::GetNKROType()
{
  return GetEEPROM(MEM_NKRO_MODE);
}

byte CMem::GetUSBHostType()
{
  return GetEEPROM(MEM_IS_USBHOST);
}

byte CMem::GetRefreshRateDown()
{
  return GetEEPROM(MEM_REFRESH_RATE_DOWN);
}

byte CMem::GetRefreshRateUp()
{
  return GetEEPROM(MEM_REFRESH_RATE_UP);
}



// End of Getters


void CMem::End(void)
{

}

CMem PersMem;
