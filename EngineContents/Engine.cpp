#include "stdafx.h"
#include "Engine.h"
#include "OSContents/WindowsGameWindow.h"
#include "OSContents/WindowsTimer.h"


void UEngine::OpenLevel(const char* lpszKey)
{
	string strLevelToOpen = lpszKey;

	auto Iter = m_Levels.find(strLevelToOpen);

	ULevel* LevelToOpen = (*Iter).second;

	m_CurrentLevel = LevelToOpen;

	m_CurrentLevel->Initialize();

	m_CurrentLevel->BeginPlay();
}

void UEngine::LoadLevel(const char* lpszKey, const char* lpszPath)
{

}

void UEngine::OpenLevelTest()
{
	ULevel* LevelToOpen{};
	LevelToOpen = (*m_Levels.find("TestLevel")).second;
	m_CurrentLevel = LevelToOpen;
	m_CurrentLevel->Initialize();
	m_CurrentLevel->BeginPlay();
}

void UEngine::LoadLevelTest()
{
	ULevel* NewLevel = new ULevel{};
	pair<string, ULevel*> ElementToInsert = {"TestLevel", NewLevel};
	m_Levels.insert(ElementToInsert);
}

void UEngine::Tick()
{
	float fDeltaTime = m_Timer->GetDeltaTimeAndSetNewCounter();
	m_GameWindow->WindowLoop();
	m_CurrentLevel->Tick(fDeltaTime);
}

void UEngine::Render()
{
	m_GameWindow->Render();
}

void UEngine::SetWindow(IGameWindow* Window)
{
	m_GameWindow = Window;
}

int UEngine::GetWindowCount() const
{
	return m_nWindowCount;
}

void UEngine::InitializeOption1()
{
	CWindowsGameWindow* Window = new CWindowsGameWindow{};
	Window->Initialize("CrazyArcade", &m_nWindowCount);
	Window->ResizeWindow(FVector2D<int>(1280, 720));
	Window->Show();

	CWindowsTimer* Timer = new CWindowsTimer{};
	Timer->Initialize();

	m_GameWindow = Window;
	m_Timer = Timer;
}

void UEngine::Release()
{
	for (auto iter = m_Levels.begin(); iter != m_Levels.end(); ++iter)
	{
		SAFE_DELETE((*iter).second);
	}

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