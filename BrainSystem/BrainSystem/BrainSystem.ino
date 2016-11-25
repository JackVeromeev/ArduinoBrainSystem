/*
 Name:		BrainSystem.ino
 Created:	11/20/2016 11:15:05 PM
 Author:	Jack
*/

// the setup function runs once when you press reset or power the board
volatile uint8_t pinn;
volatile uint8_t k;

void interruption()
{
	switch (pinn)
	{
	case 4: pinn = 6; break;
	case 6: pinn = 8; break;
	default: pinn = 4; break;
	}
	k++;
}

void setup() { 
	pinn = 4;
	k = 0;
	attachInterrupt(0, interruption, RISING);
	pinMode(4, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(13, OUTPUT);
} 
// функция loop запускает скетч по кругу 
void loop()
{
	digitalWrite(4, LOW);
	digitalWrite(6, LOW);
	digitalWrite(8, LOW);
	digitalWrite(13, LOW);
	digitalWrite(pinn, HIGH);
	if (k >= 2) digitalWrite(13, HIGH);	// если прерывание >= 2 раз за 100мс
	k = 0;
	delay(100);
}
