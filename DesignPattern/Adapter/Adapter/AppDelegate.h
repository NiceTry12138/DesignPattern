#pragma once
#include "Adapter.h"

class AppDelegate
{
public:
	void Run();

	void UseChinesePlug(ChineseSocket *socket);
	void UserAmericanPlug(AmericanSocket *socket);

private:

};

