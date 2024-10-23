#pragma once
#include <Windows.h>

// Ό³Έν :
class UGameWindow
{
public:
	void ShowWindow();
	static int WindowMessageLoop();

public:
	static UGameWindow* CreateGameWindow();
	void Initialize();
	void Release();
	~UGameWindow();

private:
	UGameWindow();
	UGameWindow(const UGameWindow& _Other) = delete;
	UGameWindow(UGameWindow&& _Other) noexcept = delete;
	UGameWindow& operator=(const UGameWindow& _Other) = delete;
	UGameWindow& operator=(UGameWindow&& _Other) noexcept = delete;

private:
	HWND m_hWindowHandle = nullptr;

};

