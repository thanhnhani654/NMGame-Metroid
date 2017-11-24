#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "ScreenManager.h"
#include "GameObject\GameObject.h"
#include "Component\BoxCollider.h"
#include "CollisionWorld.h"
#include "SpriteManager.h"
#include "GameObject\Character.h"
#include "TilesMap.h"

class  Game
{
private:
	LPDIRECT3D9 d3d = nullptr;
	LPDIRECT3DDEVICE9 d3ddv;
	LPDIRECT3DSURFACE9 surface = NULL;
	LPDIRECT3DSURFACE9 back_buffer = NULL;
	ScreenManager Screen;
	SpriteManager* _SpriteManager;
	TilesMap map1;
	
	//Test Area
	

public:
	bool GameInit(HWND hwnd);
	bool GameRun(HWND hwnd);
	bool GameRelease();

	

	void UpdateInput(HWND hwnd);
	void Update();
	void Draw();

	void test();

	int test2(int t) { t = 1; return t; }

};

