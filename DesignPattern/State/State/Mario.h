#pragma once
#include "Position.h"
#include "Action.h"
#include <string>
class MarioState;

/// <summary>
/// 马里奥的对象类
/// </summary>
class Mario {
private:
	Position m_Pos{ Position(0, 0) };		// 当前坐标
	JumpAction m_Jump{ JumpAction(15) };	// 用于计算跳跃的对象
	MarioState* state{ nullptr };			// 当前状态
	int coin{ 0 };							// 获得的积分
	std::string m_Show{ "o" };				// 显示方式

public:
	Mario(Position _startPos);
	void SetState(MarioState* state);		// 状态转移
	void SetShow(char show);				// 修改显示方式
	std::string GetShow() const;			

	void RunLeft();							// 左走
	void RunRight();						// 右走
	void Jump();							// 跳跃
	void CalculatePos();					// 计算坐标

	bool CouldJump();						// 判断当前能否跳跃，因为跳跃状态是不能再跳跃的

	Position GetPosition();

public:
	void SetCoin(int numberOfCoins);
	void ReportCoin();
	void Die();

public:
	void GotMushroom();						// 碰撞之后出发事件
	void GotFireFlower();
	void GotFeather();
	void GotAttack();
};

