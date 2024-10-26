#pragma once
#include "Object.h"
#include "EngineContents/Level.h"
#include "EngineContents/GameInstance.h"
#include "OSContents/GameWindow.h"
#include "OSContents/Timer.h"

class UEngine : public UObject
{
public:

public:
	void Tick();
	void Render();

public:
	void SetGameInstance(UGameInstance* GameInstance);
	void SetWindow(IGameWindow* Window);
	int GetWindowCount() const;

public:
	void Release();
	void Initialize() override;
	static UEngine* GetEngine();
	~UEngine();

private:
	UEngine() = default;

private:
	UGameInstance* m_ActiveGameInstance;
	IGameWindow* m_GameWindow;
	ITimer* m_Timer;
private:
	int m_nWindowCount;
};

extern UEngine* GEngine;
