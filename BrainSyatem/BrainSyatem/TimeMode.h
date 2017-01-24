 #ifndef _TIME_MODE
#define _TIME_MODE

#include "Const.h"
#include "IGameMode.h"
#include "TwoNumberDial.h"



class TimeModeClass :
	public IGameMode
{
	enum Length { Twenty = 20, Thirty = 30, Minute = 60, Seventy = 70 } currentLength;
	enum Process {COUNTING, STOP} process;
public:
	TimeModeClass()
	{
		this->currentLength = Length::Twenty;
		this->process = STOP;
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
		TwoNumberDial.setNumber(currentLength);
		
	}
	void interruptionMaster()
	{

	}
	void interruptionPlayer() {}
}TimeMode;

#endif // !_TIME_MODE