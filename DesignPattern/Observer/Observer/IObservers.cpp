#include "IObservers.h"

void IObservers::UnSubscribePublisher(IPublichser* publisher)
{
	m_subscribes.remove(publisher);
	publisher->RemoveObserver(this);
}

void IObservers::SubscribePublisher(IPublichser* publisher)
{
	for (auto publish : m_subscribes)
	{
		if (publish == publisher)
		{
			return;
		}
	}
	publisher->AddObserver(this);
	m_subscribes.push_back(publisher);
}

void IObservers::ShowInfo()
{
	std::cout << "Observer " << GetName() << std::endl;
	for (auto publish : m_subscribes)
	{
		std::cout << "	Subscriebe Publisher " << publish->GetName() << std::endl;
	}
}

IObservers::IObservers(const std::string& name) : IObserver(name)
{
	
}

IObservers::~IObservers()
{
}
