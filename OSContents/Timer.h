#pragma once

class ITimer
{
public:
	virtual float GetDeltaTimeAndSetNewCounter() = 0;
	virtual void Initialize() = 0;
};