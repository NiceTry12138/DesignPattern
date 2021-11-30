/*
 * @Author: LC
 * @Date: 2021-11-29 16:45:22
 * @LastEditTime: 2021-11-29 18:00:22
 * @LastEditors: LC
 * @Description: Chair的类
 * @FilePath: \Factory\Factory\Chair.cpp
 */
#ifndef BASEOBJ_CHAIR
#define BASEOBJ_CHAIR

#include <iostream>
#include <string>
#include "BaseFurniture.h"
using namespace std;

class Chair : public BaseFurniture
{
  public:
	Chair(const std::string _name) : BaseFurniture(_name + "_Chair") {}
	virtual ~Chair() {}
	virtual void Fun1() = 0;
	virtual void Fun2() = 0;
};

class Chair_A : public Chair
{
  public:
	Chair_A(const std::string _name) : Chair(_name + "_A") {}
	void Fun1() override;
	void Fun2() override;
};

class Chair_B : public Chair
{
  public:
	Chair_B(const std::string _name) : Chair(_name + "_B") {}
	void Fun1() override;
	void Fun2() override;
};

class Chair_C : public Chair
{
public:
	Chair_C(const std::string _name) : Chair(_name + "_C") {}
	void Fun1() override;
	void Fun2() override;
};

#endif