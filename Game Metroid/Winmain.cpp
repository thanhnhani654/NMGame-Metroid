#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#include "Game.h"
#include <msxml.h>
#include "Component\Controllable.h"
#include "GameLog.h"

#define FRAME_LIMIT 60

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmnLine, int nCmdShow)
{
	WNDCLASS wc;
	HWND hwnd;
	MSG msg;

	//wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = TEXT("MeTroid");
	//wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	


	if (!RegisterClass(&wc))
	{
		MessageBox(NULL, TEXT("CANT RUN"), TEXT("MeTroid"), MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	hwnd = CreateWindow(//WS_EX_CLIENTEDGE,
		TEXT("MeTroid"),
		TEXT("Tittle"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		272,
		256,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	//////////////////////////////////////////////////////////////

	int last_tick = 0;
	int count_per_frame = 100 / FRAME_LIMIT;

	Game game;
	//game.GameInit(hwnd);
	if (!game.GameInit(hwnd))
		return false;

	Controllable InitKeyBoard;
	InitKeyBoard._InitKeyboard(hwnd, hInstance);

	int done = 0;
	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				done = 1;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		int current_tick = GetTickCount();
		int DeltaTime = current_tick - last_tick;

		if (DeltaTime >= count_per_frame)
		{
			//GAMELOG("FPS: %d", 1000/(DeltaTime));
			if (1000 / DeltaTime > 30)
			{
				int h = 0;
			}
			if (1000 / DeltaTime < 10)
			{
				int h = 0;
			}
			last_tick = current_tick;
			game.GameRun(hwnd);			
		}
		else
		{
			Sleep(count_per_frame - (current_tick - last_tick));
			current_tick += count_per_frame - (current_tick - last_tick);
		}

	}

	game.GameRelease();

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}