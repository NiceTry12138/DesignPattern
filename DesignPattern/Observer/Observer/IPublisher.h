/*
 * @Version: 
 * @Autor: LC
 * @Date: 2021-12-01 16:13:53
 * @LastEditors: LC
 * @LastEditTime: 2021-12-01 16:17:24
 * @Description: file content
 */
#ifndef I_PUBLISHER
#define I_PUBLISHER

#include <iostream>
#include <list>
#include <string>
#include <memory>
#include "IObserver.h"

class IPublichser
{
  public:
    void AddObserver(IObserver* obs);
    void RemoveObserver(IObserver* obs);
    virtual void Modify(const std::string &info);

    ~IPublichser() = default;
    IPublichser(const std::string &name);

    std::string GetName() const;

    void ShowInfo();

private:
    std::list<IObserver*> m_oberserList;
    std::string m_name;
};

#endif