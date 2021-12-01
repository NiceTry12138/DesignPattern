#ifndef SEASTAR_STUDENT_CONFIG_LIST
#define SEASTAR_STUDENT_CONFIG_LIST

#include <map>
#include <memory>
#include "Student.h"
using namespace std;

class StudentConfigList {
public:
	static StudentConfigList& GetInstance();

	void AddStudent(std::string _name, shared_ptr<Student> _teacher);
	void RemoveStudent(const std::string& _name);
	Student* GetStudentByName(const std::string& _name) const;

	void ShowStudensInfo();
private:
	std::map<std::string, shared_ptr<Student>> m_studentList;

};

#endif