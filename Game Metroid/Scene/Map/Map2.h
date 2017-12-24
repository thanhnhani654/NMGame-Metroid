#pragma once
#include "..\..\TilesMap.h"
#include "..\..\GameObject\GameObject.h"
#include "..\..\GameObject\BlockBox.h"
#include "..\..\DebugBox.h"
#include "..\..\GameObject\Camera.h"

class Map2 : public TilesMap
{
private:
	BlockBox* _Box1;
	BlockBox* _Box2;
	BlockBox* _Box3;
	BlockBox* _Box4;
	BlockBox* _Box5;
	BlockBox* _Box6;
	BlockBox* _Box7;
	BlockBox* _Box8;
	BlockBox* _Box9;
	BlockBox* _Box10;
	BlockBox* _Box11;
	BlockBox* _Box12;
	BlockBox* _Box13;
	BlockBox* _Box14;
	BlockBox* _Box15;
	BlockBox* _Box16;
	BlockBox* _Box17;
	BlockBox* _Box18;
	BlockBox* _Box19;
	BlockBox* _Box20;
	BlockBox* _Box21;
	BlockBox* _Box22;


	Camera* _Camera;

public:

	//DebugDraw DebugBox;

	void Generating(Camera* camera);

	void MapActive();
	//void MapDeActive();

	void Update();

	void DrawDebugBox(LPDIRECT3DDEVICE9 id3ddv, int vpx, int vpy);

};

