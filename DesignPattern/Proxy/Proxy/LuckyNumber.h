#pragma once
#include "Number.h"
#include <map>

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
    void ReadFile();

private:
    std::map<std::string, int> m_Numbers;
};

