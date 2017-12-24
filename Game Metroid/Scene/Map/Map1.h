#pragma once

#include "..\..\TilesMap.h"
#include "..\..\GameObject\GameObject.h"
#include "..\..\GameObject\BlockBox.h"
#include "..\..\DebugBox.h"
#include "..\..\GameObject\Camera.h"
#include "..\..\GameObject\Zoomer.h"
#include "..\..\GameObject\Skree.h"
#include "..\..\GameObject\Marumari.h"
#include "..\..\GameObject\character.h"

class Map1 : public TilesMap
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
	Character* _Character;

	Marumari* _Marumari;
	Zoomer* _Zoomer, *_Zoomer1, *_Zoomer2, *_Zoomer3;
	Skree* _Skree0, *_Skree1, *_Skree2;


public:

	//DebugDraw DebugBox;

	void Generating(Camera* camera);

	void GetCharacter(Character* ccc);

	void UpdateInput();

	void Update();

	void Draw(int vx, int vy, int vw, int vh);

	void DrawDebugBox(LPDIRECT3DDEVICE9 id3ddv, int vpx, int vpy);
};