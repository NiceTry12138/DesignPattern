#include "CapeMario.h"
#include "MarioStates.h"
#include "Mario.h"

void CapeMario::GotMushroom(Mario* mario)
{
	mario->SetCoin(100);
}

void CapeMario::GotFireFlower(Mario* mario)
{
	mario->SetCoin(100);
	mario->SetState(&FireMario::GetInstance());
	mario->SetShow('F');
}

void CapeMario::GotFeather(Mario* mario)
{
	mario->SetCoin(100);
}

void CapeMario::GotAttack(Mario* mario)
{
	mario->SetState(&SmallMario::GetInstance());
	mario->SetShow('o');
}
