#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "Component\BoxCollider.h"

class DebugDraw
{
protected:
	LPDIRECT3DDEVICE9 d3ddv;
	LPD3DXLINE LineDraw;
	D3DCOLOR color;
	int vpx;
	int vpy;
public:
	void Initialize(LPDIRECT3DDEVICE9 id3ddv, int vpx, int vpy);

	void DrawBox(BoundingBox rect);

};