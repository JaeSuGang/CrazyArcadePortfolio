#pragma once

using std::vector;

class IKeyListener
{
public:
	virtual vector<short>& GetKeyState() = 0;
	virtual void Initialize() = 0;
};