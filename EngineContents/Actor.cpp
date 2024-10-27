#include "stdafx.h"
#include "Actor.h"

void AActor::Tick(float fDeltaTime)
{

}

bool AActor::GetEnabled()
{
	return m_bIsEnabled;
}

void AActor::SetEnabled()
{
	m_bIsEnabled = true;
}

void AActor::SetDisabled()
{
	m_bIsEnabled = false;
}

void AActor::BeginPlay()
{

}

void AActor::Initialize()
{
}

AActor::AActor()
	:
	m_bIsEnabled{ true }
{

}
