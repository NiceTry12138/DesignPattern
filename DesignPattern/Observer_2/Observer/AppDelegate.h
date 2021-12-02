#pragma once
#include <string>

class AppDelegate
{
public:
	void Run();

	void ShowCurrentInfo();
	void ModifyInfo(const std::string &info, int TeaNum);

	void CreateStudent();

	void CreateTeacher();

	void Test(int StuNum, int TeaNum);

	AppDelegate();
protected:
	int RandomInt(int maxVal);
};

