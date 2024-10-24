#pragma once
#include "Object.h"
#include <map>
#include <string>

using std::string;
using std::map;

class ULevel;


class UEngine : public UObject
{
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
