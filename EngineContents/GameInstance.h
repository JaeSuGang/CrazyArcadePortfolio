#pragma once
#include "Object.h"
#include "unordered_map"

using std::unordered_map;

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

protected:
	ULevel* m_ActiveLevel;
	unordered_map<string, ULevel*> m_Levels;
};

