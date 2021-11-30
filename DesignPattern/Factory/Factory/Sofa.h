/*
 * @Description: 沙发积累
 * @Autor: LC
 * @Date: 2021-11-29 17:33:40
 * @LastEditors: LC
 * @LastEditTime: 2021-11-29 18:01:06
 */
#ifndef BASEOBJ_SOFA
#define BASEOBJ_SOFA

#include <iostream>
#include <string>
#include "BaseFurniture.h"
using namespace std;

class Sofa : public BaseFurniture
{
  public:
    Sofa(const std::string _name) : BaseFurniture(_name + "_Sofa") {}
    virtual ~Sofa() {}
    virtual void Fun1() = 0;
    virtual void Fun2() = 0;
};

class Sofa_A : public Sofa
{
  public:
    Sofa_A(const std::string _name) : Sofa(_name + "_A") {}
    ~Sofa_A() {}
    void Fun1() override;
    void Fun2() override;
};

class Sofa_B : public Sofa
{
  public:
    Sofa_B(const std::string _name) : Sofa(_name + "_B") {}
    ~Sofa_B() {}
    void Fun1() override;
    void Fun2() override;
};

class Sofa_C : public Sofa
{
public:
    Sofa_C(const std::string _name) : Sofa(_name + "_C") {}
    ~Sofa_C() {}
    void Fun1() override;
    void Fun2() override;
};
#endif