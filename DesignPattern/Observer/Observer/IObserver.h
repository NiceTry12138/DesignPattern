/*
 * @Version: 
 * @Autor: LC
 * @Date: 2021-12-01 16:11:30
 * @LastEditors: LC
 * @LastEditTime: 2021-12-01 16:17:58
 * @Description: file content
 */
#ifndef I_OBSERVER
#define I_OBSERVER

#include <string>
#include <list>
#include <iostream>

class IObserver
{
public:
    virtual void update(const std::string& info) = 0;
    virtual ~IObserver() = default;
    IObserver(const std::string& name);

    std::string GetName() const;

    virtual bool IsGetInfo() = 0;

private:
    std::string m_name;
};

#endif