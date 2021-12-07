#pragma once
#include "MarioState.h"
#include "Singleton.h"

/// <summary>
/// ��ͨ�������
/// </summary>
class SuperMario : public MarioState, public Singleton<SuperMario>
{
public:
	virtual void GotMushroom(Mario* mario);
	virtual void GotFireFlower(Mario* mario);
	virtual void GotFeather(Mario* mario);
	virtual void GotAttack(Mario* mario);
};

