#include "BaseSocket.h"
#include <iostream>
#include <string>

void BaseSocket::SetCurrentVoltag(int voltag)
{
    m_CurrentVoltag = voltag;
}

int BaseSocket::GetRatedVoltag()
{
    return m_RatedVoltag;
}

BaseSocket::BaseSocket(int ratedvoltag) : m_RatedVoltag(ratedvoltag)
{
}

BaseSocket::~BaseSocket()
{
}

void BaseSocket::DoWork()
{
    if (m_CurrentVoltag != m_RatedVoltag)
    {
        WorkWarning();
    }
    else {
        WorkNormal();
    }
}

void BaseSocket::WorkNormal()
{
    std::cout << "Socket Work Normal" << std::endl;
}

void BaseSocket::WorkWarning()
{
    std::cout << "Socket Work Warning" << std::endl;
}
