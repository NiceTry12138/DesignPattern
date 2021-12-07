#include "SuperMario.h"
#include "MarioStates.h"
#include "Mario.h"

void SuperMario::GotMushroom(Mario* mario) {
	mario->SetCoin(50);
}

void SuperMario::GotFireFlower(Mario* mario) {
	mario->SetCoin(300);
	mario->SetState(&FireMario::GetInstance());
	mario->SetShow('F');
}

void SuperMario::GotFeather(Mario* mario)
{
	mario->SetCoin(300);
	mario->SetState(&CapeMario::GetInstance());
	mario->SetShow('-');
}

void SuperMario::GotAttack(Mario* mario)
{
	mario->SetState(&SmallMario::GetInstance());
	mario->SetShow('o');
}
