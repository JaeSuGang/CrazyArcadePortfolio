#include "stdafx.h"
#include "CrazyArcadeGame.h"
#include "EngineContents/Engine.h"
#include "OSContents/WindowsGameWindow.h"
#include "GameContents/CAGameInstance.h"

void CCrazyArcadeGame::RunForever()
{
	UEngine::GetEngine();

	GEngine->SetGameInstance<UCAGameInstance>();
	GEngine->GetGameInstance()->OpenTestLevel();

	while (GEngine->GetWindowCount())
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
