#pragma once
#include "MarioState.h"
#include "Singleton.h"

/// <summary>
/// 普通大马里奥
/// </summary>
class SuperMario : public MarioState, public Singleton<SuperMario>
{
};

