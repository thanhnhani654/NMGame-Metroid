#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>

#define KEY_DOWN(code) ( IsKeyDown(code) )
#define KEYBOARD_BUFFER_SIZE	1024

class Controllable
{
private:
	int g = 0;
	int y = 0;
public:
	LPDIRECTINPUT8 dinput = NULL;
	LPDIRECTINPUTDEVICE8 didev = NULL;
	static LPDIRECTINPUTDEVICE8 Keyboard;
	BYTE KeyStates[256];
	DIDEVICEOBJECTDATA KeyEvents[KEYBOARD_BUFFER_SIZE];
	static LPDIRECTINPUT8 di;
	typedef void(*func_void)();
	void _InitKeyboard(HWND hWnd, HINSTANCE hInstance);
	void ProcessInput();
	void OnKeyDown(int Keycode, func_void);
	void OnKeyUp(int Keycode) {};
	int IsKeyDown(int KeyCode);
	void _ProcessKeyBoard();


};