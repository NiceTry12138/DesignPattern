#pragma once
#include "BaseSocket.h"
#include <string>

class AmericanSocket : public BaseSocket
{
public:
	virtual ~AmericanSocket();
	AmericanSocket();

	virtual std::string AmericanSocketInput() const;

protected:
	void WorkNormal() override;
	void WorkWarning() override;

};

