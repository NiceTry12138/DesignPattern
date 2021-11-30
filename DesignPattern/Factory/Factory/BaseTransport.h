/*
 * @Version: 
 * @Autor: LC
 * @Date: 2021-11-29 19:11:42
 * @LastEditors: LC
 * @LastEditTime: 2021-11-29 19:17:31
 * @Description: 传输类基类
 */
#ifndef BASE_TRANSPORT
#define BASE_TRANSPORT

#include <iostream>
#include <vector>
#include <string>
#include "BaseFurniture.h"
using namespace std;

class BaseTransport
{
public:
    BaseTransport() {}
    virtual ~BaseTransport();
    virtual void DoTransport() = 0;
    virtual void ShowTransportInfo() = 0;

    inline int GetFurnitureNum() const;
    void ShowFurnitreInfo();
    void AddFurniture(BaseFurniture* _furniture);
    BaseFurniture* RemoveFurnitureByName(const std::string &name);

protected:
    void RemoveAllFuniture();

protected:
    std::vector<BaseFurniture*> m_transports;
};

#endif