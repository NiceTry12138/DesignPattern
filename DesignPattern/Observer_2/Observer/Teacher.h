/*
 * @Version: 
 * @Autor: LC
 * @Date: 2021-12-01 16:20:33
 * @LastEditors: LC
 * @LastEditTime: 2021-12-01 16:20:57
 * @Description: file content
 */
#ifndef SEASTAR_TEACHER
#define SEASTAR_TEACHER

#include "IPublisher.h"
#include <string>
#include <memory>

using namespace std;

class Teacher : public IPublichser {
public:
	static Teacher* Create(std::string _name);

public:
	void ShowInfo();
	Teacher(std::string _name);
	~Teacher();
};

#endif