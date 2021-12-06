#pragma once
#include "Number.h"
#include <map>

/// <summary>
/// �������ݿ��ʵ����
/// </summary>
class LuckyNumber : public Number
{
public:
    std::pair<bool, int> generate(std::string animal) override;
    virtual void Update(std::string _key, int _val);
    virtual void Remove(std::string _key);
    virtual void Add(std::string _key, int _val);
    virtual void ShowInfo() const;
    LuckyNumber();
    virtual ~LuckyNumber();

protected:
    /// <summary>
    /// ��ȡ�ļ��������ݴ洢��m_Numbers��
    /// </summary>
    void ReadFile();

private:
    std::map<std::string, int> m_Numbers; // �洢����KV����
};

