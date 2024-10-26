#pragma once
#include "Object.h"

class ULevel;

class UGameInstance : public UObject
{
public:
	ULevel* OpenLevel(string strLevelName);
	ULevel* LoadLevel();

public:
	virtual void Tick(float fDeltaTime);

public:
	virtual void Initialize() override;
	virtual void Release();
	~UGameInstance();
	UGameInstance() = default;

private:
	ULevel* m_ActiveLevel;
	map<string, ULevel*> m_Levels;
};

