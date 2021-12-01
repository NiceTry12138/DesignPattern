#ifndef FACTORY
#define FACTORY

#include <iostream>
#include <map>
#include "Chair.h"
#include "Sofa.h"
#include "Table.h"
using namespace std;
class FurnitureFactory;
class FurnitureCreateFactory {
public:
	static FurnitureCreateFactory& GetInstance();

public:
	void AddFurnitureFactory(std::string key, FurnitureFactory* factory);
	Table* CreateTable(const std::string key, const std::string& name);
	Chair* CreateChair(const std::string key, const std::string& name);
	Sofa* CreateSofa(const std::string key, const std::string& name);

	~FurnitureCreateFactory();

	FurnitureCreateFactory(const FurnitureCreateFactory&) = delete;    // 不允许拷贝构造
	FurnitureCreateFactory& operator=(const FurnitureCreateFactory&) = delete;
private:
	FurnitureCreateFactory() = default;

	std::map<std::string, FurnitureFactory*> m_furnitures;
};
// 家具工厂基类
class FurnitureFactory {
public:
	FurnitureFactory(const std::string& name) : m_name(name) {
		FurnitureCreateFactory::GetInstance().AddFurnitureFactory(name, this);
	}
	virtual ~FurnitureFactory() {}
	virtual Table* CreateTable(const std::string &name) = 0;
	virtual Chair* CreateChair(const std::string& name) = 0;
	virtual Sofa* CreateSofa(const std::string& name) = 0;

private:
	std::string m_name;
};

// 家具A类工厂
class Factory_A : public FurnitureFactory {
public:
	Factory_A() : FurnitureFactory("A") {}
	~Factory_A() {}
	Table* CreateTable(const std::string& name) override;
	Chair* CreateChair(const std::string& name) override;
	Sofa* CreateSofa(const std::string& name) override;

private:
	static Factory_A _self;
};

// 家具B类工厂
class Factory_B : public FurnitureFactory {
public:
	Factory_B() : FurnitureFactory("B") {}
	~Factory_B() {}
	Table* CreateTable(const std::string& name) override;
	Chair* CreateChair(const std::string& name) override;
	Sofa* CreateSofa(const std::string& name) override;

private:
	static Factory_B _self;
};

// 家具C类工厂
class Factory_C : public FurnitureFactory {
public:
	Factory_C() : FurnitureFactory("C") {}
	~Factory_C() {}
	Table* CreateTable(const std::string& name) override;
	Chair* CreateChair(const std::string& name) override;
	Sofa* CreateSofa(const std::string& name) override;

private:
	static Factory_C _self;
};

#endif