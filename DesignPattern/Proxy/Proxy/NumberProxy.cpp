#include "NumberProxy.h"
#include <iostream>

NumberProxy::NumberProxy(USER _user, const std::string& _name) : m_USER(_user), m_UserName(_name)
{
}

std::pair<bool, int> NumberProxy::generate(std::string animal)
{
	if (!IsLegalRequest(animal))
	{
		std::cout << "ERROR : Normal User Can Only Request Yourself Data!" << std::endl;
		return { false , 0 };
	}
	InitNumber();
	auto it = FindCache(animal);
	if (it != m_Cache.end())
	{
		auto _pair = std::make_pair(it->first, it->second);
		m_Cache.erase(it);
		m_Cache.push_back(_pair);
		return { true, _pair.second };
	}
	auto getVal = m_Number->generate(animal);
	if (getVal.first)
	{
		AddCache(animal, getVal.second);
	}
	return getVal;
}

void NumberProxy::Update(std::string _key, int _val)
{
	if (!IsLegalRequest(_key))
	{
		std::cout << "ERROR : Normal User Can Only Update Yourself Data!" << std::endl;
	}
	InitNumber();
	UpdateCache(_key, _val);
	m_Number->Update(_key, _val);	
}

void NumberProxy::Remove(std::string _key)
{
	if (!IsLegalRequest(_key))
	{
		std::cout << "ERROR : Normal User Can Only Remove Yourself Data!" << std::endl;
	}
	InitNumber();
	auto it = FindCache(_key);
	if (it != m_Cache.end())
	{
		m_Cache.erase(it);
	}
	m_Number->Remove(_key);
}

void NumberProxy::Add(std::string _key, int _val)
{
	if (!IsLegalRequest(_key))
	{
		std::cout << "ERROR : Normal User Can Only Add Yourself Data!" << std::endl;
	}
	InitNumber();
	UpdateCache(_key, _val);
	m_Number->Add(_key, _val);
}

void NumberProxy::ShowInfo() const
{
	if (m_Number != nullptr)
	{
		m_Number->ShowInfo();
	}
}

void NumberProxy::ShowCache() const
{
	std::cout << "Proxy Cache : " << std::endl;
	for (auto& _it : m_Cache) {
		std::cout << "\t" << _it.first << " " << _it.second << std::endl;
	}

	std::cout << std::endl;
}

void NumberProxy::AddCache(const std::string& _key, const int& _val)
{
	if (m_Cache.size() >= g_CacheMaxNumber)
	{
		m_Cache.erase(m_Cache.begin());
	}

	m_Cache.push_back(std::make_pair(_key, _val));
}

void NumberProxy::UpdateCache(const std::string& _key, const int& _val)
{
	auto it = FindCache(_key);
	if (it != m_Cache.end())
	{
		it->second = _val;
	}
}

void NumberProxy::InitNumber()
{
	if (m_Number.get() == nullptr)
	{
		m_Number.reset(new LuckyNumber());
	}
}

std::list<std::pair<std::string, int>>::iterator NumberProxy::FindCache(const std::string& _key)
{
	auto findFunction = [_key](std::pair<std::string, int>& _pair) {
		if (_pair.first == _key)
		{
			return true;
		}
		return false;
	};
	auto it = std::find_if(m_Cache.begin(), m_Cache.end(), findFunction);
	return std::move(it);
}

bool NumberProxy::IsLegalRequest(const std::string& _key)
{
	if (m_USER == USER::ADMIN)
	{
		return true;
	}
	else if (_key == m_UserName) {
		return true;
	}
	return false;
}
