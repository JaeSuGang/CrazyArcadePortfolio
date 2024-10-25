#include "stdafx.h"
#include "Engine.h"


void UEngine::OpenLevel(const char* lpszKey)
{
	string strLevelToOpen = lpszKey;

	auto Iter = m_Levels.find(strLevelToOpen);

	ULevel* LevelToOpen = (*Iter).second;

	m_CurrentLevel = LevelToOpen;

	m_CurrentLevel->Initialize();
}

void UEngine::LoadLevel(const char* lpszKey, const char* lpszPath)
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

UEngine::UEngine()
	:
	m_CurrentLevel{},
	m_Levels{}
{
}


UEngine* GEngine = UEngine::GetEngine();