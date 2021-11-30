/*
 * @Autor: LC
 * @Date: 2021-11-29 17:20:41
 * @LastEditors: LC
 * @Description: Table的类
 * @LastEditTime: 2021-11-29 18:04:21
 */

#include "Table.h"

void Table_A::Fun1()
{
	std::cout << getName() + " Table A run fun1" << std::endl;
}

void Table_A::Fun2()
{
	std::cout << getName() + " Table A run fun2" << std::endl;
}

void Table_B::Fun1()
{
	std::cout << getName() + " Table B run fun1" << std::endl;
}

void Table_B::Fun2()
{
	std::cout << getName() + " Table B run fun2" << std::endl;
}

void Table_C::Fun1()
{
	std::cout << getName() + " Table C run fun1" << std::endl;
}

void Table_C::Fun2()
{
	std::cout << getName() + " Table C run fun2" << std::endl;
}
