#pragma once
#include "Object.h"
#include "EngineCore/Level.h"
#include <map>
#include <string>

using std::string;
using std::map;

class UEngine : public UObject
{
public:
	void OpenLevel(const char* lpszKey);
	void LoadLevel(const char* lpszKey, const char* lpszPath);

public:
	void Tick();

public:
	static UEngine* GetEngine();
	~UEngine() = default;

private:
	UEngine();

private:
	map<string, ULevel*> m_Levels;
	ULevel* m_CurrentLevel;
};

extern UEngine* GEngine;
