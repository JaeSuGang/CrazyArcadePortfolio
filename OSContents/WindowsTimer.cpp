#include "stdafx.h"
#include "WindowsTimer.h"

float CWindowsTimer::GetDeltaTimeAndSetNewCounter()
{
	LARGE_INTEGER CurrentCounter{};
	QueryPerformanceCounter(&CurrentCounter);

	__int64 CounterDifference = CurrentCounter.QuadPart - m_LastCounter.QuadPart;

	float fDeltaTime = (float)CounterDifference / (float)m_PerformanceFrequency.QuadPart;

	m_LastCounter = CurrentCounter;

	return fDeltaTime;
}

void CWindowsTimer::Initialize()
{
	QueryPerformanceCounter(&m_LastCounter);
	QueryPerformanceFrequency(&m_PerformanceFrequency);
}

CWindowsTimer::CWindowsTimer()
	:
	m_LastCounter{},
	m_PerformanceFrequency{}
{
}
