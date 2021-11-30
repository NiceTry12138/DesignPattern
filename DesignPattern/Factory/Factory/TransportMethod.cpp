#include "TransportMethod.h"

void TransportLand::DoTransport()
{	
	std::cout << "TransportLand DoTransport!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	RemoveAllFuniture();
}

void TransportLand::ShowTransportInfo()
{
	std::cout << "TransportLand num " << m_transports.size() << std::endl;
}

void TransportLiquid::DoTransport()
{
	std::cout << "TransportLiquid DoTransport!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	RemoveAllFuniture();
}

void TransportLiquid::ShowTransportInfo()
{
	std::cout << "TransportLiquid num " << m_transports.size() << std::endl;
}

void TransportAir::DoTransport()
{
	std::cout << "TransportAir DoTransport!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	RemoveAllFuniture();
}

void TransportAir::ShowTransportInfo()
{
	std::cout << "TransportAir num " << m_transports.size() << std::endl;
}
