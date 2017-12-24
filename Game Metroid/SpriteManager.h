#pragma once
#include "Sprite.h"
#include <map>
#include "AddXML.h"


using namespace std;

enum eSprite
{
	eCharacter,
	eZoomer,
	eSkree,
	eRipper,
	eReo,
	eMarumari,
	eEnergy,
	eNum1,
	eNum2,
	eBullet,

};

enum eTiles
{
	Tile1 = 0,
	Tile2 = 1,
	Tile3 = 2,
	Tile4 = 3,
	Tile5 = 4,
	Tile6 = 5,
	Tile7 = 6,
	Tile8 = 7,
	Tile9 = 8,
	Tile10 = 9,
	Tile11 = 10,
	Tile12 = 11,
	Tile13 = 12,
	Tile14 = 13,
	Tile15 = 14,
	Tile16 = 15,
	Tile17 = 16,
	Tile18 = 17,
	Tile19 = 18,
	Tile20 = 19,
	Tile21 = 20,
	Tile22 = 21,
	Tile23 = 22,
	Tile24 = 23,
	Tile25 = 24,
	Tile26 = 25,
	Tile27 = 26,
	Tile28 = 27,
	Tile29 = 28,
	Tile30 = 29,
	Tile31 = 30,
	Tile32 = 31,
	Tile33 = 32,
	Tile34 = 33,
	Tile35 = 34,
	Tile36 = 35,
	Tile37 = 36,
	Tile38 = 37,
	Tile39 = 38,
	Tile40 = 39,
	Tile41 = 40,
	Tile42 = 41,
};



class SpriteManager
{
private:
	
	Sprite* temp;
public:
	LPDIRECT3DDEVICE9 d3ddv;
	SpriteManager(void){}
	AddXML add;
	static std::map <eSprite, Sprite*> SpriteList;
	static std::map <eTiles, Sprite*> TilesList;

	void LoadResource();

	void Render();

	void Initialize(LPDIRECT3DDEVICE9 id3ddv) { d3ddv = id3ddv;}

	~SpriteManager()
	{
	}
};
