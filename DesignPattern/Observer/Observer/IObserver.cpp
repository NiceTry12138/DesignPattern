#include "IObserver.h"

IObserver::IObserver(const std::string& name) : m_name(name)
{
}

std::string IObserver::GetName() const
{
	return m_name;
}


void IObserver::AddRegisterPublisher(const std::string& publishName)
{
	for (auto _name : m_registPublisher)
	{
		if (publishName == _name)
		{
			return;
		}
	}
	m_registPublisher.push_back(publishName);
	std::cout << "Observer " << m_name << " Subscribe " << publishName << std::endl;
}

void IObserver::RemoveRegisterPublisher(const std::string& publishName)
{
	m_registPublisher.remove(publishName);
	std::cout << "Observer " << m_name << " UnSubscribe " << publishName << std::endl;
}

void IObserver::ShowInfo()
{
	for (auto publisher : m_registPublisher)
	{
		std::cout << "	Register Publisher Name " << publisher << std::endl;
	}
}
