#pragma once
#include "Object.h"

class AActor : public UObject
{
public:
	void BeginPlay();

public:
	virtual void Initialize();
};

