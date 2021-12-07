#pragma once
class MarioState;

class Mario {
private:
	MarioState* state;
	int coin;

public:
	Mario();
	void SetState(MarioState* state);

public:
	void SetCoin(int numberOfCoins);
	void ReportCoin();

public:
	void GotMushroom();
	void GotFireFlower();
};

