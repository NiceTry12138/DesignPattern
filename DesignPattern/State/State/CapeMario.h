#pragma once
#include "MarioState.h"
#include "Singleton.h"

/// <summary>
/// ���������
/// </summary>
class CapeMario : public MarioState, public Singleton<CapeMario>
{
};

