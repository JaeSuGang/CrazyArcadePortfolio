#include "stdafx.h"
#include "GameInstance.h"
#include "EngineContents/Level.h"

ULevel* UGameInstance::OpenLevel(string strLevelName)
{
	ULevel* LevelToOpen = (*m_Levels.find(strLevelName)).second;
	m_ActiveLevel = LevelToOpen;
	m_ActiveLevel->Initialize();
	m_ActiveLevel->BeginPlay();
	return m_ActiveLevel;
}

ULevel* UGameInstance::LoadLevel()
{
	return nullptr;
}

void UGameInstance::Tick(float fDeltaTime)
{
	m_ActiveLevel->Tick(fDeltaTime);
}

void UGameInstance::Initialize()
{
}

void UGameInstance::Release()
{
	for (auto iter = m_Levels.begin(); iter != m_Levels.end(); ++iter)
	{
		SAFE_DELETE((*iter).second)
	}
	m_Levels.clear();
}

UGameInstance::~UGameInstance()
{
	this->Release();
}
