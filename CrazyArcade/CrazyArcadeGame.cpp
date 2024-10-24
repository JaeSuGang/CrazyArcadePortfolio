#include "stdafx.h"
#include "CrazyArcadeGame.h"
#include "EngineCore/Engine.h"
#include "Windows/GameWindow.h"

void CCrazyArcadeGame::RunForever()
{
	int nWindowCount{};

	CGameWindow Window{};
	Window.Initialize("CrazyArcade", &nWindowCount);
	Window.ResizeWindow(FVector2D<int>(1280, 720));
	Window.Show();

	UEngine::GetEngine();


	while (nWindowCount)
	{
		Window.MainLoop();

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
