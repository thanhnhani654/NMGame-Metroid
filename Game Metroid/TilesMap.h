#pragma once
#include <vector>
#include "GameObject\BlockBox.h"
#include "SpriteManager.h"
#include "Sprite.h"

#define BLOCK_WIDTH 16
#define BLOCK_HEIGHT 16

using namespace std;

class TilesMap
{
protected:
	int **Map = NULL;
	Sprite **MapObject;
	int SizeX, SizeY;
	int StartPointX;
	int StartPointY;

	bool bActive;

	std::vector<BlockBox*> _BoxList;

public:
	void SetStartPoint(int X, int Y);

	void SetMapSize(int sizeX, int sizeY);

	void SetMap(int **map);

	/*~TilesMap();*/

	virtual void Draw(int vx, int vy, int vw, int vh);

	virtual void UpdateInput();

	virtual void Update();

	TilesMap() { StartPointX = 0; StartPointY = 0; };

	virtual void MapActive();
	virtual void MapDeActive();
	bool IsActive();
};