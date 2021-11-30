#ifndef FACTORY
#define FACTORY

#include <iostream>
#include <map>
#include "Chair.h"
#include "Sofa.h"
#include "Table.h"
using namespace std;

// �Ҿ߹�������
class FurnitureFactory {
public:
	FurnitureFactory() {}
	virtual ~FurnitureFactory() {}
	virtual Table* CreateTable(const std::string &name) = 0;
	virtual Chair* CreateChair(const std::string& name) = 0;
	virtual Sofa* CreateSofa(const std::string& name) = 0;
};

// �Ҿ�A�๤��
class Factory_A : public FurnitureFactory {
public:
	Factory_A() {}
	~Factory_A() {}
	Table* CreateTable(const std::string& name) override;
	Chair* CreateChair(const std::string& name) override;
	Sofa* CreateSofa(const std::string& name) override;
};

// �Ҿ�B�๤��
class Factory_B : public FurnitureFactory {
public:
	Factory_B() {}
	~Factory_B() {}
	Table* CreateTable(const std::string& name) override;
	Chair* CreateChair(const std::string& name) override;
	Sofa* CreateSofa(const std::string& name) override;
};

// �Ҿ�C�๤��
class Factory_C : public FurnitureFactory {
public:
	Factory_C() {}
	~Factory_C() {}
	Table* CreateTable(const std::string& name) override;
	Chair* CreateChair(const std::string& name) override;
	Sofa* CreateSofa(const std::string& name) override;
};

class FurnitureCreateFactory {
public:
	void AddFurnitureFactory(std::string key, FurnitureFactory* factory);
	Table* CreateTable(const std::string key, const std::string &name);
	Chair* CreateChair(const std::string key, const std::string& name);
	Sofa* CreateSofa(const std::string key, const std::string& name);
private:
	std::map<std::string, FurnitureFactory*> m_furnitures;
};

#endif