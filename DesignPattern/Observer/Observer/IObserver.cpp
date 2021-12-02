#include "IObserver.h"

IObserver::IObserver(const std::string& name) : m_name(name)
{
}

std::string IObserver::GetName() const
{
	return m_name;
}
