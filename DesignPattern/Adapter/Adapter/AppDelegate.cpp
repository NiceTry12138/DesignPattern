#include "AppDelegate.h"
#include "Adapter.h"
#include <iostream>

void AppDelegate::Run()
{
	std::shared_ptr<AmericanSocket> americanSocket = std::make_shared<AmericanSocket>();
	std::shared_ptr<ChineseSocket> chineseSocket = std::make_shared<ChineseSocket>();

	std::shared_ptr<Adapter> adapter = std::make_shared<Adapter>(chineseSocket.get(), americanSocket.get());

	UserAmericanPlug(americanSocket.get());
	UseChinesePlug(chineseSocket.get());

	UserAmericanPlug(adapter.get());
	UseChinesePlug(adapter.get());
}

void AppDelegate::UseChinesePlug(ChineseSocket* socket)
{
	socket->SetCurrentVoltag(220);
	std::cout << socket->ChineseSocketInput() << std::endl;
	socket->DoWork();
	std::cout << std::endl;
}

void AppDelegate::UserAmericanPlug(AmericanSocket* socket)
{
	socket->SetCurrentVoltag(110);
	std::cout << socket->AmericanSocketInput() << std::endl;
	socket->DoWork();
	std::cout << std::endl;
}
