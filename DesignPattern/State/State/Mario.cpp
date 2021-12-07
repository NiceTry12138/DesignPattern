#include "Mario.h"
#include "MarioStates.h"
#include <iostream>

Mario::Mario(Position _startPos) : m_Pos(_startPos) {
	coin = 0;
	this->state = &SmallMario::GetInstance();
}

void Mario::SetState(MarioState* state) {
	this->state = state;
}

void Mario::SetShow(char show)
{
	m_Show = show;
}

std::string Mario::GetShow() const
{
	return m_Show;
}

void Mario::RunLeft()
{
	m_Pos.AddX(-1);
}

void Mario::RunRight()
{
	m_Pos.AddX(1);
}

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

bool Mario::CouldJump()
{
	return m_Jump.IsFinish();
}

Position Mario::GetPosition()
{
	return Position(m_Pos.X(), m_Jump.GetVector().Y());
}

void Mario::SetCoin(int numberOfCoins) {
	coin += numberOfCoins;
}

void Mario::ReportCoin() {

}

void Mario::Die()
{
	Config::GetInstance().SetMarioState(false);
	std::cout << "Mario Die" << std::endl;
}

void Mario::GotMushroom() {
	this->state->GotMushroom(this);
}

void Mario::GotFireFlower() {
	this->state->GotFireFlower(this);
}

void Mario::GotFeather()
{
	this->state->GotFeather(this);
}

void Mario::GotAttack()
{
	this->state->GotAttack(this);
}
