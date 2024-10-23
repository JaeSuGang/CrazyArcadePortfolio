#pragma once

class CGameWindow
{
public:
	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

public:
	void Initialize();
};

