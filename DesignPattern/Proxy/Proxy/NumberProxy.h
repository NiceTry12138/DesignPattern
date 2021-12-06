#pragma once
#include "LuckyNumber.h"
#include <memory>
#include <list>

enum class USER {
	CONSUMER,		// 普通用户
	ADMIN			// 管理员
};

class NumberProxy : public Number
{
public:
	static const int g_CacheMaxNumber = 10;

public:
	NumberProxy(USER _user, const std::string& _name);
	virtual std::pair<bool, int> generate(std::string animal) override;
	virtual void Update(std::string _key, int _val);
	virtual void Remove(std::string _key);
	virtual void Add(std::string _key, int _val);

	virtual void ShowInfo() const;
	void ShowCache() const;

protected:
	void UpdateCache(const std::string& _key, const int& _val);
	void AddCache(const std::string& _key,const int &_val);
	void InitNumber();
	std::list<std::pair<std::string, int>>::iterator FindCache(const std::string& _key);
	bool IsLegalRequest(const std::string &_key);
	
private:
	USER m_USER;
	std::string m_UserName;
	std::unique_ptr<Number> m_Number{ nullptr };
	std::list<std::pair<std::string, int>> m_Cache;
};

