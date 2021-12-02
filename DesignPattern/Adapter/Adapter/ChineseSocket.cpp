#include "ChineseSocket.h"
#include <iostream>

ChineseSocket::~ChineseSocket()
{
}

ChineseSocket::ChineseSocket() : BaseSocket(220)
{
}

std::string ChineseSocket::ChineseSocketInput() const
{
    return "Input Chinese Standard Socket.";
}

void ChineseSocket::WorkNormal()
{
	std::cout << "Chinese Socket Work Normal" << std::endl;
}

void ChineseSocket::WorkWarning()
{
	std::cout << "Chinese Socket Work Normal" << std::endl;
}
