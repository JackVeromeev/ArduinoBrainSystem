/*
 Name:		BrainSyatem.ino
 Created:	12/11/2016 7:42:47 PM
 Author:	Jack
*/
#include "TwoNumberDial.h"
#include "Const.h"

volatile int p1, p2;



void interruption() {
	p1 = analogRead(1);
	p2 = analogRead(2);

	Serial.print(pl1);
	Serial.print("  ");
	Serial.println(pl2);

	if (true) {
		if (p1 > p2 + 100) {
			Serial.println("FIRST");
			//digitalWrite(10, HIGH);
			TwoNumberDial.setNumber(1);
		}
		else if (p1 < p2 - 100) {
			Serial.println("SECOND");
			//digitalWrite(12, HIGH);
			TwoNumberDial.setNumber(2);
		}
		else {
			Serial.println("BOTH");
			TwoNumberDial.setNumber(99);
		}
	}
}

void setup() {
	Serial.begin(9600);
	attachInterrupt(0, interruption, RISING);
	p1 = LOW;
	p2 = LOW;
}
void loop()
{
	//Serial.print(analogRead(1));
	//Serial.print("  ");
	//Serial.println(analogRead(2));
	//TwoNumberDial.setNumber(48);
	//delay(1000);
	//TwoNumberDial.setNumber(75);
	//delay(1000);
}