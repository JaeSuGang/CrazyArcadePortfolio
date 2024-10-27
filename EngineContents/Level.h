#pragma once
#include "stdafx.h"
#include "Object.h"
#include "EngineContents/Actor.h"
#include "EngineContents/Gamemode.h"

class ULevel final : public UObject
{
public:
	//typedef AActor T;
	template<typename T>
	T* SpawnActor()
	{
		T* Actor = new T{};
		m_ActorsToSpawn.push_back(Actor);
		return Actor;
	}

	void TryDestroyActor(AActor* ActorToDelete);

	void Tick(float fDeltaTime);
	void LateTick(float fDeltaTime);

public:
	void BeginPlay();
	void Initialize();
	void Release();
	ULevel() = default;
	~ULevel();

private:
	void HandleActorsToDestroy();
	void HandleActorsToSpawn();


private:
	vector<AActor*> m_ActorsToSpawn;
	vector<AActor*> m_ActorsToDestroy;
	unordered_set<AActor*> m_AllActors;
	AGamemode* m_Gamemode;
};

