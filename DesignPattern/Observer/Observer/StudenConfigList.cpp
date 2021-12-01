#include "StudenConfigList.h"

StudentConfigList& StudentConfigList::GetInstance()
{
	static StudentConfigList instance;
	return instance;
}

void StudentConfigList::AddStudent(std::string _name, shared_ptr<Student> _teacher)
{
	m_studentList[_name] = _teacher;
}

void StudentConfigList::RemoveStudent(const std::string& _name)
{
	auto _target = m_studentList.find(_name);
	if (_target != m_studentList.end())
	{
		m_studentList.erase(_target);
	}
}

Student* StudentConfigList::GetStudentByName(const std::string& _name) const
{
	auto _target = m_studentList.find(_name);
	if (_target != m_studentList.end())
	{
		return _target->second.get();
	}
	return nullptr;
}

void StudentConfigList::ShowStudensInfo()
{
	std::cout << "Teacher Info : " << std::endl;

	for (auto _it = m_studentList.begin(); _it != m_studentList.end(); ++_it) {
		auto student = _it->second;
		student->ShowInfo();
	}

	std::cout << std::endl;
}
