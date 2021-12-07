#include "FireMario.h"
#include "MarioStates.h"
#include "Mario.h"

void FireMario::GotMushroom(Mario* mario) {
	mario->SetCoin(100);
}

void FireMario::GotFireFlower(Mario* mario) {
	mario->SetCoin(100);
}

void FireMario::GotFeather(Mario* mario)
{
	mario->SetCoin(100);
	mario->SetState(&CapeMario::GetInstance());
	mario->SetShow('-');
}

void FireMario::GotAttack(Mario* mario)
{
	mario->SetState(&SmallMario::GetInstance());
	mario->SetShow('o');
}
