#include "stdafx.h"
#include "Level.h"
#include "EngineContents/Actor.h"

void ULevel::Tick(float fDeltaTime)
{
	for (int i = 0; i < m_AllActors.size(); i++)
	{
		m_AllActors[i]->Tick(fDeltaTime);
	}
}

void ULevel::BeginPlay()
{
	for (int i = 0; i < m_AllActors.size(); i++)
	{
		m_AllActors[i]->BeginPlay();
	}
}

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

ULevel::~ULevel()
{
	this->Release();
}
