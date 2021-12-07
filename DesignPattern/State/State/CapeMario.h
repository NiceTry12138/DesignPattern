#pragma once
#include "MarioState.h"
#include "Singleton.h"

/// <summary>
/// ¶·ÅñÂíÀï°Â
/// </summary>
class CapeMario : public MarioState, public Singleton<CapeMario>
{
};

