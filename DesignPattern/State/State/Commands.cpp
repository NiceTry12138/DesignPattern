#include "Commands.h"
#include "Mario.h"
#include "Config.h"

void RunLeftCommand::execute(Mario* mario) {
	if (mario->GetPosition().X() > 0)
	{
		mario->RunLeft();
	}
}

void RunRighCommand::execute(Mario* mario) {
	if (mario->GetPosition().X() < Config::CMD_WEIGHT)
	{
		mario->RunRight();
	}
}

void JumoCommand::execute(Mario* mario) {
	if (mario->CouldJump())
	{
		mario->Jump();
	}
}