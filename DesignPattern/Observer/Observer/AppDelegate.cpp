#include "AppDelegate.h"

#include <cstdlib>
#include <time.h>

void AppDelegate::Run()
{
	Test(5, 2);
}

void AppDelegate::ShowCurrentInfo()
{
	for (auto stu : m_students)
	{
		stu->ShowInfo();
	}
	std::cout << std::endl;
	for (auto tea : m_teachers)
	{
		tea->ShowInfo();
	}
	std::cout << std::endl;
}

void AppDelegate::ModifyInfo(const std::string& info)
{
	for (auto tea : m_teachers)
	{
		tea->Modify(info);
	}
}

void AppDelegate::CreateStudent(int num)
{
	for (int i = 0; i < num; ++i)
	{
		std::shared_ptr<Student> student(new Student("Student_" + std::to_string(i)));
		m_students.push_back(student);
	}
}

void AppDelegate::CreateTeacher(int num)
{
	for (int i = 0; i < num; ++i)
	{
		std::shared_ptr<Teacher> teacher(new Teacher("Teacher_" + std::to_string(i)));
		m_teachers.push_back(teacher);
	}
}

void AppDelegate::Test(int StuNum, int TeaNum)
{
	CreateStudent(StuNum);
	CreateTeacher(TeaNum);

	// 老师添加观察者
	for (auto stu : m_students)
	{
		for (auto tea : m_teachers)
		{
			tea->AddObserver(stu.get());
		}
	}

	// 学生取消订阅
	for (auto stu : m_students)
	{
		int randomTeaIndex = RandomInt(m_teachers.size());
		stu->UnSubscribePublisher(m_teachers[randomTeaIndex].get());
	}

	// 老师删除观察者
	for (auto tea : m_teachers)
	{
		int randomStuIndex = RandomInt(m_students.size());
		tea->RemoveObserver(m_students[randomStuIndex].get());
	}

	// 学生订阅老师
	for (auto stu : m_students)
	{
		int randomTeaIndex = RandomInt(m_teachers.size());
		stu->SubscribePublisher(m_teachers[randomTeaIndex].get());
	}

	ShowCurrentInfo();

	ModifyInfo("Math Homework status update, please Notice That");
}

AppDelegate::AppDelegate()
{
	srand((int)time(0));
}

int AppDelegate::RandomInt(int maxVal)
{
	return rand() % maxVal;
}
