#include "TilesMap.h"

void TilesMap::SetStartPoint(int X, int Y)
{
	StartPointX = X;
	StartPointY = Y;
}

void TilesMap::SetMapSize(int sizeX, int sizeY)
{
	SizeX = sizeX;
	SizeY = sizeY;
	Map = new int *[sizeX];

	for (int i = 0; i < SizeX; i++)
	{
		Map[i] = new int[SizeY];
	}

	MapObject = new Sprite *[sizeX];

	for (int i = 0; i < SizeX; i++)
	{
		MapObject[i] = new Sprite[SizeY];
	}
}

void TilesMap::SetMap(int *map[])
{
	for (int x = 0; x < SizeX; x++)
		for (int y = 0; y < SizeY; y++)
			Map[x][y] = map[y][x];

	for (int x = 0; x < SizeX; x++)
		for (int y = 0; y < SizeY; y++)
		{
			switch (Map[x][y])
			{
			case 0:
				break;
			case 1:
				MapObject[x][y] = *SpriteManager::TilesList[Tile1];
				break;
			case 2:
				MapObject[x][y] = *SpriteManager::TilesList[Tile2];
				break;
			case 3:
				MapObject[x][y] = *SpriteManager::TilesList[Tile3];
				break;
			case 4:
				MapObject[x][y] = *SpriteManager::TilesList[Tile4];
				break;
			case 5:
				MapObject[x][y] = *SpriteManager::TilesList[Tile5];
				break;
			case 6:
				MapObject[x][y] = *SpriteManager::TilesList[Tile6];
				break;
			case 7:
				MapObject[x][y] = *SpriteManager::TilesList[Tile7];
				break;
			case 8:
				MapObject[x][y] = *SpriteManager::TilesList[Tile8];
				break;
			case 9:
				MapObject[x][y] = *SpriteManager::TilesList[Tile9];
				break;
			case 10:
				MapObject[x][y] = *SpriteManager::TilesList[Tile10];
				break;
			case 11:
				MapObject[x][y] = *SpriteManager::TilesList[Tile11];
				break;
			case 12:
				MapObject[x][y] = *SpriteManager::TilesList[Tile12];
				break;
			case 13:
				MapObject[x][y] = *SpriteManager::TilesList[Tile13];
				break;
			case 14:
				MapObject[x][y] = *SpriteManager::TilesList[Tile14];
				break;
			case 15:
				MapObject[x][y] = *SpriteManager::TilesList[Tile15];
				break;
			case 16:
				MapObject[x][y] = *SpriteManager::TilesList[Tile16];
				break;
			case 17:
				MapObject[x][y] = *SpriteManager::TilesList[Tile17];
				break;
			case 18:
				MapObject[x][y] = *SpriteManager::TilesList[Tile18];
				break;
			case 19:
				MapObject[x][y] = *SpriteManager::TilesList[Tile19];
				break;
			case 20:
				MapObject[x][y] = *SpriteManager::TilesList[Tile20];
				break;
			case 21:
				MapObject[x][y] = *SpriteManager::TilesList[Tile21];
				break;
			case 22:
				MapObject[x][y] = *SpriteManager::TilesList[Tile22];
				break;
			case 23:
				MapObject[x][y] = *SpriteManager::TilesList[Tile23];
				break;
			case 24:
				MapObject[x][y] = *SpriteManager::TilesList[Tile24];
				break;
			case 25:
				MapObject[x][y] = *SpriteManager::TilesList[Tile25];
				break;
			case 26:
				MapObject[x][y] = *SpriteManager::TilesList[Tile26];
				break;
			case 27:
				MapObject[x][y] = *SpriteManager::TilesList[Tile27];
				break;
			case 28:
				MapObject[x][y] = *SpriteManager::TilesList[Tile28];
				break;
			case 29:
				MapObject[x][y] = *SpriteManager::TilesList[Tile29];
				break;
			case 30:
				MapObject[x][y] = *SpriteManager::TilesList[Tile30];
				break;
			case 31:
				MapObject[x][y] = *SpriteManager::TilesList[Tile31];
				break;
			case 32:
				MapObject[x][y] = *SpriteManager::TilesList[Tile32];
				break;
			case 33:
				MapObject[x][y] = *SpriteManager::TilesList[Tile33];
				break;
			case 34:
				MapObject[x][y] = *SpriteManager::TilesList[Tile34];
				break;
			case 35:
				MapObject[x][y] = *SpriteManager::TilesList[Tile35];
				break;
			case 36:
				MapObject[x][y] = *SpriteManager::TilesList[Tile36];
				break;
			case 37:
				MapObject[x][y] = *SpriteManager::TilesList[Tile37];
				break;
			case 38:
				MapObject[x][y] = *SpriteManager::TilesList[Tile38];
				break;
			case 39:
				MapObject[x][y] = *SpriteManager::TilesList[Tile39];
				break;
			case 40:
				MapObject[x][y] = *SpriteManager::TilesList[Tile40];
				break;
			case 41:
				MapObject[x][y] = *SpriteManager::TilesList[Tile41];
				break;
			case 42:
				MapObject[x][y] = *SpriteManager::TilesList[Tile42];
				break;

			default:
				break;
			}
		}
}

void TilesMap::Draw(int vx, int vy, int vw, int vh)
{
	if (IsActive())
	{
		for (int x = 0; x < SizeX; x++)
			for (int y = 0; y < SizeY; y++)
			{
				if (Map[x][y] != 0)
				{
					MapObject[x][y].SetIsMap(true);
					MapObject[x][y].Render(x * BLOCK_WIDTH + StartPointX, y * BLOCK_HEIGHT + StartPointY, vx, vy);
				}

			}
	}
}

void TilesMap::MapActive()
{
	bActive = true;
}

void TilesMap::MapDeActive()
{
	bActive = false;
}

bool TilesMap::IsActive()
{
	return bActive;
}

void TilesMap::Update()
{

}

void TilesMap::UpdateInput()
{

}