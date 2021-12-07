#include "SmallMario.h"
#include "MarioStates.h"
#include "Mario.h"

void SmallMario::GotMushroom(Mario* mario) {
	mario->SetCoin(100);
	mario->SetState(&SuperMario::GetInstance());
	mario->SetShow('O');
}

void SmallMario::GotFireFlower(Mario* mario) {
	mario->SetCoin(200);
	mario->SetState(&FireMario::GetInstance());
	mario->SetShow('F');
}

void SmallMario::GotFeather(Mario* mario)
{
	mario->SetCoin(300);
	mario->SetState(&FireMario::GetInstance());
	mario->SetShow('-');
}

void SmallMario::GotAttack(Mario* mario)
{
	mario->Die();
}