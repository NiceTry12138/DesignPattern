#pragma once

#include "Singleton.h"
#include <string>

enum class Mario_TOOLS {
	Mushroom,
	FireFlower,
	Feather,
	Attack
};

class Config : public Singleton<Config> {
public:
	static const char G_QUIT = 'q';
	static const int CMD_HEIGHT = 25;
	static const int CMD_WEIGHT = 120;

	static std::string BLUE_BOX;
	static std::string NORMAL_BOX;
	static std::string BROWN_BOX;
	static std::string RED_BOX;
	static std::string GREEN_BOX;
	static std::string WHITE_BOX;

public:
	/// <summary>
	/// enum与string的转换，用于输出显示
	/// </summary>
	std::string GetToolStr(Mario_TOOLS _tool);

	float GetDelayTime() { return m_DelayTime; }
	void SetDelayTime(float _val) { m_DelayTime = _val; }

	bool IsMarioAlive() { return m_IsAlive; }
	void SetMarioState(bool _isAlive) { m_IsAlive = _isAlive; }
private:
	bool m_IsAlive{ true };		// 当前马里奥是否存活
	float m_DelayTime{ 0.05f };	// 屏幕刷新间隔
};