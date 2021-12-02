#include "Teacher.h"
#include "TeacherConfigList.h"

Teacher* Teacher::Create(std::string _name)
{
	auto teacher = make_shared<Teacher>(_name);
	TeachConfigList::GetInstance().AddTeacher(_name, teacher);
	return teacher.get();
}

void Teacher::ShowInfo()
{
	std::cout << "Teacher Name " << GetName() << std::endl;
	IPublichser::ShowInfo();
}

Teacher::Teacher(std::string _name) : IPublichser(_name)
{
}

Teacher::~Teacher()
{
	std::cout << "___ teacher " << GetName() << " ~ delete" << std::endl;
}
