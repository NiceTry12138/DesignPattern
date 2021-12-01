#include "TransportFactory.h"

TransportLandFactory TransportLandFactory::_self;

TransportLiquidFactory TransportLiquidFactory::_self;

TransportAirFactory TransportAirFactory::_self;

BaseTransport* TransportLandFactory::CreateTransport()
{
	return new TransportLand();
}

BaseTransport* TransportLiquidFactory::CreateTransport()
{
	return new TransportLiquid();
}

BaseTransport* TransportAirFactory::CreateTransport()
{
	return new TransportAir();
}

TransportCreateFactory& TransportCreateFactory::GetInstance()
{
	static TransportCreateFactory instance;
	return instance;
	// TODO: �ڴ˴����� return ���
}

void TransportCreateFactory::AddTransportFactory(std::string key, TransportFactory* factory)
{
	m_factories.insert(std::pair<std::string, TransportFactory*>(key, factory));
}

BaseTransport* TransportCreateFactory::CreateTransport(const std::string key)
{
	if (m_factories.find(key) != m_factories.end()) {
		return m_factories[key]->CreateTransport();
	}
	std::cout << key + " Transport can't create" << std::endl;
	return nullptr;
}

TransportCreateFactory::~TransportCreateFactory()
{
}