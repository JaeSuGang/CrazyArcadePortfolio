#include "stdafx.h"
#include "Engine.h"


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
	m_CurrentLevel->Tick();
}

void UEngine::Render()
{
}

void UEngine::Release()
{
	for (auto iter = m_Levels.begin(); iter != m_Levels.end(); ++iter)
	{
		SAFE_DELETE((*iter).second);
	}
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