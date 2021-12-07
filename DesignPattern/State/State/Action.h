#pragma once
#include "Position.h"
#include "Config.h"

/// <summary>
/// 跳跃类
/// </summary>
class JumpAction
{
public:
	const static int G = -10;	// 重力加速度 设定为10

	JumpAction(int speed);
	~JumpAction() = default;

	Vec GetVector();
	void Calculate();			

	bool IsFinish();			// 当前跳跃是否结束
	void ActiveAction();		// 激活跳跃状态，即开始跳跃

protected:
	inline float GetHeight();	// 通过物理公式计算当前高度

private:
	bool m_IsFinish{ true };
	float m_RunTime{ 0.0f };	// 记录事件，高度计算需要时间
	int m_Speed;				// 设定初始速度，高度计算需要初始速度
	Vec m_Vec{ Position(0,0) };
};