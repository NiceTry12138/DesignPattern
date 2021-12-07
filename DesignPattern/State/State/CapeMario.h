#pragma once
#include "MarioState.h"
#include "Singleton.h"

/// <summary>
/// ¶·ÅñÂíÀï°Â
/// </summary>
class CapeMario : public MarioState, public Singleton<CapeMario>
{
public:
	virtual void GotMushroom(Mario* mario);
	virtual void GotFireFlower(Mario* mario);
	virtual void GotFeather(Mario* mario);
	virtual void GotAttack(Mario* mario);
};

