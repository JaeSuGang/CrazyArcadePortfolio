#include "stdafx.h"
#include "WindowsKeyListener.h"

vector<short>& CWindowsKeyListener::GetKeyState()
{
	for (int i = 0; i <= m_KeyCount; i++)
	{
		 m_KeyStates[i] = GetAsyncKeyState(i);
	}

	return m_KeyStates;
}

void CWindowsKeyListener::Initialize()
{
	m_KeyStates.reserve(m_KeyCount);

	for (int i = 0; i <= VK_F24; i++)
	{
		m_KeyStates.push_back(0);
	}
}
