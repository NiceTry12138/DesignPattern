#include "Action.h"

JumpAction::JumpAction(int speed) : m_Speed(speed) {}

Vec JumpAction::GetVector() { 
	return m_Vec; 
}

bool JumpAction::IsFinish() { 
	return m_IsFinish; 
}
void JumpAction::ActiveAction() { 
	m_IsFinish = false; 
}

void JumpAction::Calculate() {
	m_IsFinish = false;
	float height = GetHeight();
	if (height < 0)
	{
		height = 0;
		m_RunTime = 0.0f;
		m_IsFinish = true;
	}
	m_Vec.SetX(0);
	m_Vec.SetY(height);
}

// 物理公式：V*t + 1/2 * a * t^2
float JumpAction::GetHeight() {
	m_RunTime += Config::GetInstance().GetDelayTime();
	return m_Speed * m_RunTime + 0.5f * G * m_RunTime * m_RunTime;
}