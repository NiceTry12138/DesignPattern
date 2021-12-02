#ifndef SEASTAR_TEACHER_CONFIG_LIST
#define SEASTAR_TEACHER_CONFIG_LIST

#include "Teacher.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

class TeachConfigList {
public:
	static TeachConfigList& GetInstance();

	void AddTeacher(std::string _name);
	void AddTeacher(std::string _name, shared_ptr<Teacher> _teacher);
	void RemoveTeacher(const std::string &_name);
	Teacher* GetTeacherByName(const std::string &_name) const;

	void ShowTeachersInfo();
private:
	std::map<std::string, shared_ptr<Teacher>> m_teachList;

};

#endif