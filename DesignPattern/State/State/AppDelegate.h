#pragma once
#include "Mario.h"
#include "Commands.h"
#include "Config.h"
#include <memory>
#include <string>
#include <map>
#include <thread>

class AppDelegate
{
public:

public:
	/// <summary>
	/// 主运行
	/// </summary>
	void Run();

	/// <summary>
	/// 初始化函数
	/// </summary>
	void Init();

	/// <summary>
	/// 根据输入操作对应的命令
	/// </summary>
	/// <param name="input">输入的命令参数</param>
	void GetInput(char input);

	/// <summary>
	/// 渲染函数，跑在另一个线程中
	/// </summary>
	void Show();

	/// <summary>
	/// 碰撞检测
	/// </summary>
	void TouchTools();

	std::string ShowTip();

	/// <summary>
	/// 坐标转换，因为马里奥的(0, 0)对应的是命令行的(0, CMD_HEIGHT)所以需要做一个转换
	/// </summary>
	/// <param name="marioPosition">需要转换的坐标</param>
	/// <returns>转换的坐标</returns>
	Position ConversMarioPosition(const Position& marioPosition);

	std::string ShowItem(int x, int y);

	virtual ~AppDelegate();
private:
	std::thread m_ShowThread;
	bool m_ISQUIT{ false };
	std::map<Mario_TOOLS, Position> m_Tools;
	std::map<char, std::unique_ptr<Command>> m_Commands;
	std::unique_ptr<Mario> m_Mario{ nullptr };
};

