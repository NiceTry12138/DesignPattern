#include "Adapter.h"

Adapter::Adapter(ChineseSocket* ChineseSocket, AmericanSocket* AmericanSocket) : m_ChineseSocket(ChineseSocket), m_AmericanSocket(AmericanSocket)
{

}

std::string Adapter::AmericanSocketInput() const
{
	return this->m_ChineseSocket->ChineseSocketInput();
}

std::string Adapter::ChineseSocketInput() const
{
	return this->m_AmericanSocket->AmericanSocketInput();
}

void Adapter::SetCurrentVoltag(int voltag)
{
	if (voltag != BaseSocket::GetRatedVoltag())
	{
		voltag = BaseSocket::GetRatedVoltag();
	}
	BaseSocket::SetCurrentVoltag(voltag);
}
