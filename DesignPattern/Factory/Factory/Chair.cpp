/*
 * @Author: LC
 * @Date: 2021-11-29 16:45:22
 * @LastEditTime: 2021-11-29 18:04:54
 * @LastEditors: LC
 * @Description: Chair的类
 * @FilePath: \Factory\Factory\Chair.cpp
 */

#include "Chair.h"

void Chair_A::Fun1()
{
    std::cout << getName() + " Chair A run Fun1" << std::endl;
}

void Chair_A::Fun2()
{
    std::cout << getName() + " Chair A run Fun2" << std::endl;
}

void Chair_B::Fun1()
{
    std::cout << getName() + " Chair B run Fun1" << std::endl;
}

void Chair_B::Fun2()
{
    std::cout << getName() + " Chair B run Fun2" << std::endl;
}

void Chair_C::Fun1()
{
    std::cout << getName() + " Chair C run Fun1" << std::endl;
}

void Chair_C::Fun2()
{
    std::cout << getName() + " Chair C run Fun2" << std::endl;
}
