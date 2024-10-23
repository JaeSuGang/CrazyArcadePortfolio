#include "stdafx.h"
#include "CrazyArcadeGame.h"

void CCrazyArcadeGame::RunForever()
{
	assert(m_bIsInitialized);

	while (true)
	{



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
