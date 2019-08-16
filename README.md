This is the version of the firmware that I run on my own keyboard. Changes that are actually useful like bugfixes and improved debouncing have been commited back to animus proper. The remaining changes are things I like personally, which are:


* The LEDs play the game of life
* Rather than wrong pin numbers and no keybinds, the default is the correct pin numbers and my
  keybinds. EEPROM is cleared on flash, and restoring these after every flash is tedious when
  you're working on the code.


# Flashing

If you care about default keybinds/pin numbers, then you need to set `IS_LEFT` in `Global.h`
according to which keyboard half you're flashing.


If you're on Linux there's a rule in the makefile for flashing:

```bash
make build
make upload
```
