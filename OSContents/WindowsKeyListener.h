#pragma once
#include "OSContents/KeyListener.h"

using std::vector;

class CWindowsKeyListener : public IKeyListener
{
public:
	vector<short>& GetKeyState() override;

public:
	void Initialize() override;

private:
	const int m_KeyCount = VK_F24;
	vector<short> m_KeyStates;

};

