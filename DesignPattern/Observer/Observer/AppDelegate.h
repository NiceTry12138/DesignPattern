#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Student.h"
#include "Teacher.h"

using namespace std;

class AppDelegate
{
public:
	void Run();

	void ShowCurrentInfo();
	void ModifyInfo(const std::string &info);

	void CreateStudent(int num);
	void CreateTeacher(int num);

	void Test(int StuNum, int TeaNum);

	AppDelegate();
protected:
	int RandomInt(int maxVal);

private:
	std::vector<std::unique_ptr<Teacher>> m_teachers;
	std::vector<std::unique_ptr<Student>> m_students;
};

