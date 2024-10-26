#pragma once
#include "Object.h"

class AActor : public UObject
{
public:
	void Tick();

public:
	void BeginPlay();
	virtual void Initialize();
};

