#ifndef _TIME_MODE
#define _TIME_MODE

#include "Const.h"
#include "GameMode.h"

class TimeModeClass :
	public GameModeClass
{
public:
	enum Length { Twenty = 20, Thirty = 30, Minute = 60, Seventy = 70 } currentLength;
	int currentTime;
	TimeModeClass()
	{
		this->currentLength = Length::Twenty;
	}
	void masterStart()
	{

	}
	void masterReset()
	{

	}
	void masterChange()
	{

	}
	void init()
	{
		attachInterrupt(Const.interruptionMasterN, this->interruptionMaster, RISING);
		attachInterrupt(Const.interruptionPlayerN, this->interruptionPlayer, RISING);
		currentTime = currentLength;
		TwoNumberDial.setNumber(currentTime);
	}
	void interruptionMaster()
	{

	}
	void interruptionPlayer() {}
}TimeMode;

#endif // !_TIME_MODE




