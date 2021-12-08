#include "AppDelegate.h"
#include "Position.h"
#include "Config.h"
#include <iostream>
#include <conio.h>
#include <thread>
#include <Windows.h>
#include <vector>

void AppDelegate::Run()
{
	Init();

	m_ShowThread = std::thread(&AppDelegate::Show, this);

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

void AppDelegate::Init()
{
	m_Mario = std::make_unique<Mario>(Position{3, 15});

	m_Commands.insert(std::make_pair('a', std::make_unique<RunLeftCommand>()));
	m_Commands.insert(std::make_pair('d', std::make_unique<RunRighCommand>()));
	m_Commands.insert(std::make_pair('w', std::make_unique<JumoCommand>()));

	m_Tools = {
		{Mario_TOOLS::Mushroom, ConversMarioPosition(Position(20, 0))},
		{Mario_TOOLS::FireFlower, ConversMarioPosition(Position(40, 0))},
		{Mario_TOOLS::Feather, ConversMarioPosition(Position(60, 0))},
		{Mario_TOOLS::Attack, ConversMarioPosition(Position(80 ,0))},
	};
}

void AppDelegate::GetInput(char input)
{
	if (m_Commands.find(input) == m_Commands.end())
	{
		return;
	}
	m_Commands[input]->execute(m_Mario.get());
}

void AppDelegate::Show()
{
	HANDLE hOutput, hOutBuf;//控制台屏幕缓冲区句柄
		//创建新的控制台缓冲区
	hOutBuf = CreateConsoleScreenBuffer(
		GENERIC_WRITE,//定义进程可以往缓冲区写数据
		FILE_SHARE_WRITE,//定义缓冲区可共享写权限
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);
	hOutput = CreateConsoleScreenBuffer(
		GENERIC_WRITE,//定义进程可以往缓冲区写数据
		FILE_SHARE_WRITE,//定义缓冲区可共享写权限
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);

	COORD coord = { 0,0 };
	//双缓冲处理显示
	DWORD bytes = 0;
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = 0;
	cci.dwSize = 1;
	SetConsoleCursorInfo(hOutput, &cci);
	SetConsoleCursorInfo(hOutBuf, &cci);

	bool selectBuffer = true;
	do
	{
		m_Mario->CalculatePos();
		auto _pos = ConversMarioPosition(m_Mario->GetPosition());
		std::vector<std::string> showList;
		showList.push_back(ShowTip());
		for (int i = 0; i <= Config::CMD_HEIGHT; ++i)
		{
			std::string showLine{};
			for (int j = 0; j <= Config::CMD_WEIGHT; ++j) {
				showLine += ShowItem(j, i);
			}
			showList.push_back(showLine);
		}
		for (int i = 0; i < showList.size(); ++i)
		{
			coord.Y = i;
			if (selectBuffer)
			{
				WriteConsoleOutputCharacterA(hOutBuf, showList[i].c_str(), strlen(showList[i].c_str()), coord, &bytes);
				SetConsoleActiveScreenBuffer(hOutBuf);
			}
			else {
				WriteConsoleOutputCharacterA(hOutput, showList[i].c_str(), strlen(showList[i].c_str()), coord, &bytes);
				SetConsoleActiveScreenBuffer(hOutput);
			}
		}
		Sleep(Config::GetInstance().GetDelayTime() * 1000);
	} while (!m_ISQUIT);
}

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

std::string AppDelegate::ShowTip()
{
	return "1 Mushroom; 2 FireFlower; 3 Feather; 4 Monster\n";
}

Position AppDelegate::ConversMarioPosition(const Position& marioPosition)
{
	return Position(marioPosition.X(), Config::CMD_HEIGHT - marioPosition.Y());
}

std::string AppDelegate::ShowItem(int x, int y)
{
	std::string result = " ";
	for (auto &item : m_Tools)
	{
		if (item.second == Position(x, y))
		{
			result = Config::GetInstance().GetToolStr(item.first);
			break;
		}
	}
	if (ConversMarioPosition(m_Mario->GetPosition()) == Position(x, y))
	{
		result = m_Mario->GetShow();
	}
	return result;
}

AppDelegate::~AppDelegate()
{
	m_ShowThread.join();
}
