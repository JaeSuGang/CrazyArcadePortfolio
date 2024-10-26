#pragma once

class IGameWindow
{
public:
	virtual void Render() = 0;
	virtual void WindowLoop() = 0;
};