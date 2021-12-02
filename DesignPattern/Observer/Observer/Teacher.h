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
#include "IObservers.h"
#include <string>
#include <memory>

using namespace std;

class Teacher : public IPublichser {
public:
	//static Teacher* Create(std::string _name);
	void AddObserver(IObservers* obs);
	void RemoveObserver(IObservers* obs);

public:
	virtual void Modify(const std::string& info) override;
	Teacher(std::string _name);
	~Teacher();
};

#endif