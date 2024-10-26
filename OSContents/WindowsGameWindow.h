#pragma once
#include "stdafx.h"
#include "OSContents/GameWindow.h"

class CWindowsGameWindow : public IGameWindow
{
public:
	virtual void Render() override;
	void ResizeWindow(FVector2D<int> Vector);
	void MainLoop();
	void Show();
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

public:
	HWND GetWindowHandle() const;

public:
	bool Initialize(const char* lpszClassName, int* pWindowCount);
	void Release();
	CWindowsGameWindow() = default;
	~CWindowsGameWindow();

private:
	WNDCLASSEXA CreateWindowClass(const char* lpszClassName);

private:
	int* m_pWindowCount;
	bool m_bIsLoopOn;
	HWND m_hWnd;
};

