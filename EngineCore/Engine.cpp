#include "stdafx.h"
#include "Engine.h"


UEngine* UEngine::GetEngine()
{
	if (!GEngine)
	{
		GEngine = new UEngine{};
	}

	return GEngine;
}

UEngine::UEngine()
	:
	m_CurrentLevel{},
	m_Levels{}
{
}


UEngine* GEngine = UEngine::GetEngine();