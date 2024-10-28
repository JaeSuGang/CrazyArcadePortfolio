#pragma once
#include "Timer.h"

class CWindowsTimer : public ITimer
{
public:
	// 한 곳에서만 호출되어야 함. 여러곳에서 호출 x
	virtual float GetDeltaTimeAndSetNewCounter() override;

public:
	virtual void Initialize() override;
	CWindowsTimer();
	

private:
	LARGE_INTEGER m_LastCounter;
	LARGE_INTEGER m_PerformanceFrequency;
};

