#include "stdafx.h"
#include "CrazyArcade/CrazyArcadeGame.h"

#pragma comment (lib, "EnginePlatform.lib")
#pragma comment (lib, "CrazyArcade.lib")

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CCrazyArcadeGame* Game = new CCrazyArcadeGame{};

	Game->Initialize();
	Game->RunForever();

	delete Game;

	_CrtDumpMemoryLeaks();
}