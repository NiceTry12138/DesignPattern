#pragma once
#include "MarioState.h"
#include "Singleton.h"

/// <summary>
/// ��ͨ�������
/// </summary>
class SuperMario : public MarioState, public Singleton<SuperMario>
{
};

