#include "Student.h"
#include "StudenConfigList.h"

Student* Student::Create(const std::string& name)
{
	auto student = make_shared<Student>(name);
	StudentConfigList::GetInstance().AddStudent(name, student);
	return student.get();
}

void Student::update(const std::string& info)
{
	std::cout << "	" << GetName() << " get info : " << info << std::endl;
}

void Student::ShowInfo()
{
	std::cout << "Student Name " << GetName() << std::endl;
	IObserver::ShowInfo();
}

Student::Student(std::string _name) : IObserver(_name)
{
}

Student::~Student()
{
	std::cout << "___ Student " << GetName() << " ~ delete" << std::endl;
}