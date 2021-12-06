#pragma once
#include "LuckyNumber.h"
#include <memory>
#include <list>

/// <summary>
/// �û�Ȩ�޵�enum
/// </summary>
enum class USER {
	CONSUMER,		// ��ͨ�û�
	ADMIN			// ����Ա
};

/// <summary>
/// ����LuckyNumber�������ݲ����ĵ���
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
	/// ���»����е�����
	/// </summary>
	void UpdateCache(const std::string& _key, const int& _val);
	/// <summary>
	/// ��ӻ��棬����ָ����Ŀ�ĸ������δʹ�õĵ����㷨�������
	/// </summary>
	void AddCache(const std::string& _key,const int &_val);
	/// <summary>
	/// ��ʹ��ʱ��ʼ��LuckyNumber
	/// </summary>
	void InitNumber();
	/// <summary>
	/// �ӻ����в���Ŀ��key-value
	/// </summary>
	std::list<std::pair<std::string, int>>::iterator FindCache(const std::string& _key);
	/// <summary>
	/// �ж��Ƿ��Ǻ���Ĳ�������
	/// </summary>
	bool IsLegalRequest(const std::string &_key);
	
private:
	USER m_USER;									// ʹ�øô�������Ȩ��
	std::string m_UserName;							// ʹ�øô�����������
	std::unique_ptr<Number> m_Number{ nullptr };	// unique_ptr��LuckyNumber
	std::list<std::pair<std::string, int>> m_Cache;	// ����
};

