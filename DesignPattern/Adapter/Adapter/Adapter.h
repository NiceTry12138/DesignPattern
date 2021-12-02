#pragma once

#include "AmericanSocket.h"
#include "ChineseSocket.h"

class Adapter : public AmericanSocket, public ChineseSocket
{
public:
	Adapter(ChineseSocket* ChineseSocket, AmericanSocket* AmericanSocket);
	
	std::string AmericanSocketInput() const;
	std::string ChineseSocketInput() const;

	void SetCurrentVoltag(int voltag);
protected:

private:
	ChineseSocket* m_ChineseSocket{ nullptr };
	AmericanSocket* m_AmericanSocket{ nullptr };
};

