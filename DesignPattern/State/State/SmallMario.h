#pragma once
#include "MarioState.h"
#include "Singleton.h"

/// <summary>
/// С�����
/// </summary>
class SmallMario : public MarioState, public Singleton<SmallMario>
{

};

