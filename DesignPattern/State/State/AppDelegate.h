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
	/// ������
	/// </summary>
	void Run();

	/// <summary>
	/// ��ʼ������
	/// </summary>
	void Init();

	/// <summary>
	/// �������������Ӧ������
	/// </summary>
	/// <param name="input">������������</param>
	void GetInput(char input);

	/// <summary>
	/// ��Ⱦ������������һ���߳���
	/// </summary>
	void Show();

	/// <summary>
	/// ��ײ���
	/// </summary>
	void TouchTools();

	std::string ShowTip();

	/// <summary>
	/// ����ת������Ϊ����µ�(0, 0)��Ӧ���������е�(0, CMD_HEIGHT)������Ҫ��һ��ת��
	/// </summary>
	/// <param name="marioPosition">��Ҫת��������</param>
	/// <returns>ת��������</returns>
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

