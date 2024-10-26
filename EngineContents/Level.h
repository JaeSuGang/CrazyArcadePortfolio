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
		Actor->Initialize();
		Actor->BeginPlay();
		m_AllActors.push_back(Actor);
		return Actor;
	}

	void Tick();

public:
	void BeginPlay();
	void Initialize();
	void Release();
	ULevel() = default;
	~ULevel();


private:
	vector<AActor*> m_AllActors;
	AGamemode* m_Gamemode;
};

