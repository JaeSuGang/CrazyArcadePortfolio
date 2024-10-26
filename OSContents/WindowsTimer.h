#pragma once
#include "Timer.h"

class CWindowsTimer : public ITimer
{
public:
	// �� �������� ȣ��Ǿ�� ��. ���������� ȣ�� x
	virtual float GetDeltaTimeAndSetNewCounter() override;

public:
	virtual void Initialize() override;
	CWindowsTimer() = default;
	

private:
	LARGE_INTEGER m_LastCounter;
	LARGE_INTEGER m_PerformanceFrequency;
};

