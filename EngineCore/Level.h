#pragma once
#include "stdafx.h"
#include "Object.h"
#include "EngineCore/Actor.h"

class ULevel final : public UObject
{
public:
	typedef AActor T;
	//template<typename T>
	T* SpawnActor()
	{
		T* Actor = new T{};
		Actor->Initialize();
		m_AllActors.push_back(Actor);
		return Actor;
	}

public:
	void Initialize();
	void Release();
	ULevel();
	~ULevel();


private:
	vector<AActor*> m_AllActors;
};

