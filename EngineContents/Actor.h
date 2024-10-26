#pragma once
#include "Object.h"

class AActor : public UObject
{
public:
	void Tick(float fDeltaTime);

public:
	void BeginPlay();
	virtual void Initialize();
};

