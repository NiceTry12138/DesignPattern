#include "AmericanSocket.h"
#include <iostream>

AmericanSocket::~AmericanSocket()
{
}

AmericanSocket::AmericanSocket() : BaseSocket(110)
{
}

std::string AmericanSocket::AmericanSocketInput() const
{
	return "Input American Standard Socket.";
}

void AmericanSocket::WorkNormal()
{
	std::cout << "American Socket Work Normal" << std::endl;
}

void AmericanSocket::WorkWarning()
{
	std::cout << "American Socket Work Warning" << std::endl;
}
