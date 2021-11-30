#include "BaseFurniture.h"
/*
 * @Version: 
 * @Autor: LC
 * @Date: 2021-11-29 18:47:47
 * @LastEditors: LC
 * @LastEditTime: 2021-11-29 18:49:07
 * @Description: file content
 */

BaseFurniture::~BaseFurniture()
{
	//std::cout << "remove " + m_name << std::endl;
}

std::string BaseFurniture::getName() const
{
	return this->m_name;
}

void BaseFurniture::setName(const std::string _name)
{
	this->m_name = _name;
}

void BaseFurniture::Func()
{
	std::cout << "this is a Furniture" << std::endl;
}
