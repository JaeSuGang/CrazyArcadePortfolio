#pragma once

class CGameWindow
{
public:
	void ResizeWindow(FVector2D<int> Vector);
	void MainLoop();
	void Show();
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

public:
	HWND GetWindowHandle() const;

public:
	bool Initialize(const char* lpszClassName);
	CGameWindow() = default;

private:
	WNDCLASSEXA CreateWindowClass(const char* lpszClassName);

private:
	HWND m_hWnd;
};

