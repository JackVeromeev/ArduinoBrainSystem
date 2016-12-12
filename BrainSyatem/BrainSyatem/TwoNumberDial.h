// TwoNumberDial.h
#pragma once
#ifndef _TWONUMBERDIAL_h
#define _TWONUMBERDIAL_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Const.h"

class TwoNumberDialClass
{
	uint8_t currentNumber1,   // least significant digit
			currentNumber2;   // most significant digit
	uint8_t clockPin1, clockPin2;
	uint8_t resetPin1, resetPin2;

public:
	TwoNumberDialClass(uint8_t _clockPin1, uint8_t _clockPin2, uint8_t _resetPin1, uint8_t _resetPin2)
	{
		this->currentNumber1 = 0;
		this->currentNumber2 = 0;
		this->clockPin1 = _clockPin1;
		this->clockPin2 = _clockPin2;
		this->resetPin1 = _resetPin1;
		this->resetPin2 = _resetPin2;
		pinMode(this->clockPin1, OUTPUT);
		pinMode(this->clockPin2, OUTPUT);
		pinMode(this->resetPin1, OUTPUT);
		pinMode(this->resetPin2, OUTPUT);
		digitalWrite(this->clockPin1, LOW);
		digitalWrite(this->clockPin2, LOW);
		digitalWrite(this->resetPin1, LOW);
		digitalWrite(this->resetPin2, LOW);
		reset();
		Serial.begin(9600);
	}

	void reset(int digitN = 0)
	{
		switch (digitN) {
		case 0: 
			this->reset(1);
			this->reset(2);
			break;
		case 1: 
			digitalWrite(this->resetPin1, HIGH);
			digitalWrite(this->resetPin1, LOW);
			this->currentNumber1 = 0;
			break;
		case 2: 
			digitalWrite(this->resetPin2, HIGH);
			digitalWrite(this->resetPin2, LOW);
			this->currentNumber2 = 0;
			break;
		default: break;
		}
	}

	void increment(uint8_t digitNumber = 0)
	{
		switch (digitNumber)
		{
		case 0: // simple increment of the number, written
			if (this->currentNumber1 == 9 && this->currentNumber2 == 9) {
				this->reset();
				return;
			}
			this->increment(1);
			if (this->currentNumber1 >= 10) {
				this->currentNumber1 = 0;
				this->increment(2);
				if (this->currentNumber2 >= 10) {
					this->currentNumber2 = 0;
				}
			}
			break;
		case 1:
			digitalWrite(clockPin1, HIGH);
			digitalWrite(clockPin1, LOW);
			this->currentNumber1++;
			break;
		case 2:
			digitalWrite(clockPin2, HIGH);
			digitalWrite(clockPin2, LOW);
			this->currentNumber2++;
			break;
		default: break;
		}
	}

	void setNumber(uint8_t number)
	{
		Serial.print("current: ");
		Serial.print(currentNumber2);
		Serial.print("");
		Serial.print(currentNumber1);
		uint8_t d1 = number % 10;

		uint8_t d2 = (number / 10) % 10;
		Serial.print(" d2=");
		Serial.print(d2);
		Serial.print(" d1=");
		Serial.println(d1);
		if (d1 == 0 || d1 < currentNumber1) { reset(1); Serial.print("reset1"); }
		if (d2 == 0 || d2 < currentNumber2) { reset(2); Serial.print(" reset2"); }
		int n1 = d1 - currentNumber1;
		int n2 = d2 - currentNumber2;
		Serial.println(" ");
		while (n1 != 0 || n2 != 0) {
			Serial.print("n2=");
			Serial.print(n2);
			Serial.print(" n1= ");
			Serial.println(n1);
			if (n1 != 0) {
				increment(1);
				n1--;
			}
			if (n2 != 0) {
				increment(2);
				n2--;
			}
		}
	}

} TwoNumberDial(
	Const.Dial.clockPin1,
	Const.Dial.clockPin2,
	Const.Dial.resetPin1,
	Const.Dial.resetPin2
	);

#endif
