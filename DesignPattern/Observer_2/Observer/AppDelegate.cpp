#include "AppDelegate.h"

#include "StudenConfigList.h"
#include "TeacherConfigList.h"

#include <cstdlib>

void AppDelegate::Run()
{
	Test(10, 4);
}

void AppDelegate::ShowCurrentInfo()
{
	StudentConfigList::GetInstance().ShowStudensInfo();

	TeachConfigList::GetInstance().ShowTeachersInfo();

	std::cout << std::endl;
}

void AppDelegate::ModifyInfo(const std::string& info, int TeaNum)
{
	for (int i=0; i<TeaNum; ++i)
	{
		TeachConfigList::GetInstance().GetTeacherByName("Teacher_" + std::to_string(i))->Modify(info);
	}
}

void AppDelegate::CreateStudent()
{
	std::cout << "Please Input Student Name : " << std::endl;
	std::string name{};
	cin >> name;
	Student::Create(name);
	std::cout << "Create Student Finish" << std::endl;
}

void AppDelegate::CreateTeacher()
{
	std::cout << "Please Input Teacher Name : " << std::endl;
	std::string name{};
	cin >> name;
	Teacher::Create(name);
	std::cout << "Create Student Finish" << std::endl;
}

void AppDelegate::Test(int StuNum, int TeaNum)
{
	for (int i = 0; i < TeaNum; ++i) {
		Teacher::Create("Teacher_" + std::to_string(i));
	}

	std::cout << std::endl;

	for (int i = 0; i < StuNum; ++i) {
		auto stu = Student::Create("Student_" + std::to_string(i));
		for (int teaID = 0; teaID < TeaNum; ++teaID)
		{
			TeachConfigList::GetInstance().GetTeacherByName("Teacher_" + std::to_string(teaID))->AddObserver(stu);
		}
	}

	for (int i = 0; i < StuNum; ++i) {
		std::string unSubTeachName = "Teacher_" + std::to_string(RandomInt(TeaNum));
		auto stu = StudentConfigList::GetInstance().GetStudentByName("Student_" + std::to_string(i));
		//stu->RemoveRegisterPublisher(unSubTeachName);
		TeachConfigList::GetInstance().GetTeacherByName(unSubTeachName)->RemoveObserver(stu);
	}

	std::cout << std::endl;

	for (int i = 0; i < TeaNum; ++i) {
		auto stu = StudentConfigList::GetInstance().GetStudentByName("Student_" + std::to_string(RandomInt(StuNum)));
		TeachConfigList::GetInstance().GetTeacherByName("Teacher_" + std::to_string(i))->RemoveObserver(stu);
	}

	std::cout << std::endl;

	ShowCurrentInfo();

	ModifyInfo("homework status update, please Notice That", TeaNum);
}

AppDelegate::AppDelegate()
{
	srand((int)time(0));
}

int AppDelegate::RandomInt(int maxVal)
{
	return rand() % maxVal;
}
