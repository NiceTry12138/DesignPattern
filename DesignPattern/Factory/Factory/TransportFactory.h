/*
 * @Autor: LC
 * @Date: 2021-11-29 19:42:21
 * @LastEditors: LC
 * @LastEditTime: 2021-11-29 19:43:26
 * @Description: 传输类工厂
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

// 陆路运输工厂
class TransportLandFactory : public TransportFactory {
public:
	TransportLandFactory() {}
	~TransportLandFactory() {}
	BaseTransport* CreateTransport() override;
};

// 水路运输工厂
class TransportLiquidFactory : public TransportFactory {
public:
	TransportLiquidFactory() {}
	~TransportLiquidFactory() {}
	BaseTransport* CreateTransport() override;
};

// 航空运输工厂
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