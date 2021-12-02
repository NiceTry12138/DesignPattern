/*
 * @Version: 
 * @Autor: LC
 * @Date: 2021-12-01 16:18:33
 * @LastEditors: LC
 * @LastEditTime: 2021-12-01 16:18:44
 * @Description: file content
 */
#include "IPublisher.h"

void IPublichser::AddObserver(IObserver* obs)
{
	for (auto _it : m_oberserList) {
		if (_it == obs)
		{
			return;
		}
	}
	obs->AddRegisterPublisher(m_name);
	m_oberserList.push_back(obs);
}

void IPublichser::RemoveObserver(IObserver* obs)
{
	obs->RemoveRegisterPublisher(m_name);
	m_oberserList.remove(obs);
}

void IPublichser::Modify(const std::string& info)
{
	for (auto obs : m_oberserList) {
		std::cout << "	" << m_name << " Notice ";
 		obs->update(info);
	}
	std::cout << std::endl;
}

IPublichser::IPublichser(const std::string& name) : m_name(name)
{
}

std::string IPublichser::GetName() const
{
	return this->m_name;
}

void IPublichser::ShowInfo()
{
	for (auto iObserve : m_oberserList)
	{
		std::cout << "	Register Observer " << iObserve->GetName() << std::endl;
	}
}
