#include <Windows.h>
#include "GameWindow.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    

    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

int UGameWindow::WindowMessageLoop()
{
    MSG msg{};
    while (msg.message != WM_QUIT)
    {
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (!TranslateAccelerator(msg.hwnd, nullptr, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
    }

    return (int)msg.wParam;
}

UGameWindow::UGameWindow() :
    m_hWindowHandle{}
{
    Initialize();
}

UGameWindow* UGameWindow::CreateGameWindow()
{
    UGameWindow* EngineWindow = new UGameWindow{};
    EngineWindow->Initialize();

    return EngineWindow;
}

void UGameWindow::Initialize()
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
    wcex.lpszClassName = "DefaultWindow";
    wcex.hIconSm = nullptr;

    RegisterClassExA(&wcex);

    m_hWindowHandle = CreateWindowA("DefaultWindow", "MainWindow", WS_OVERLAPPEDWINDOW,
        0, 0, CW_USEDEFAULT, 0, nullptr, nullptr, nullptr, nullptr);

}

void UGameWindow::Release()
{

}

UGameWindow::~UGameWindow()
{
    Release();
}

void UGameWindow::ShowWindow()
{
    ::ShowWindow(m_hWindowHandle, SW_SHOW);
    UpdateWindow(m_hWindowHandle);
}