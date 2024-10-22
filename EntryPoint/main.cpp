#include <Windows.h>
#include <EnginePlatform/EngineWindow.h>

#pragma comment (lib, "EnginePlatform.lib")

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UEngineWindow* EngineWindow = UEngineWindow::CreateEngineWindow();
	EngineWindow->ShowWindow();

	return UEngineWindow::WindowMessageLoop();
}