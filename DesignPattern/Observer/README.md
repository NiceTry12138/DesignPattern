<!--
 * @Version: 
 * @Autor: LC
 * @Date: 2021-12-01 21:09:01
 * @LastEditors: LC
 * @LastEditTime: 2021-12-03 11:46:37
 * @Description: file content
-->
# 观察者模式

## 目标

1. 学生订阅多个老师，获取老师所发布作业
的作业通知系统
2. 学生可以取消订阅老师，老师也可以屏蔽学生的订阅

## 实现

提供三种基类：`IObserver`,`IObservers`,`IPublichser`  

- IObserver：基础观察者类，仅提供`update`和`IsGetInfo`方法
- IObservers：维护被观察者列表的观察者类，继承于`IObserver`
- IPublichser：被观察类，维护了`IObserver`列表，并且提供`Modify`通知方法

作为观察者的`Student`继承`IObservers`，因为学生可以主动的取消订阅，所以需要知道其对应的订阅对象  
作为被观察的`Teacher`继承`IPublichser`，作为消息的发送者，并且可以删除、添加观察者

```cpp
class Teacher : public IPublichser {
public:
	void AddObserver(IObservers* obs);
	void RemoveObserver(IObservers* obs);
public:
	virtual void Modify(const std::string& info) override;
	Teacher(std::string _name);
	~Teacher();
};
```

1. 老师删除学生的观察的时候，学生也需要删除对老师的订阅，所以传入的是可以删除发布者的`IObservers`，在函数中主动调用`IObservers`的删除功能，同时调用`IPublisher`对`IObserver`的删除，达成双向的删除
2. 这里使用老师删除学生的同时学生也会删除老师，学生屏蔽老师的时候老师也屏蔽学生。之所以这么做是因为现实生活中**学生离开班级（学生取消订阅老师），老师也就不关心离开的学生了，自然不会发送消息给该学生**，感觉师生关系是相互的，一方断开双方自动断开。
3. 如果想实现网络关注的那种状态，只需要注释老师的删除学生代码即可

```cpp
class IObserver
{
public:
    virtual void update(const std::string& info) = 0;
    virtual ~IObserver() = default;
    IObserver(const std::string& name);
    std::string GetName() const;
    virtual bool IsGetInfo() = 0;
private:
    std::string m_name;
};
```

1. `IObserver`为观察者基类，提供纯虚函数`update`给`IPublisher`使用
2. 该类提供`IsGetInfo`供`IPublisher`判断该`IObserver`对象是否需要推送信息，`IObserver`的子类只需要重写`IsGetInfo`方法即可

```cpp
class IObservers : public IObserver
{
public:
	void UnSubscribePublisher(IPublichser* publisher);
	void SubscribePublisher(IPublichser* publisher);
	void ShowInfo();
	IObservers(const std::string& name);
	virtual ~IObservers();
private:
	std::list<IPublichser*> m_subscribes;
};
```

1. `IObservers`继承`IObserver`，并且维护`IPublichser`对象数组，为了实现学生取消订阅老师的时候，老师也可以屏蔽学生，所以需要记录下`IPublichser`对象
2. 定义`IObservers`的想法是定义一个中间层，防止`IObserver`和`IPublichser`互相包含的情况出现

## 代码运行

```cpp
// 老师添加观察者
for (auto stu : m_students){
    for (auto tea : m_teachers) {
        tea->AddObserver(stu.get());
    }
}

// 学生取消订阅
for (auto stu : m_students){
    int randomTeaIndex = RandomInt(m_teachers.size());
    stu->UnSubscribePublisher(m_teachers[randomTeaIndex].get());
}

// 老师删除观察者
for (auto tea : m_teachers){
    int randomStuIndex = RandomInt(m_students.size());
    tea->RemoveObserver(m_students[randomStuIndex].get());
}

// 学生订阅老师
for (auto stu : m_students){
    int randomTeaIndex = RandomInt(m_teachers.size());
    stu->SubscribePublisher(m_teachers[randomTeaIndex].get());
}
```

测试用例在`AppDelegate`对象中实现，使用数组记录下每个创建的`Student`和`Teacher`对象，让老师随机的添加学生和删除学生的观察，让学生随机的订阅和取消订阅老师

## 修改

```cpp
void AppDelegate::CreateTeacher(int num)
{
	for (int i = 0; i < num; ++i)
	{
		std::unique_ptr<Teacher> teacher = std::make_unique<Teacher>("Teacher_" + std::to_string(i));
		m_teachers.push_back(std::move(teacher));
	}
}
```

`AppDelegate`中对`Student`和`Teacher`的创建使用`unique_ptr`，因为创建出来的对象并没有给其他对象共享使用权