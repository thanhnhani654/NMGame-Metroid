#include "Utility.h"

Cameraa* Utility::gameCamera = new Cameraa();

D3DXVECTOR2 Utility::TranformVector2(D3DXVECTOR2 iVec2)
{
	D3DXVECTOR2 vec2 = iVec2;
	D3DXMATRIX mt;
	D3DXMatrixIdentity(&mt);
	mt._11 = 1.0f;
	mt._22 = -1.0f;
	mt._41 = -gameCamera->x;
	mt._42 = gameCamera->y;

	D3DXVECTOR4 vp_pos;

	D3DXVec2Transform(&vp_pos, &vec2, &mt);
	vec2.x = vp_pos.x;
	vec2.y = vp_pos.y;

	return vec2;
}


RECT Utility::TranformBox(RECT box)
{
	D3DXVECTOR2 point[] = {
		D3DXVECTOR2(box.left, box.top) ,
		D3DXVECTOR2(box.right, box.top) ,
		D3DXVECTOR2(box.right, box.bottom), };

	for (int i = 0; i < 3; i++)
	{
		point[i] = TranformVector2(point[i]);
	}

	box.left = point[0].x;
	box.right = point[1].x;
	box.top = point[0].y;
	box.bottom = point[2].y;

	return box;
}