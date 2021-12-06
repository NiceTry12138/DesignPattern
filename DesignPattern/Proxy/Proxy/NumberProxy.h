#pragma once
#include "LuckyNumber.h"
#include <memory>
#include <list>

/// <summary>
/// 用户权限的enum
/// </summary>
enum class USER {
	CONSUMER,		// 普通用户
	ADMIN			// 管理员
};

/// <summary>
/// 代理LuckyNumber进行数据操作的的类
/// </summary>
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
	/// <summary>
	/// 更新缓存中的数据
	/// </summary>
	void UpdateCache(const std::string& _key, const int& _val);
	/// <summary>
	/// 添加缓存，多于指定数目的根据最久未使用的调度算法清除缓存
	/// </summary>
	void AddCache(const std::string& _key,const int &_val);
	/// <summary>
	/// 在使用时初始化LuckyNumber
	/// </summary>
	void InitNumber();
	/// <summary>
	/// 从缓存中查找目标key-value
	/// </summary>
	std::list<std::pair<std::string, int>>::iterator FindCache(const std::string& _key);
	/// <summary>
	/// 判断是否是合理的操作请求
	/// </summary>
	bool IsLegalRequest(const std::string &_key);
	
private:
	USER m_USER;									// 使用该代理对象的权限
	std::string m_UserName;							// 使用该代理对象的名称
	std::unique_ptr<Number> m_Number{ nullptr };	// unique_ptr的LuckyNumber
	std::list<std::pair<std::string, int>> m_Cache;	// 缓存
};

