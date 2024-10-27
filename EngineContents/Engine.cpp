#include "stdafx.h"
#include "Engine.h"
#include "OSContents/WindowsGameWindow.h"
#include "OSContents/WindowsTimer.h"

void UEngine::Tick()
{
	float fDeltaTime = m_Timer->GetDeltaTimeAndSetNewCounter();
	m_GameWindow->WindowLoop();
	m_ActiveGameInstance->Tick(fDeltaTime);
	m_ActiveGameInstance->LateTick(fDeltaTime);
}

void UEngine::Render()
{
	m_GameWindow->Render();
}

UGameInstance* UEngine::GetGameInstance()
{
	return m_ActiveGameInstance;
}

void UEngine::SetWindow(IGameWindow* Window)
{
	m_GameWindow = Window;
}

void UEngine::SetTimer(ITimer* Timer)
{
	m_Timer = Timer;
}

int* UEngine::GetpWindowCount()
{
	return &m_nWindowCount;
}

void UEngine::Release()
{
	SAFE_DELETE(m_ActiveGameInstance);
	SAFE_DELETE(m_GameWindow);
	SAFE_DELETE(m_Timer);
}

void UEngine::Initialize()
{
}

UEngine* UEngine::GetEngine()
{
	if (!GEngine)
	{
		GEngine = new UEngine{};
	}

	return GEngine;
}

UEngine::~UEngine()
{
	this->Release();
}

UEngine* GEngine = UEngine::GetEngine();