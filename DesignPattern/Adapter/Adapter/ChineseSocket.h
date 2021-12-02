#pragma once
#include "BaseSocket.h"
#include <string>

class ChineseSocket : public BaseSocket
{
public:
	virtual ~ChineseSocket();
	ChineseSocket();

	virtual std::string ChineseSocketInput() const;

protected:
	void WorkNormal() override;
	void WorkWarning() override;

};

