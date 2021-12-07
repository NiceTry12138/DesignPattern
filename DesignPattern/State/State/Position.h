#pragma once

#include <string>

/// <summary>
/// 坐标类，提供一些方便使用的方法
/// </summary>
class Position {
public:
	Position(int _x, int _y) : m_x(_x), m_y(_y) {}
	Position(int _x) : m_x(_x), m_y(_x) {}
	Position() : m_x(0), m_y(0) {}

	inline bool operator == (const Position &_t) {
		return this->m_x == _t.m_x && this->m_y == _t.m_y;
	}

	inline Position& operator += (const Position &_t) {
		this->m_x += _t.m_x;
		this->m_y += _t.m_y;
		return *this;
	}

	void AddX(int _add) { m_x += _add; }
	void AddY(int _add) { m_y += _add; }

	void SetX(int _val) { m_x = _val; }
	void SetY(int _val) { m_y = _val; }

	int X() const { return m_x; }
	int Y() const { return m_y; }

	std::string to_string() { return "x : " + std::to_string(m_x) + " y : " + std::to_string(m_y); }
private:
	int m_x, m_y;
};

typedef Position Vec;