#include "stdafx.h"
#include "KeyManager.h"

void UKeyManager::SetKeyListener(IKeyListener* KeyListener)
{
	m_KeyListener = KeyListener;
}

void UKeyManager::Initialize()
{

}

UKeyManager::UKeyManager()
	:
	m_KeyListener{}
{

}

UKeyManager::~UKeyManager()
{
	SAFE_DELETE(m_KeyListener);
}
