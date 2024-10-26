#include "stdafx.h"
#include "WindowsGameWindow.h"

void CWindowsGameWindow::ResizeWindow(FVector2D<int> Vector)
{
	if (m_hWnd)
	{
		SetWindowPos(m_hWnd, NULL, 0, 0, Vector.x, Vector.y, SWP_NOMOVE | SWP_NOZORDER);
	}
}

void CWindowsGameWindow::MainLoop()
{
	MSG msg{};

	while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT || msg.message == WM_CLOSE || msg.message == WM_DESTROY)
		{
			(*m_pWindowCount)--;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}
}

void CWindowsGameWindow::Show()
{
	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);
}

LRESULT CWindowsGameWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_QUIT:
	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0);

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

HWND CWindowsGameWindow::GetWindowHandle() const
{
	return m_hWnd;
}

WNDCLASSEXA CWindowsGameWindow::CreateWindowClass(const char* lpszClassName)
{
    WNDCLASSEXA wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
	wcex.hInstance = nullptr;
    wcex.hIcon = nullptr;
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = lpszClassName;
    wcex.hIconSm = nullptr;

	return wcex;
}

void CWindowsGameWindow::Render()
{

}

bool CWindowsGameWindow::Initialize(const char* lpszClassName, int* pWindowCount)
{
	(*pWindowCount)++;
	m_pWindowCount = pWindowCount;

	WNDCLASSEXA wcex = CreateWindowClass(lpszClassName);

	if (!RegisterClassExA(&wcex))
	{
		return false;
	}

	m_hWnd = CreateWindowA(lpszClassName, lpszClassName, WS_OVERLAPPEDWINDOW,
		0, 0, CW_USEDEFAULT, 0, nullptr, nullptr, nullptr, nullptr);

	if (!m_hWnd)
	{
		return false;
	}

	return true;
}

void CWindowsGameWindow::Release()
{
	DestroyWindow(m_hWnd);
	m_hWnd = 0;
}

CWindowsGameWindow::~CWindowsGameWindow()
{
	Release();
}
