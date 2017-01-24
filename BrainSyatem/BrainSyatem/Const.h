#ifndef _CONSTANTS_h
#define _CONSTANTS_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

typedef const uint8_t cui8;
typedef uint8_t ui8;

struct ConstClass {
	struct DialConst
	{
		cui8 clockPin1 = 11;
		cui8 clockPin2 = 12;
		cui8 resetPin1 = 9;
		cui8 resetPin2 = 10;
	}Dial;

	struct BrainModeConst
	{
		cui8 pin[5] = { 8, 1, 2, 3, 4 };
	}BrainSystem;

	struct MasterConst
	{
		cui8 resetPin = 1;
		cui8 startPin = 2;
		cui8 changePin = 7;
	}Master;

	cui8 speakerPin = 8;
	cui8 interruptionMasterN = 0;
	cui8 interruptionPlayerN = 0;

} Const;
#endif