#pragma once
#include "MarioState.h"
#include "Singleton.h"

/// <summary>
/// ���������
/// </summary>
class FireMario : public MarioState, public Singleton<FireMario>
{
};

