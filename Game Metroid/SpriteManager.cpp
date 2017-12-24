#include "SpriteManager.h"
#include "AddXML.h"


std::map <eSprite, Sprite*> SpriteManager::SpriteList;
std::map <eTiles, Sprite*> SpriteManager::TilesList;

void SpriteManager::LoadResource()
{
	//SpriteList.clear();
	//======================Character============================
	Sprite* Character;
	Character = new Sprite(d3ddv, TEXT("Resources/Character.bmp"), 574, 1009);

	Character->GetAmount(50);
	for (int i = 0; i <= 49; i++)
	{
		add.queryNodes(L"Resources/sheet1.xml", i + 1, Character->GetPosition()[i].x, Character->GetPosition()[i].y, Character->GetPosition()[i].width, Character->GetPosition()[i].height);
		Character->GetPosition()[i].y = 1009 - Character->GetPosition()[i].y - Character->GetPosition()[i].height;
	}
	

	Character->AddAnimation(Animation::char_appear, char_appear_begin, char_appear_end);
	Character->AddAnimation(Animation::char_stand, char_stand_begin, char_stand_end);
	Character->AddAnimation(Animation::char_stand_up, char_stand_up_begin, char_stand_up_end);
	Character->AddAnimation(Animation::char_stand_shoot, char_stand_shoot_begin, char_stand_shoot_end);
	Character->AddAnimation(Animation::char_run, char_run_begin, char_run_end);
	Character->AddAnimation(Animation::char_jump, char_jump_begin, char_jump_end);
	Character->AddAnimation(Animation::char_flip, char_flip_begin, char_flip_end);
	Character->AddAnimation(Animation::char_roll, char_roll_begin, char_roll_end);
	Character->AddAnimation(Animation::char_run_shoot, char_run_shoot_begin, char_run_shoot_end);
	Character->AddAnimation(Animation::char_run_shoot_up, char_run_shoot_up_begin, char_run_shoot_up_end);
	Character->AddAnimation(Animation::char_jump_shoot_up, char_jump_shoot_up_begin, char_jump_shoot_up_end);
	Character->AddAnimation(Animation::char_fire_stand, char_fire_stand_begin, char_fire_stand_end);
	Character->AddAnimation(Animation::char_fire_shoot, char_fire_shoot_begin, char_fire_shoot_end);
	Character->AddAnimation(Animation::char_fire_shoot_up, char_fire_shoot_up_begin, char_fire_shoot_up_end);
	Character->AddAnimation(Animation::char_fire_run, char_fire_run_begin, char_fire_run_end);
	Character->AddAnimation(Animation::char_fire_jump, char_fire_jump_begin, char_fire_jump_end);
	Character->AddAnimation(Animation::char_fire_flip, char_fire_flip_begin, char_fire_flip_end);
	Character->AddAnimation(Animation::char_fire_roll, char_fire_roll_begin, char_fire_roll_end);
	Character->AddAnimation(Animation::char_fire_run_shoot, char_fire_run_shoot_begin, char_fire_run_shoot_end);
	Character->AddAnimation(Animation::char_fire_jump_shoot, char_fire_jump_shoot_begin, char_fire_jump_shoot_end);
	Character->AddAnimation(Animation::char_fire_run_shoot_up, char_fire_run_shoot_up_begin, char_fire_run_shoot_up_end);
	Character->AddAnimation(Animation::char_fire_jump_shoot_up, char_fire_jump_shoot_up_begin, char_fire_jump_shoot_up_end);

	SpriteList[eCharacter] = Character;
	//============================================================	

	//======================Bullet============================

	Sprite* Bullet;
	Bullet = new Sprite(d3ddv, TEXT("Character.bmp"), 574, 1009);

	Bullet->GetAmount(74);
	for (int i = 0; i <= 73; i++)
	{
		add.queryNodes(L"sheet1.xml", i + 1, Bullet->GetPosition()[i].x, Bullet->GetPosition()[i].y, Bullet->GetPosition()[i].width, Bullet->GetPosition()[i].height);
		Bullet->GetPosition()[i].y = 1009 - Bullet->GetPosition()[i].y - Bullet->GetPosition()[i].height;
	}

	Bullet->AddAnimation(Animation::bullet, bullet_begin, bullet_end);
	Bullet->AddAnimation(Animation::char_run, char_run_begin, char_run_end);

	SpriteList[eBullet] = Bullet;

	//=========================Zoomer=============================
	Sprite* Zoomer;
	Zoomer = new Sprite(d3ddv, TEXT("Resources/Enemies.bmp"), 561, 337);

	Zoomer->GetAmount(32);
	for (int i = 0; i <32; i++)
	{
		add.queryNodes(L"Resources/sheet2.xml", i + 1, Zoomer->GetPosition()[i].x, Zoomer->GetPosition()[i].y, Zoomer->GetPosition()[i].width, Zoomer->GetPosition()[i].height);
		Zoomer->GetPosition()[i].y = 337 - Zoomer->GetPosition()[i].y - Zoomer->GetPosition()[i].height;
	}
	Zoomer->AddAnimation(Animation::zoomer_orange_on, zoomer_orange_on_begin, zoomer_orange_on_end);
	Zoomer->AddAnimation(Animation::zoomer_orange_under, zoomer_orange_under_begin, zoomer_orange_under_end);
	Zoomer->AddAnimation(Animation::zoomer_orange_left, zoomer_orange_left_begin, zoomer_orange_left_end);
	Zoomer->AddAnimation(Animation::zoomer_orange_right, zoomer_orange_right_begin, zoomer_orange_right_end);

	Zoomer->AddAnimation(Animation::zoomer_pink_on, zoomer_pink_on_begin, zoomer_pink_on_end);
	Zoomer->AddAnimation(Animation::zoomer_pink_under, zoomer_pink_under_begin, zoomer_pink_under_end);
	Zoomer->AddAnimation(Animation::zoomer_pink_left, zoomer_pink_left_begin, zoomer_pink_left_end);
	Zoomer->AddAnimation(Animation::zoomer_pink_right, zoomer_pink_right_begin, zoomer_pink_right_end);

	Zoomer->AddAnimation(Animation::zoomer_red_on, zoomer_red_on_begin, zoomer_red_on_end);
	Zoomer->AddAnimation(Animation::zoomer_red_under, zoomer_red_under_begin, zoomer_red_under_end);
	Zoomer->AddAnimation(Animation::zoomer_red_left, zoomer_red_left_begin, zoomer_red_left_end);
	Zoomer->AddAnimation(Animation::zoomer_red_right, zoomer_red_right_begin, zoomer_red_right_end);


	//Zoomer->id = 1;

	SpriteList[eZoomer] = Zoomer;
	//==============================================================

	//===========================Skree==============================
	Sprite* Skree;
	Skree = new Sprite(d3ddv, TEXT("Resources/Enemies.bmp"), 561, 337);

	Skree->GetAmount(46);
	for (int i = 0; i <= 46; i++)
	{
		add.queryNodes(L"Resources/sheet2.xml", i + 1, Skree->GetPosition()[i].x, Skree->GetPosition()[i].y, Skree->GetPosition()[i].width, Skree->GetPosition()[i].height);
		Skree->GetPosition()[i].y = 337 - Skree->GetPosition()[i].y - Skree->GetPosition()[i].height;
	}

	Skree->AddAnimation(Animation::skree_greenyellow_down, skree_greenyellow_down_begin, skree_greenyellow_down_end);
	Skree->AddAnimation(Animation::skree_green, skree_green_begin, skree_green_end);
	Skree->AddAnimation(Animation::skree_blue, skree_blue_begin, skree_blue_end);
	Skree->AddAnimation(Animation::skree_greenorange, skree_greenorange_begin, skree_greenorange_end);
	Skree->AddAnimation(Animation::skree_freeze, skree_freeze_begin, skree_freeze_end);

	SpriteList[eSkree] = Skree;
	//==============================================================

	//===========================Ripper=============================
	Sprite* Ripper;
	Ripper = new Sprite(d3ddv, TEXT("Resources/Enemies.bmp"), 561, 337);

	Ripper->GetAmount(57);
	for (int i = 0; i <= 56; i++)
	{
		add.queryNodes(L"Resources/sheet2.xml", i + 1, Ripper->GetPosition()[i].x, Ripper->GetPosition()[i].y, Ripper->GetPosition()[i].width, Ripper->GetPosition()[i].height);
		Ripper->GetPosition()[i].y = 337 - Ripper->GetPosition()[i].y - Ripper->GetPosition()[i].height;
	}

	Ripper->AddAnimation(Animation::ripper_orangeblue, ripper_orangeblue_begin, ripper_orangeblue_end);

	SpriteList[eRipper] = Ripper;
	//=============================================================

	//===========================Reo===============================
	Sprite* Reo;
	Reo = new Sprite(d3ddv, TEXT("Resources/Enemies.bmp"), 561, 337);

	Reo->GetAmount(50);
	for (int i = 0; i <= 49; i++)
	{
		add.queryNodes(L"Resources/sheet2.xml", i + 1, Reo->GetPosition()[i].x, Reo->GetPosition()[i].y, Reo->GetPosition()[i].width, Reo->GetPosition()[i].height);
		Reo->GetPosition()[i].y = 337 - Reo->GetPosition()[i].y - Reo->GetPosition()[i].height;
	}

	Reo->AddAnimation(Animation::reo_greenyellow, reo_greenyellow_begin, reo_greenyellow_end);

	SpriteList[eReo] = Reo;
	//==============================================================

	//===========================Maru mari==========================
	Sprite* Marumari;
	Marumari = new Sprite(d3ddv, TEXT("Resources/Items.bmp"), 293, 197);

	Marumari->GetAmount(3);
	for (int i = 0; i <= 2; i++)
	{
		add.queryNodes(L"Resources/sheet3.xml", i + 1, Marumari->GetPosition()[i].x, Marumari->GetPosition()[i].y, Marumari->GetPosition()[i].width, Marumari->GetPosition()[i].height);
		Marumari->GetPosition()[i].y = 197 - Marumari->GetPosition()[i].y - Marumari->GetPosition()[i].height;
	}

	Marumari->AddAnimation(Animation::maru_mari, maru_mari_begin, maru_mari_end);

	SpriteList[eMarumari] = Marumari;
	//==============================================================

	//==============================HUD=============================
	Sprite* energy;
	energy = new Sprite(d3ddv, TEXT("Resources/energy.bmp"), 157, 29);
	energy->GetAmount(11);
	for (int i = 0; i <= 10; i++)
	{
		add.queryNodes(L"Resources/hud.xml", i + 1, energy->GetPosition()[i].x, energy->GetPosition()[i].y, energy->GetPosition()[i].width, energy->GetPosition()[i].height);
		energy->GetPosition()[i].y = 29 - energy->GetPosition()[i].y - energy->GetPosition()[i].height;
	}
	energy->AddAnimation(Animation::eEN, 10, 10);
	SpriteList[eEnergy] = energy;

	Sprite* num1;
	num1 = new Sprite(d3ddv, TEXT("Resources/energy.bmp"), 157, 29);
	num1->GetAmount(11);
	for (int i = 0; i <= 10; i++)
	{
		add.queryNodes(L"Resources/hud.xml", i + 1, num1->GetPosition()[i].x, num1->GetPosition()[i].y, num1->GetPosition()[i].width, num1->GetPosition()[i].height);
		num1->GetPosition()[i].y = 29 - num1->GetPosition()[i].y - num1->GetPosition()[i].height;
	}
	num1->AddAnimation(Animation::e0, 0, 0);
	num1->AddAnimation(Animation::e1, 1, 1);
	num1->AddAnimation(Animation::e2, 2, 2);
	num1->AddAnimation(Animation::e3, 3, 3);
	num1->AddAnimation(Animation::e4, 4, 4);
	num1->AddAnimation(Animation::e5, 5, 5);
	num1->AddAnimation(Animation::e6, 6, 6);
	num1->AddAnimation(Animation::e7, 7, 7);
	num1->AddAnimation(Animation::e8, 8, 8);
	num1->AddAnimation(Animation::e9, 9, 9);
	SpriteList[eNum1] = num1;

	Sprite* num2;
	num2 = new Sprite(d3ddv, TEXT("Resources/energy.bmp"), 157, 29);
	num2->GetAmount(11);
	for (int i = 0; i <= 10; i++)
	{
		add.queryNodes(L"Resources/hud.xml", i + 1, num2->GetPosition()[i].x, num2->GetPosition()[i].y, num2->GetPosition()[i].width, num2->GetPosition()[i].height);
		num2->GetPosition()[i].y = 29 - num2->GetPosition()[i].y - num2->GetPosition()[i].height;
	}
	num2->AddAnimation(Animation::e0, 0, 0);
	num2->AddAnimation(Animation::e1, 1, 1);
	num2->AddAnimation(Animation::e2, 2, 2);
	num2->AddAnimation(Animation::e3, 3, 3);
	num2->AddAnimation(Animation::e4, 4, 4);
	num2->AddAnimation(Animation::e5, 5, 5);
	num2->AddAnimation(Animation::e6, 6, 6);
	num2->AddAnimation(Animation::e7, 7, 7);
	num2->AddAnimation(Animation::e8, 8, 8);
	num2->AddAnimation(Animation::e9, 9, 9);
	SpriteList[eNum2] = num2;
	//==============================================================

	Sprite* Tiles[42];
	for (int i = 0; i < 42; i++)
	{
		Tiles[i] = new Sprite(d3ddv, TEXT("Resources/Map1.png"), 333, 350);
		Tiles[i]->GetAmount(1);
		add.queryNodes(L"Resources/sheet4.xml", i+1, Tiles[i]->GetPosition()[0].x, Tiles[i]->GetPosition()[0].y, Tiles[i]->GetPosition()[0].width, Tiles[i]->GetPosition()[0].height);
	
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