#include "DebugBox.h"
#include "Utility.h"

void DebugDraw::Initialize(LPDIRECT3DDEVICE9 id3ddv, int ivpx, int ivpy)
{
	d3ddv = id3ddv;
	D3DXCreateLine(d3ddv, &LineDraw);

	LineDraw->SetWidth(2);
	color = D3DCOLOR_XRGB(255, 0, 0);

	vpx = ivpx;
	vpy = ivpy;
}

void DebugDraw::DrawBox(BoundingBox rect)
{
	D3DXVECTOR2 lines[] = { 
		 D3DXVECTOR2(rect.left, rect.top) ,
		D3DXVECTOR2(rect.right, rect.top) ,
		D3DXVECTOR2(rect.right, rect.bottom), 
		D3DXVECTOR2(rect.left, rect.bottom),
		D3DXVECTOR2(rect.left, rect.top) };

	for (int i = 0; i < 5; i++)
	{
		lines[i] = Utility::TranformVector2(lines[i]);
	}
	

	LineDraw->Begin();
	LineDraw->Draw(lines, 5, color);
	LineDraw->End();
}