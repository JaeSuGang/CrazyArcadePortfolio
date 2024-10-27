#include "stdafx.h"
#include "CrazyArcadeGame.h"
#include "EngineContents/Engine.h"
#include "OSContents/WindowsGameWindow.h"
#include "OSContents/WindowsTimer.h"
#include "GameContents/CAGameInstance.h"

void CCrazyArcadeGame::RunForever()
{
	UEngine::GetEngine();

	CWindowsTimer* Timer = new CWindowsTimer{};
	Timer->Initialize();
	CWindowsGameWindow* Window = new CWindowsGameWindow{};
	Window->Initialize("CrazyArcade", GEngine->GetpWindowCount());
	Window->Show();
	GEngine->SetWindow(Window);
	GEngine->SetTimer(Timer);
	GEngine->SetGameInstance<UCAGameInstance>();

	while (*GEngine->GetpWindowCount())
	{
		GEngine->Tick();
		GEngine->Render();
	}
}

void CCrazyArcadeGame::Initialize()
{
	m_bIsInitialized = true;
}

void CCrazyArcadeGame::Release()
{
	SAFE_DELETE(GEngine);
}

CCrazyArcadeGame::~CCrazyArcadeGame()
{
	Release();
}

CCrazyArcadeGame::CCrazyArcadeGame()
	:
	m_bIsInitialized{}
{

}
