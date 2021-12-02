#pragma once

#include "IPublisher.h"
#include <list>

class IObservers : public IObserver
{
public:
	void UnSubscribePublisher(IPublichser* publisher);
	void SubscribePublisher(IPublichser* publisher);
	void ShowInfo();
	IObservers(const std::string& name);
	virtual ~IObservers();
private:
	std::list<IPublichser*> m_subscribes;
};

