#include "stdafx.h"
#include "Engine.h"
#include "OSContents/WindowsGameWindow.h"
#include "OSContents/WindowsTimer.h"

void UEngine::Tick()
{
	float fDeltaTime = m_Timer->GetDeltaTimeAndSetNewCounter();
	m_GameWindow->WindowLoop();
	m_ActiveGameInstance->Tick(fDeltaTime);
}

void UEngine::Render()
{
	m_GameWindow->Render();
}

void UEngine::SetGameInstance(UGameInstance* GameInstance)
{
	m_ActiveGameInstance = GameInstance;
	m_ActiveGameInstance->Initialize();
}

void UEngine::SetWindow(IGameWindow* Window)
{
	m_GameWindow = Window;
}

int UEngine::GetWindowCount() const
{
	return m_nWindowCount;
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