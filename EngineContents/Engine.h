#pragma once
#include "Object.h"
#include "EngineContents/Level.h"
#include "OSContents/GameWindow.h"

class UEngine : public UObject
{
public:
	void OpenLevel(const char* lpszKey);
	void LoadLevel(const char* lpszKey, const char* lpszPath);
	void OpenLevelTest();
	void LoadLevelTest();

public:
	void Tick();
	void Render();

public:
	void Release();
	void Initialize();
	static UEngine* GetEngine();
	~UEngine();

private:
	UEngine() = default;

private:
	map<string, ULevel*> m_Levels;
	ULevel* m_CurrentLevel;
	CGameWindow* m_GameWindow;
};

extern UEngine* GEngine;
