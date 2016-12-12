#ifndef _GAME_MODE
#define _GAME_MODE

class GameModeClass
{
public:
	virtual void masterStart() = 0;
	virtual void masterReset() = 0;
	virtual void masterChange() = 0;
	virtual void init() = 0;
	virtual void interruptionMaster() = 0;
	virtual void interruptionPlayer() = 0;
};

#endif // !_GAME_MODE