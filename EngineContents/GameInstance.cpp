#include "stdafx.h"
#include "GameInstance.h"
#include "EngineContents/Level.h"

ULevel* UGameInstance::OpenTestLevel()
{
	ULevel* LevelToOpen = new ULevel{};
	auto PairToInsert = std::make_pair(string("Test"), LevelToOpen);
	m_Levels.insert(PairToInsert);
	OpenLevel("Test");
	return m_ActiveLevel;
}

ULevel* UGameInstance::OpenLevel(string strLevelName)
{
	ULevel* LevelToOpen = (*m_Levels.find(strLevelName)).second;
	m_ActiveLevel = LevelToOpen;
	m_ActiveLevel->Initialize();
	m_ActiveLevel->BeginPlay();
	return m_ActiveLevel;
}

ULevel* UGameInstance::LoadLevel(string strPath, string strKey)
{
	return nullptr;
}

void UGameInstance::Tick(float fDeltaTime)
{
	if (m_ActiveLevel)
		m_ActiveLevel->Tick(fDeltaTime);
}

void UGameInstance::LateTick(float fDeltaTime)
{
	if (m_ActiveLevel)
		m_ActiveLevel->LateTick(fDeltaTime);
}

void UGameInstance::Initialize()
{
}

void UGameInstance::Release()
{
	for (auto iter = m_Levels.begin(); iter != m_Levels.end(); ++iter)
	{
		if ((*iter).second)
		{
			delete (*iter).second;
		}
	}
	m_Levels.clear();
}

UGameInstance::~UGameInstance()
{
	this->Release();
}
