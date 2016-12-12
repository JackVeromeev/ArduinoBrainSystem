#ifndef _CONSTANTS_h
#define _CONSTANTS_h

#define pl1 0
#define pl2 1
#define pl3 2
#define pl4 3
#define pl5 4


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

typedef const uint8_t cui;

class ConstClass {
public:
	class DialConstClass
	{
	public:
		DialConstClass() {}
		cui clockPin1 = 11;
		cui clockPin2 = 12;
		cui resetPin1 = 9;
		cui resetPin2 = 10;
	}Dial;

	class BrainModeConstClass
	{
	public:
		cui pin[5] = { 8, 1, 2, 3, 4 };
	}BS;

	class MasterClass
	{
	public:
		cui resetPin = 1;
		cui startPin = 2;
		cui changePin = 7;
	}Master;

	cui interruptionMasterN = 0;
	cui interruptionPlayerN = 0;

	ConstClass() { }
} Const;
#endif