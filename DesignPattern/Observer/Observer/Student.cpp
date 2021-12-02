#include "Student.h"

void Student::update(const std::string& info)
{
	std::cout << "Studen " << GetName() << " Get Info : " << info << std::endl;
}

void Student::ShowInfo()
{
	IObservers::ShowInfo();
}

bool Student::IsGetInfo()
{
	return true;
}

Student::Student(std::string _name) : IObservers(_name)
{
}

Student::~Student()
{
}
