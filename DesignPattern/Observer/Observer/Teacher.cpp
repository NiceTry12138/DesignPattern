#include "Teacher.h"

void Teacher::AddObserver(IObservers* obs)
{
	obs->SubscribePublisher(this);
	IPublichser::AddObserver(obs);
}

void Teacher::RemoveObserver(IObservers* obs)
{
	obs->UnSubscribePublisher(this);
	IPublichser::RemoveObserver(obs);
}

void Teacher::Modify(const std::string& info)
{
	std::cout << "Teacher " << GetName() << " Send HomeWork" << std::endl;
	IPublichser::Modify(info);
}

Teacher::Teacher(std::string _name) :IPublichser(_name)
{
}

Teacher::~Teacher()
{
}
