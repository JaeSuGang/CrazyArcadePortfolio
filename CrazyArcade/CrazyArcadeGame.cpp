#include "stdafx.h"
#include "CrazyArcadeGame.h"
#include "Windows/GameWindow.h"

void CCrazyArcadeGame::RunForever()
{
	CGameWindow Window{};
	Window.Initialize("CrazyArcade");
	Window.ResizeWindow(FVector2D<int>(800, 600));
	Window.Show();

	while (true)
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
