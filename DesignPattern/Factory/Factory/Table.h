/*
 * @Autor: LC
 * @Date: 2021-11-29 17:20:41
 * @LastEditors: LC
 * @Description: Table的类
 * @LastEditTime: 2021-11-29 18:01:24
 */
#ifndef BASEOBJ_TABLE
#define BASEOBJ_TABLE

#include <iostream>
#include <string>
#include "BaseFurniture.h"
using namespace std;

class Table : public BaseFurniture
{
  public:
    Table(std::string _name) : BaseFurniture(_name + "_Table") {}
    virtual ~Table() {}
    virtual void Fun1() = 0;
    virtual void Fun2() = 0;
};

class Table_A : public Table
{
  public:
    Table_A(const std::string _name) : Table(_name + "_A") {}
    ~Table_A() {}
    void Fun1() override;
    void Fun2() override;
};

class Table_B : public Table
{
  public:
    Table_B(const std::string _name) : Table(_name + "_B") {}
    ~Table_B() {}
    void Fun1() override;
    void Fun2() override;
};

class Table_C : public Table
{
public:
    Table_C(const std::string _name) : Table(_name + "_C") {}
    ~Table_C() {}
    void Fun1() override;
    void Fun2() override;
};
#endif