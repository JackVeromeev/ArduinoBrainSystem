#ifndef _BS_MODE
#define _BS_MODE
#include "Const.h"
#include "IGameMode.h"

class BSModeClass
	: public IGameMode
{
public:
	BSModeClass() {}
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
	}
	void interruptionMaster()
	{

	}
	void interruptionPlayer() {

	}
}BSMode;

#endif // !_BS_MODE
