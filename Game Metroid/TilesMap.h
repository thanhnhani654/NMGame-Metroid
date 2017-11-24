#pragma once
#include "SpriteManager.h"
#include "Sprite.h"

#define BLOCK_WIDTH 16
#define BLOCK_HEIGHT 16

class TilesMap
{
private:
	int **Map = NULL;
	Sprite **MapObject;
	int SizeX, SizeY;


public:
	void SetMapSize(int sizeX, int sizeY);

	void SetMap(int **map);
	int k = 0;
	/*~TilesMap();*/

	void Draw(int vx, int vy, int vw, int vh);


	TilesMap() {};
};