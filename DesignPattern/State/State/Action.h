#pragma once
#include "Position.h"
#include "Config.h"

/// <summary>
/// ��Ծ��
/// </summary>
class JumpAction
{
public:
	const static int G = -10;	// �������ٶ� �趨Ϊ10

	JumpAction(int speed);
	~JumpAction() = default;

	Vec GetVector();
	void Calculate();			

	bool IsFinish();			// ��ǰ��Ծ�Ƿ����
	void ActiveAction();		// ������Ծ״̬������ʼ��Ծ

protected:
	inline float GetHeight();	// ͨ������ʽ���㵱ǰ�߶�

private:
	bool m_IsFinish{ true };
	float m_RunTime{ 0.0f };	// ��¼�¼����߶ȼ�����Ҫʱ��
	int m_Speed;				// �趨��ʼ�ٶȣ��߶ȼ�����Ҫ��ʼ�ٶ�
	Vec m_Vec{ Position(0,0) };
};