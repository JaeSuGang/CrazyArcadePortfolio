#pragma once
#include "Object.h"
#include "EngineContents/Level.h"
#include "OSContents/GameWindow.h"
#include "OSContents/Timer.h"

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
	void SetWindow(IGameWindow* Window);
	int GetWindowCount() const;

public:
	void InitializeOption1();
	void Release();
	void Initialize() override;
	static UEngine* GetEngine();
	~UEngine();
private:
	UEngine() = default;

private:
	map<string, ULevel*> m_Levels;
	ULevel* m_CurrentLevel;
	IGameWindow* m_GameWindow;
	ITimer* m_Timer;
private:
	int m_nWindowCount;
};

extern UEngine* GEngine;
