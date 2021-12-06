#pragma once
#include <string>

/// <summary>
/// Number基类，提供需要实现的基础功能
/// </summary>
class Number {
public:
    // 查询 animal对应的值
    virtual std::pair<bool, int> generate(std::string animal) = 0;
    // 更新_key对应的值为_val
    virtual void Update(std::string _key, int _val) = 0;
    // 删除_key对应的值
    virtual void Remove(std::string _key) = 0;
    // 添加_key和_val的键值对
    virtual void Add(std::string _key, int _val) = 0;
    // 展示存储的功能
    virtual void ShowInfo() const = 0;
    virtual ~Number() = default;
};