#pragma once
#include "MarioState.h"
#include "Singleton.h"

/// <summary>
/// Ð¡ÂíÀï°Â
/// </summary>
class SmallMario : public MarioState, public Singleton<SmallMario>
{
public:
	virtual void GotMushroom(Mario* mario);
	virtual void GotFireFlower(Mario* mario);
	virtual void GotFeather(Mario* mario);
	virtual void GotAttack(Mario* mario);
};

