#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "Scene\Scene.h"

struct Cameraa
{
	int x;
	int y;
	int width;
	int height;
};

class Utility
{
public:
	static Cameraa* gameCamera;

	static D3DXVECTOR2 TranformVector2(D3DXVECTOR2);

	static RECT TranformBox(RECT);
};
