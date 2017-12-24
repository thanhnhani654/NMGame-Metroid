#pragma once
#include "..\TilesMap.h"
class  Scene
{
protected:
	LPDIRECT3DDEVICE9 d3ddv;
public:

	virtual bool Init() { return true; }
	virtual void Update() {};
	virtual void UpdateInput() {};
	virtual void Draw() {};
	void GetDevice(LPDIRECT3DDEVICE9 id3ddv) { d3ddv = id3ddv; }

};