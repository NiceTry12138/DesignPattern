#pragma once
#include <string>

class Number {
public:
    virtual std::pair<bool, int> generate(std::string animal) = 0;
    virtual void Update(std::string _key, int _val) = 0;
    virtual void Remove(std::string _key) = 0;
    virtual void Add(std::string _key, int _val) = 0;
    virtual void ShowInfo() const = 0;
    virtual ~Number() = default;
};