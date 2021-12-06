#pragma once
#include "Number.h"
#include <map>

/// <summary>
/// 访问数据库的实体类
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
    /// 读取文件，将数据存储到m_Numbers中
    /// </summary>
    void ReadFile();

private:
    std::map<std::string, int> m_Numbers; // 存储数据KV对象
};

