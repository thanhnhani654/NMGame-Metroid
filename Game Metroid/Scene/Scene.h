#pragma once
#include "..\TilesMap.h"

class  Scene
{
protected:
	TilesMap Map;
	int ViewPortX;
	int ViewPortY;
	int ViewPortWidth;
	int ViewPortHeight;
public:

	virtual bool Init() { return true; }
	virtual void Update() {};
	virtual void UpdateInput() {};
	virtual void Draw() {};

};