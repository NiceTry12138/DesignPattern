#pragma once
#include "MarioState.h"
#include "Singleton.h"

/// <summary>
/// »ğÑæÂíÀï°Â
/// </summary>
class FireMario : public MarioState, public Singleton<FireMario>
{
public:
	virtual void GotMushroom(Mario* mario);
	virtual void GotFireFlower(Mario* mario);
	virtual void GotFeather(Mario* mario);
	virtual void GotAttack(Mario* mario);
};

