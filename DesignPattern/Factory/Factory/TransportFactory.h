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

class TransportFactory;

class TransportCreateFactory {
public:
	static TransportCreateFactory& GetInstance();

public:
	void AddTransportFactory(std::string key, TransportFactory* factory);
	BaseTransport* CreateTransport(const std::string key);
	~TransportCreateFactory();
	TransportCreateFactory(const TransportCreateFactory&) = delete;    // ������������
	TransportCreateFactory& operator=(const TransportCreateFactory&) = delete;
private:
	TransportCreateFactory() = default;

	std::map<std::string, TransportFactory*> m_factories;
};

class TransportFactory {
public:
	virtual BaseTransport* CreateTransport() = 0;
	TransportFactory(const std::string& name) : m_factoryName(name) { TransportCreateFactory::GetInstance().AddTransportFactory(name, this); }
	virtual ~TransportFactory() {}

private:
	std::string m_factoryName;
};

// ½·���乤��
class TransportLandFactory : public TransportFactory {
public:
	TransportLandFactory() : TransportFactory("Land") {}
	~TransportLandFactory() {}
	BaseTransport* CreateTransport() override;
private:
	static TransportLandFactory _self;
};

// ˮ·���乤��
class TransportLiquidFactory : public TransportFactory {
public:
	TransportLiquidFactory() : TransportFactory("Liquid") {}
	~TransportLiquidFactory() {}
	BaseTransport* CreateTransport() override;
private:
	static TransportLiquidFactory _self;
};

// �������乤��
class TransportAirFactory : public TransportFactory {
public:
	TransportAirFactory() : TransportFactory("Air") {}
	~TransportAirFactory() {}
	BaseTransport* CreateTransport() override;
private:
	static TransportAirFactory _self;
};

#endif