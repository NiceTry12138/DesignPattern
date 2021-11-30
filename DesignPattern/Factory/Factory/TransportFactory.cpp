#include "TransportFactory.h"

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
	for (auto _it = m_factories.begin(); _it != m_factories.end(); ++_it)
	{
		delete _it->second;
		_it->second = nullptr;
		m_factories.erase(_it);
	}
}
