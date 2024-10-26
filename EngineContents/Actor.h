#pragma once
#include "Object.h"

class AActor : public UObject
{
public:
	virtual void Tick(float fDeltaTime);

public:
	virtual void BeginPlay();
	virtual void Initialize();
};

