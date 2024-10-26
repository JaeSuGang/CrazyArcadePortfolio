#include "stdafx.h"
#include "CrazyArcadeGame.h"
#include "EngineContents/Engine.h"
#include "OSContents/WindowsGameWindow.h"

void CCrazyArcadeGame::RunForever()
{
	int nWindowCount{};

	CWindowsGameWindow Window{};
	Window.Initialize("CrazyArcade", &nWindowCount);
	Window.ResizeWindow(FVector2D<int>(1280, 720));
	Window.Show();

	UEngine::GetEngine();
	GEngine->LoadLevelTest();
	GEngine->OpenLevelTest();


	while (nWindowCount)
	{
		Window.MainLoop();
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
