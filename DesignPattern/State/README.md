<!--
 * @Version: 
 * @Autor: LC
 * @Date: 2021-12-06 17:03:22
 * @LastEditors: LC
 * @LastEditTime: 2021-12-07 19:22:21
 * @Description: 代理模式
-->

# 状态模式

## 目标

1. 事件
   1. 吃羽毛
   2. 吃火焰花
   3. 吃蘑菇
   4. 碰到怪物
2. 状态
   1. 小马里奥
   2. 大马里奥
   3. 火焰马里奥
   4. 斗篷马里奥


## 实现

1. 状态转换

```cpp
void Mario::SetState(MarioState* state) {
	this->state = state;
}

void SmallMario::GotMushroom(Mario* mario) {
	mario->SetCoin(100);
	mario->SetState(&SuperMario::GetInstance());
	mario->SetShow('O');
}

void SmallMario::GotAttack(Mario* mario)
{
	mario->Die();
}
```

马里奥对应的状态遇到特定事件，可以进行状态的转移，外界只需要调用马里奥对应的接口即可实现状态自动的变化，同时可以顺带的修改马里奥的属性数据


| 初始状态   | 事件     | 最终状态   |
| ---------- | -------- | ---------- |
| 小马里奥   | 吃蘑菇   | 大马里奥   |
| 小马里奥   | 吃火焰花 | 火焰马里奥 |
| 小马里奥   | 吃羽毛   | 斗篷马里奥 |
| 小马里奥   | 受到攻击 | 死亡       |
| 大马里奥   | 吃蘑菇   | 大马里奥   |
| 大马里奥   | 吃火焰花 | 火焰马里奥 |
| 大马里奥   | 吃羽毛   | 斗篷马里奥 |
| 大马里奥   | 受到攻击 | 小马里奥   |
| 火焰马里奥 | 吃蘑菇   | 火焰马里奥 |
| 火焰马里奥 | 吃火焰花 | 火焰马里奥 |
| 火焰马里奥 | 吃羽毛   | 斗篷马里奥 |
| 火焰马里奥 | 受到攻击 | 小马里奥   |
| 斗篷马里奥 | 吃蘑菇   | 斗篷马里奥 |
| 斗篷马里奥 | 吃火焰花 | 火焰马里奥 |
| 斗篷马里奥 | 吃羽毛   | 斗篷马里奥 |
| 斗篷马里奥 | 受到攻击 | 小马里奥   |

2. 运动

```cpp
class Position {
public:
	Position(int _x, int _y) : m_x(_x), m_y(_y) {}
	Position(int _x) : m_x(_x), m_y(_x) {}
	Position() : m_x(0), m_y(0) {}

	inline bool operator == (const Position &_t);
	inline Position& operator += (const Position &_t);
	
	void AddX(int _add) { m_x += _add; }
	void AddY(int _add) { m_y += _add; }
private:
	int m_x, m_y;
};

typedef Position Vec;

void Mario::RunLeft()
{
	m_Pos.AddX(-1);
}

void Mario::RunRight()
{
	m_Pos.AddX(1);
}
```

马里奥包含一个`Position`对象的属性，可以记录当前马里奥的坐标，同样马里奥对外暴露`RunLeft`和`RunRight`方法，可以修改自身`Position`坐标

```cpp
class JumpAction
{
public:
	const static int G = -10;

	JumpAction(int speed);
	~JumpAction() = default;

	Vec GetVector();
	void Calculate();

	bool IsFinish();
	void ActiveAction();

protected:
	inline float GetHeight();

private:
	bool m_IsFinish{ true };
	float m_RunTime{ 0.0f };
	int m_Speed;
	Vec m_Vec{ Position(0,0) };
};
void Mario::Jump()
{
	m_Jump.ActiveAction();
}

void Mario::CalculatePos()
{
	if (!m_Jump.IsFinish())
	{
		m_Jump.Calculate();
	}
}
```

添加`JumpAction`对象作为`Mario`的成员属性，在渲染时计算当前跳跃高度并且同步修改到`Mario`的坐标中  
`JumpAction`中根据传入的初始速度、时间和重力加速度计算在某一时刻对象所在的对应高度  

3. 命令模式

```cpp
class Command {
public:
	virtual void execute(Mario* mario) = 0;
	virtual ~Command() = default;
};

class RunLeftCommand : public Command {
public:
	virtual void execute(Mario* mario) override;
};

class RunRighCommand : public Command {
public:
	virtual void execute(Mario* mario) override;
};

class JumoCommand : public Command {
public:
	virtual void execute(Mario* mario) override;
};

// 输入控制按钮
void AppDelegate::GetInput(char input)
{
	if (m_Commands.find(input) == m_Commands.end())
	{
		return;
	}
	m_Commands[input]->execute(m_Mario.get());
}
```

使用命令模式，定义命令基类，将不同命令封装成不同的对象并记录在`AppDelegate`的映射表中，使用命令模式可以**动态的修改绑定的命令**，可以在**保证开闭原则**的情况下添加新的命令

4. 添加`Monster`的`Attack`事件

```cpp
class MarioState
{
public:
	virtual void GotMushroom(Mario* mario) = 0;
	virtual void GotFireFlower(Mario* mario) = 0;
	virtual void GotFeather(Mario* mario) = 0;
	virtual void GotAttack(Mario* mario) = 0;
};
```

当`Mario`碰到怪物的时候，会受到攻击，不同的状态面对攻击会转移到其他的状态

4. 多线程

```cpp
do {
	char input = _getch();
	if (Config::G_QUIT == input)
	{
		m_ISQUIT = true;
	}
	GetInput(input);
	TouchTools();
	if (!Config::GetInstance().IsMarioAlive())
	{
		m_ISQUIT = true;
	}
} while (!m_ISQUIT);

std::thread showThread(&AppDelegate::Show, this);
```

程序分为两个线程，主线程用来接受命令处理数据，另一个线程用于根据数据进行渲染操作  
`_getch()`方法可以在不输入回车的情况下接受输入，比较适合这个场景的使用  

5. 配置工具类

```cpp
class Config : public Singleton<Config> {
public:
	static const char G_QUIT = 'q';
	static const int CMD_HEIGHT = 25;
	static const int CMD_WEIGHT = 120;

public:
	std::string GetToolStr(Mario_TOOLS _tool);

	float GetDelayTime() { return m_DelayTime; }
	void SetDelayTime(float _val) { m_DelayTime = _val; }

	bool IsMarioAlive() { return m_IsAlive; }
	void SetMarioState(bool _isAlive) { m_IsAlive = _isAlive; }
private:
	bool m_IsAlive{ true };
	float m_DelayTime{0.05f};
};
```

作为数据记录的类，初始化定义一些数据供程序需要的地方使用，也可以设定数据记录当前状态  

## 运行

```cpp
void AppDelegate::Run()
{
	Init();

	std::thread showThread(&AppDelegate::Show, this);
	showThread.detach();

	m_ISQUIT = false;
	do {
		char input = _getch();
		if (Config::G_QUIT == input)
		{
			m_ISQUIT = true;
		}
		GetInput(input);
		TouchTools();
		if (!Config::GetInstance().IsMarioAlive())
		{
			m_ISQUIT = true;
		}
	} while (!m_ISQUIT);
}
```

`AppDelegate`是的`Run`方法是程序入口，使用`Init`方法初始化命令列表、创建马里奥对象、初始化其他对象，使用`std::thread`创建渲染线程按固定的频率刷新屏幕，使用`do whie`循环不停的监听输入数据来执行对应的命令

```cpp
void AppDelegate::TouchTools()
{
	auto marioPos = ConversMarioPosition(m_Mario->GetPosition());
	for (auto& item : m_Tools)
	{
		if (item.second == marioPos)
		{
			switch (item.first)
			{
			case Mario_TOOLS::Mushroom:
				m_Mario->GotMushroom();
				break;
			case Mario_TOOLS::FireFlower:
				m_Mario->GotFireFlower();
				break;
			case Mario_TOOLS::Feather:
				m_Mario->GotFeather();
				break;
			case Mario_TOOLS::Attack:
				m_Mario->GotAttack();
				break;
			default:
				break;
			}
		}
	}
}
```

在`TouchTools`进行**碰撞检测**，直接进行坐标的判断，从而判断对应触发的方法

因此该项目的流程图就很清楚

![Run的流程图](https://img-blog.csdnimg.cn/6b4f52aea95343059b21fe8afae06d22.png)

## 修改