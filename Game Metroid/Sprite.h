#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <dinput.h>
#include <windowsx.h>
#include <map>
#include "Define.h"

struct Position
{
	int x;
	int y;
	int width;
	int height;
};

struct BeginEnd
{
	int _Begin;
	int _End;
};

class Sprite
{
protected:
	LPDIRECT3DTEXTURE9 _Image;
	LPD3DXSPRITE _SpriteHandler;

	int _Index;
	int _Height;
	int _Width;
	int _Begin;
	int _End;
	

	bool _Flip = false;
	bool _IsMap = false;

	float FRAME_RATE;
	int currentframe;
	
	BeginEnd Beg;
	std::map<Animation,BeginEnd> AnimMap;
	Animation CurrentAnim;
public:
	Sprite() {}
	Sprite(int) {}
	Position* Pos;
	Sprite(LPDIRECT3DDEVICE9 d3ddv, LPCWSTR Path, int Width, int Height);
	void GetAmount(int n) 
	{ 
		Pos = new Position[n];
	}
	Position* GetPosition();
	void AddAnimation(Animation eAnim, int Begin, int End);
	void SetStatus(Animation t);
	void Next();
	void Render(int X, int Y, int vx, int vy);

	void Flip();
	void Reset();
	void SetIsMap(bool map);
	void SetFrameRate(float rate);
	Position GetCurrentPosition();

	~Sprite();
};

