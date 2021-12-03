#include "Adapter.h"

Adapter::Adapter(ChineseSocket* ChineseSocket, AmericanSocket* AmericanSocket) : m_ChineseSocket(ChineseSocket), m_AmericanSocket(AmericanSocket)
{

}

Adapter::Adapter(ChineseSocket* ChineseSocket) : m_ChineseSocket(ChineseSocket), m_AmericanSocket(nullptr)
{
}

Adapter::Adapter(AmericanSocket* AmericanSocket) : m_ChineseSocket(nullptr), m_AmericanSocket(AmericanSocket)
{
}

std::string Adapter::AmericanSocketInput() const
{
	if (m_ChineseSocket == nullptr)
	{
		return "Error : No Sockeet Input";
	}
	return this->m_ChineseSocket->ChineseSocketInput();
}

std::string Adapter::ChineseSocketInput() const
{
	if (m_AmericanSocket == nullptr)
	{
		return "Error : No Sockeet Input";
	}
	return this->m_AmericanSocket->AmericanSocketInput();
}

void Adapter::SetCurrentVoltag(int voltag)
{
	if (m_AmericanSocket != nullptr)
	{
		voltag = m_AmericanSocket->GetRatedVoltag();	// ��ѹת��������Ķ��ѹ
		m_AmericanSocket->SetCurrentVoltag(voltag);
	}

	if (m_ChineseSocket != nullptr)
	{
		voltag = m_ChineseSocket->GetRatedVoltag();		// ��ѹת���ɹ���Ķ��ѹ
		m_ChineseSocket->SetCurrentVoltag(voltag);
	}
}
