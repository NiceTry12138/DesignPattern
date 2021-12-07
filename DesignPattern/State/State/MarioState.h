#pragma once
class Mario;

class MarioState
{
public:
	virtual void GotMushroom(Mario* mario) = 0;
	virtual void GotFireFlower(Mario* mario) = 0;
	virtual void GotFeather(Mario* mario) = 0;
};

