#include "LuckyNumber.h"
#include <iostream>

using namespace std;

std::pair<bool, int> LuckyNumber::generate(std::string animal)
{
    if (m_Numbers.find(animal) == m_Numbers.end()) {
        return { false ,0 };
    }
    else {
        return { true, m_Numbers[animal] };
    }
}

void LuckyNumber::Update(std::string _key, int _val)
{
    if (m_Numbers.find(_key) == m_Numbers.end()) {
        Add(_key, _val);
    }
    m_Numbers[_key] = _val;
}

void LuckyNumber::Remove(std::string _key)
{
    m_Numbers.erase(_key);
}

void LuckyNumber::Add(std::string _key, int _val)
{
    if (m_Numbers.find(_key) == m_Numbers.end())
    {
        m_Numbers.insert(std::make_pair(_key, _val));
    }
    else {
        Update(_key, _val);
    }
}

void LuckyNumber::ShowInfo() const
{
    std::cout << "LuckNumber Info : " << std::endl;
    for (auto &_it : m_Numbers)
    {
        std::cout << "\t" << _it.first << " " << _it.second << std::endl;
    }

    std::cout << std::endl;
}

LuckyNumber::LuckyNumber()
{
    ReadFile();    
}

LuckyNumber::~LuckyNumber()
{
}

void LuckyNumber::ReadFile()
{
    m_Numbers = {
               {"Rat", 1469},
               {"Ox", 2057},
               {"Tiger", 1368},
               {"Rabbit", 1368},
               {"Dragon", 2507},
               {"Snake", 2378},
               {"Horse", 2378},
               {"Goat", 2570},
               {"Monkey", 4950},
               {"Rooster",4095},
               {"Dog", 2057},
               {"Pig", 1469},
    };
}
