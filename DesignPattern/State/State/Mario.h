#pragma once
#include "Position.h"
#include "Action.h"
#include <string>
class MarioState;

/// <summary>
/// ����µĶ�����
/// </summary>
class Mario {
private:
	Position m_Pos{ Position(0, 0) };		// ��ǰ����
	JumpAction m_Jump{ JumpAction(15) };	// ���ڼ�����Ծ�Ķ���
	MarioState* state{ nullptr };			// ��ǰ״̬
	int coin{ 0 };							// ��õĻ���
	std::string m_Show{ "o" };				// ��ʾ��ʽ

public:
	Mario(Position _startPos);
	void SetState(MarioState* state);		// ״̬ת��
	void SetShow(char show);				// �޸���ʾ��ʽ
	std::string GetShow() const;			

	void RunLeft();							// ����
	void RunRight();						// ����
	void Jump();							// ��Ծ
	void CalculatePos();					// ��������

	bool CouldJump();						// �жϵ�ǰ�ܷ���Ծ����Ϊ��Ծ״̬�ǲ�������Ծ��

	Position GetPosition();

public:
	void SetCoin(int numberOfCoins);
	void ReportCoin();
	void Die();

public:
	void GotMushroom();						// ��ײ֮������¼�
	void GotFireFlower();
	void GotFeather();
	void GotAttack();
};

