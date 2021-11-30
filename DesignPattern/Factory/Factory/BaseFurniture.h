/*
 * @Autor: LC
 * @Date: 2021-11-29 18:47:27
 * @LastEditors: LC
 * @LastEditTime: 2021-11-29 18:50:54
 * @Description: 家具基类
 */
#ifndef BASEOBJ_FURNITURE
#define BASEOBJ_FURNITURE

#include <string>
#include <iostream>
using namespace std;

class BaseFurniture
{
public:
    BaseFurniture(const std::string& _name) : m_name(_name) {}
    virtual ~BaseFurniture();
    std::string getName() const;
    void setName(const std::string _name);
    virtual void Func();

private:
    std::string m_name;
};

#endif