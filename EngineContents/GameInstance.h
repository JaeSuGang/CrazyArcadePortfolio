#pragma once
#include "Object.h"

class ULevel;

class UGameInstance : public UObject
{
public:
	ULevel* OpenTestLevel();
	ULevel* OpenLevel(string strLevelName);
	ULevel* LoadLevel(string strPath, string strKey);

public:
	virtual void Tick(float fDeltaTime);
	virtual void LateTick(float fDeltaTime);

public:
	virtual void Initialize() override;
	virtual void Release();
	~UGameInstance();
	UGameInstance() = default;

private:
	ULevel* m_ActiveLevel;
	unordered_map<string, ULevel*> m_Levels;
};

