#include "Config.h"

std::string Config::NORMAL_BOX = "\033[0m";
std::string Config::RED_BOX = "\033[0;37;41m";
std::string Config::GREEN_BOX = "\033[0;37;42m";
std::string Config::BROWN_BOX = "\033[0;37;43m";
std::string Config::BLUE_BOX = "\033[0;37;44m";
std::string Config::WHITE_BOX = "\033[0;37;47m";

std::string Config::GetToolStr(Mario_TOOLS _tool)
{
	switch (_tool)
	{
	case Mario_TOOLS::Mushroom:
		//return Config::BROWN_BOX + "1" + Config::NORMAL_BOX;
		return "1";
		break;
	case Mario_TOOLS::FireFlower:
		//return Config::RED_BOX + "2" + Config::NORMAL_BOX;
		return "2";
		break;
	case Mario_TOOLS::Feather:
		//return Config::BLUE_BOX + "3" + Config::NORMAL_BOX;
		return "3";
		break;
	case Mario_TOOLS::Attack:
		//return Config::WHITE_BOX + "4" + Config::NORMAL_BOX;
		return "4";
		break;
	default:
		return std::string();
		break;
	}
}
