#pragma once
#include "Object.h"

class AActor : public UObject
{
public:
	virtual void Tick(float fDeltaTime);
	bool GetEnabled();
	void SetEnabled();
	void SetDisabled();

public:
	virtual void BeginPlay();
	virtual void Initialize();
	AActor();

private:
	bool m_bIsEnabled{};
};

