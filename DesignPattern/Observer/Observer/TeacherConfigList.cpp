#include "TeacherConfigList.h"

TeachConfigList& TeachConfigList::GetInstance()
{
	static TeachConfigList instance;
	return instance;
}

void TeachConfigList::AddTeacher(std::string _name)
{
}

void TeachConfigList::AddTeacher(std::string _name, shared_ptr<Teacher> _teacher)
{
	m_teachList[_name] = _teacher;
}

void TeachConfigList::RemoveTeacher(const std::string& _name)
{
	auto _target = m_teachList.find(_name);
	if (_target != m_teachList.end())
	{
		m_teachList.erase(_target);
	}
}

Teacher* TeachConfigList::GetTeacherByName(const std::string& _name) const
{
	auto _target = m_teachList.find(_name);
	if (_target != m_teachList.end())
	{
		return _target->second.get();
	}
	return nullptr;
}

void TeachConfigList::ShowTeachersInfo()
{
	std::cout << "Teacher Info : " << std::endl;

	for (auto _it = m_teachList.begin(); _it != m_teachList.end(); ++_it) {
		auto teacher = _it->second;
		teacher->ShowInfo();
	}

	std::cout << std::endl;
}
