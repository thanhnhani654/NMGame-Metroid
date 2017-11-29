#include "SpriteManager.h"
#include "AddXML.h"


std::map <eSprite, Sprite*> SpriteManager::SpriteList;
std::map <eTiles, Sprite*> SpriteManager::TilesList;

void SpriteManager::LoadResource()
{
	//SpriteList.clear();

	Sprite* Character;
	Character = new Sprite(d3ddv, TEXT("Character.bmp"), 574, 1009);

	Character->GetAmount(50);
	for (int i = 0; i <= 49; i++)
	{
		add.queryNodes(L"sheet1.xml", i + 1, Character->GetPosition()[i].x, Character->GetPosition()[i].y, Character->GetPosition()[i].width, Character->GetPosition()[i].height);
		Character->GetPosition()[i].y = 1009 - Character->GetPosition()[i].y - Character->GetPosition()[i].height;
	}

	Character->AddAnimation(Animation::char_appear, char_appear_begin, char_appear_end);
	Character->AddAnimation(Animation::char_run, char_run_begin, char_run_end);
	Character->AddAnimation(Animation::char_stand, char_stand_begin, char_stand_end);

	SpriteList[eCharacter] = Character;
	/*temp = Character;*/
	Sprite* Tiles[42];
	for (int i = 0; i < 42; i++)
	{
		Tiles[i] = new Sprite(d3ddv, TEXT("Resource/Map1.png"), 333, 350);
		Tiles[i]->GetAmount(1);
		add.queryNodes(L"Resource/sheet4.xml", i+1, Tiles[i]->GetPosition()[0].x, Tiles[i]->GetPosition()[0].y, Tiles[i]->GetPosition()[0].width, Tiles[i]->GetPosition()[0].height);
	
		int k = 0;
	}

	TilesList[eTiles::Tile1] = Tiles[0];
	TilesList[eTiles::Tile2] = Tiles[1];
	TilesList[eTiles::Tile3] = Tiles[2];
	TilesList[eTiles::Tile4] = Tiles[3];
	TilesList[eTiles::Tile5] = Tiles[4];
	TilesList[eTiles::Tile6] = Tiles[5];
	TilesList[eTiles::Tile7] = Tiles[6];
	TilesList[eTiles::Tile8] = Tiles[7];
	TilesList[eTiles::Tile9] = Tiles[8];
	TilesList[eTiles::Tile10] = Tiles[9];
	TilesList[eTiles::Tile11] = Tiles[10];
	TilesList[eTiles::Tile12] = Tiles[11];
	TilesList[eTiles::Tile13] = Tiles[12];
	TilesList[eTiles::Tile14] = Tiles[13];
	TilesList[eTiles::Tile15] = Tiles[14];
	TilesList[eTiles::Tile16] = Tiles[15];
	TilesList[eTiles::Tile17] = Tiles[16];
	TilesList[eTiles::Tile18] = Tiles[17];
	TilesList[eTiles::Tile19] = Tiles[18];
	TilesList[eTiles::Tile20] = Tiles[19];
	TilesList[eTiles::Tile21] = Tiles[20];
	TilesList[eTiles::Tile22] = Tiles[21];
	TilesList[eTiles::Tile23] = Tiles[22];
	TilesList[eTiles::Tile24] = Tiles[23];
	TilesList[eTiles::Tile25] = Tiles[24];
	TilesList[eTiles::Tile26] = Tiles[25];
	TilesList[eTiles::Tile27] = Tiles[26];
	TilesList[eTiles::Tile28] = Tiles[27];
	TilesList[eTiles::Tile29] = Tiles[28];
	TilesList[eTiles::Tile30] = Tiles[29];
	TilesList[eTiles::Tile31] = Tiles[30];
	TilesList[eTiles::Tile32] = Tiles[31];
	TilesList[eTiles::Tile33] = Tiles[32];
	TilesList[eTiles::Tile34] = Tiles[33];
	TilesList[eTiles::Tile35] = Tiles[34];
	TilesList[eTiles::Tile36] = Tiles[35];
	TilesList[eTiles::Tile37] = Tiles[36];
	TilesList[eTiles::Tile38] = Tiles[37];
	TilesList[eTiles::Tile39] = Tiles[38];
	TilesList[eTiles::Tile40] = Tiles[39];
	TilesList[eTiles::Tile41] = Tiles[40];
	TilesList[eTiles::Tile42] = Tiles[41];
}


void SpriteManager::Render()
{
	/*SpriteList[eCharacter]->Render(X, Y, NULL);
	SpriteList[eCharacter]->Next();*/
	/*temp->Render(X, Y, NULL);*/
}