/*
 * @Autor: LC
 * @Date: 2021-11-29 19:42:21
 * @LastEditors: LC
 * @LastEditTime: 2021-11-29 19:43:26
 * @Description: �����๤��
 */
#ifndef TRANSPORT_FACTORY
#define TRANSPORT_FACTORY

#include "TransportMethod.h"
#include <map>
using namespace std;

class TransportFactory {
public:
	virtual BaseTransport* CreateTransport() = 0;
	TransportFactory() {}
	virtual ~TransportFactory() {}
};

// ½·���乤��
class TransportLandFactory : public TransportFactory {
public:
	TransportLandFactory() {}
	~TransportLandFactory() {}
	BaseTransport* CreateTransport() override;
};

// ˮ·���乤��
class TransportLiquidFactory : public TransportFactory {
public:
	TransportLiquidFactory() {}
	~TransportLiquidFactory() {}
	BaseTransport* CreateTransport() override;
};

// �������乤��
class TransportAirFactory : public TransportFactory {
public:
	TransportAirFactory() {}
	~TransportAirFactory() {}
	BaseTransport* CreateTransport() override;
};

class TransportCreateFactory {
public:
	void AddTransportFactory(std::string key, TransportFactory* factory);
	BaseTransport* CreateTransport(const std::string key);
	~TransportCreateFactory();
private:
	std::map<std::string, TransportFactory*> m_factories;
};

#endif