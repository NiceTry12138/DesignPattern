/*
 * @Version: 
 * @Autor: LC
 * @Date: 2021-12-01 16:19:43
 * @LastEditors: LC
 * @LastEditTime: 2021-12-01 16:20:04
 * @Description: file content
 */
#ifndef SEASTAR_STUDENT
#define SEASTAR_STUDENT

#include "IObserver.h"
#include <vector>
#include <string>

using namespace std;

class Student : public IObserver {
public:
	static Student* Create(const std::string &name);

public:
	void update(const std::string& info) override;

	void ShowInfo();

	Student(std::string _name);
	~Student();

private:
};

#endif