#include "FurnitureFactory.h"

Factory_A Factory_A::_self;

Factory_B Factory_B::_self;

Factory_C Factory_C::_self;

Table* Factory_A::CreateTable(const std::string& name)
{
	return new Table_A(name);
}

Chair* Factory_A::CreateChair(const std::string& name)
{
	return new Chair_A(name);
}

Sofa* Factory_A::CreateSofa(const std::string& name)
{
	return new Sofa_A(name);
}

Table* Factory_B::CreateTable(const std::string& name)
{
	return new Table_B(name);
}

Chair* Factory_B::CreateChair(const std::string& name)
{
	return new Chair_B(name);
}

Sofa* Factory_B::CreateSofa(const std::string& name)
{
	return new Sofa_B(name);
}

Table* Factory_C::CreateTable(const std::string& name)
{
	return new Table_C(name);
}

Chair* Factory_C::CreateChair(const std::string& name)
{
	return new Chair_C(name);
}

Sofa* Factory_C::CreateSofa(const std::string& name)
{
	return new Sofa_C(name);
}

FurnitureCreateFactory& FurnitureCreateFactory::GetInstance()
{
	static FurnitureCreateFactory _factory;
	return _factory;
}

void FurnitureCreateFactory::AddFurnitureFactory(std::string key, FurnitureFactory* factory)
{
	m_furnitures.insert(std::pair<std::string, FurnitureFactory*>(key, factory));
}

Table* FurnitureCreateFactory::CreateTable(const std::string key, const std::string& name)
{
	if (m_furnitures.find(key) != m_furnitures.end()) {
		return m_furnitures[key]->CreateTable(name);
	}
	std::cout << key + " Table con't create" << std::endl;
	return nullptr;
}

Chair* FurnitureCreateFactory::CreateChair(const std::string key, const std::string& name)
{
	if (m_furnitures.find(key) != m_furnitures.end()) {
		return m_furnitures[key]->CreateChair(name);
	}
	std::cout << key + " Chair con't create" << std::endl;
	return nullptr;
}

Sofa* FurnitureCreateFactory::CreateSofa(const std::string key, const std::string& name)
{
	if (m_furnitures.find(key) != m_furnitures.end()) {
		return m_furnitures[key]->CreateSofa(name);
	}
	std::cout << key + " Sofa con't create" << std::endl;
	return nullptr;
}

FurnitureCreateFactory::~FurnitureCreateFactory()
{
}
