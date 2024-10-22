#pragma once
#include <Windows.h>

// ���� :
class UEngineWindow
{
public:
	void Open();
	static int WindowMessageLoop();

public:
	static UEngineWindow* CreateEngineWindow();
	void Initialize();
	void Release();
	~UEngineWindow();

private:
	UEngineWindow();
	UEngineWindow(const UEngineWindow& _Other) = delete;
	UEngineWindow(UEngineWindow&& _Other) noexcept = delete;
	UEngineWindow& operator=(const UEngineWindow& _Other) = delete;
	UEngineWindow& operator=(UEngineWindow&& _Other) noexcept = delete;

private:
	HWND m_WindowHandle = nullptr;

};

