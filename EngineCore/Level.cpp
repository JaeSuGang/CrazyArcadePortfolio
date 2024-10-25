#include "stdafx.h"
#include "Level.h"
#include "EngineCore/Actor.h"

void ULevel::Initialize()
{

}

void ULevel::Release()
{
	for (auto it = m_AllActors.begin(); it != m_AllActors.end(); ++it)
	{
		SAFE_DELETE(*it);
	}

	m_AllActors.clear();
}

ULevel::ULevel()
{

}

ULevel::~ULevel()
{
	this->Release();
}
