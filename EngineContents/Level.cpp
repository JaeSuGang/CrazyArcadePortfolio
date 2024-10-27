#include "stdafx.h"
#include "Level.h"
#include "EngineContents/Actor.h"

void ULevel::TryDestroyActor(AActor* ActorToDelete)
{
	m_ActorsToDestroy.push_back(ActorToDelete);
}

void ULevel::Tick(float fDeltaTime)
{
	for (auto iter = m_AllActors.begin(); iter != m_AllActors.end(); )
	{
		AActor* Actor = *iter;
		if (Actor && Actor->GetEnabled())
		{
			Actor->Tick(fDeltaTime);
		}
		++iter;
	}
}

void ULevel::LateTick(float fDeltaTime)
{
	HandleActorsToSpawn();
	HandleActorsToDestroy();
}

void ULevel::BeginPlay()
{
	for (auto iter = m_AllActors.begin(); iter != m_AllActors.end(); )
	{
		AActor* Actor = *iter;
		if (Actor && Actor->GetEnabled())
		{
			Actor->BeginPlay();
		}
		++iter;
	}
}

void ULevel::Initialize()
{
	m_AllActors.reserve(10000);
	m_ActorsToDestroy.reserve(10000);
	m_ActorsToSpawn.reserve(10000);
}

void ULevel::Release()
{
	for (auto iter = m_AllActors.begin(); iter != m_AllActors.end();)
	{
		if (*iter)
		{
			delete* iter;
		}
	}
	m_AllActors.clear();
}

ULevel::~ULevel()
{
	this->Release();
}

void ULevel::HandleActorsToDestroy()
{
	for (int i = 0; i < m_ActorsToDestroy.size(); i++)
	{
		auto iter = m_AllActors.find(m_ActorsToDestroy[i]);
		if (*iter)
		{
			delete* iter;
		}
		m_AllActors.erase(m_ActorsToDestroy[i]);
	}

}

void ULevel::HandleActorsToSpawn()
{
	for (int i = 0; i < m_ActorsToSpawn.size(); i++)
	{
		m_ActorsToSpawn[i]->Initialize();
		m_ActorsToSpawn[i]->BeginPlay();
		m_AllActors.insert(m_ActorsToSpawn[i]);
	}

	m_ActorsToSpawn.clear();
}
