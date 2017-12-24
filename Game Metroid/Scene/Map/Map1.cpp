#include "Map1.h"

void Map1::Generating(Camera* camera)
{
	SetStartPoint(0, 0);

	SetMapSize(80, 15);
	int * map[15];

	map[14] = new int[80]{ 18,	0,	0,	0,	18,	0,	0,	0,	18,	0,	0,	0,	18,	0,	0,	0,	30,	0,	0,	0,	0,	0,	31,	0,	2,	0,	0,	0,	0,	0,	0,	0,	30,	0,	0,	0,	0,	0,	31,	0,	30,	0,	0,	0,	0,	0,	31,	0,	30,	0,	0,	0,	0,	0,	31,	0,	30,	0,	0,	0,	0,	0,	31,	0,	30,	0,	0,	0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	0,	17,	0 };
	map[13] = new int[80]{ 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 };
	map[12] = new int[80]{ 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 };
	map[11] = new int[80]{ 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	5,	0,	0,	0,	0,	0,	5,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 };
	map[10] = new int[80]{ 18,	0,	0,	0,	18,	0,	0,	0,	18,	0,	0,	0,	18,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	18,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 };
	map[9] = new int[80]{ 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	17,	0,	0,	0,	0,	17,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	26,	25 };
	map[8] = new int[80]{ 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	18,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 };
	map[7] = new int[80]{ 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 };
	map[6] = new int[80]{ 18,	0,	0,	0,	18,	0,	0,	0,	18,	0,	0,	0,	18,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	18,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	37,	0,	0,	0,	17,	0 };
	map[5] = new int[80]{ 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 };
	map[4] = new int[80]{ 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	40,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 };
	map[3] = new int[80]{ 18,	0,	0,	0,	18,	0,	0,	0,	18,	0,	0,	0,	18,	0,	0,	0,	0,	0,	0,	39,	0,	0,	0,	0,	0,	39,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 };
	map[2] = new int[80]{ 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	42,	42,	0,	0,	0,	42,	42,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 };
	map[1] = new int[80]{ 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	0 };
	map[0] = new int[80]{ 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0 };

	SetMap(map);


	//Box Collider
#pragma region BoxInitialize

	_Box1 = new BlockBox();
	_Box1->Initialize(StartPointX, StartPointY - 16, StartPointX + 16 * 80, StartPointX + 16 * 2);
	_Box1->id = 1;
	_Box1->DebugName = 1;

	_BoxList.push_back(_Box1);

	_Box2 = new BlockBox();
	_Box2->Initialize(StartPointX, StartPointY + 16, StartPointX + 16 * 16, StartPointY + 16 * 13);
	_Box2->id = 1;
	_Box2->DebugName = 2;

	_BoxList.push_back(_Box2);

	_Box3 = new BlockBox();
	_Box3->Initialize(StartPointX + 16 * 16, StartPointY + 16 * 12, StartPointX + 16 * 64, StartPointY + 16 * 2);
	_Box3->id = 1;
	_Box3->DebugName = 3;

	_BoxList.push_back(_Box3);

	_Box4 = new BlockBox();
	_Box4->Initialize(StartPointX + 16 * 19, StartPointY + 16, StartPointX + 16, StartPointY + 16 * 2);
	_Box4->id = 1;
	_Box4->DebugName = 4;

	_BoxList.push_back(_Box4);

	_Box5 = new BlockBox();
	_Box5->Initialize(StartPointX + 16 * 20, StartPointY + 16, StartPointX + 16, StartPointY + 16);
	_Box5->id = 1;
	_Box5->DebugName = 5;

	_BoxList.push_back(_Box5);

	_Box6 = new BlockBox();
	_Box6->Initialize(StartPointX + 16 * 22, StartPointY + 16, StartPointX + 16, StartPointY + 16 * 3);
	_Box6->id = 1;
	_Box6->DebugName = 6;

	_BoxList.push_back(_Box6);

	_Box7 = new BlockBox();
	_Box7->Initialize(StartPointX + 16 * 24, StartPointY + 16, StartPointX + 16, StartPointY + 16);
	_Box7->id = 1;
	_Box7->DebugName = 7;

	_BoxList.push_back(_Box7);

	_Box8 = new BlockBox();
	_Box8->Initialize(StartPointX + 16 * 25, StartPointY + 16, StartPointX + 16, StartPointY + 16 * 2);
	_Box8->id = 1;
	_Box8->DebugName = 8;

	_BoxList.push_back(_Box8);

	_Box9 = new BlockBox();
	_Box9->Initialize(StartPointX + 16 * 26, StartPointY + 16 * 8, StartPointX + 16 * 4, StartPointY + 16 * 2);
	_Box9->id = 1;
	_Box9->DebugName = 9;

	_BoxList.push_back(_Box9);

	_Box10 = new BlockBox();
	_Box10->Initialize(StartPointX + 16 * 26, StartPointY + 16 * 6, StartPointX + 16 * 5, StartPointY + 16 * 2);
	_Box10->id = 1;
	_Box10->DebugName = 10;

	_BoxList.push_back(_Box10);

	_Box11 = new BlockBox();
	_Box11->Initialize(StartPointX + 16 * 27, StartPointY + 16 * 4, StartPointX + 16 * 5, StartPointY + 16 * 2);
	_Box11->id = 1;
	_Box11->DebugName = 11;

	_BoxList.push_back(_Box11);

	_Box12 = new BlockBox();
	_Box12->Initialize(StartPointX + 16 * 28, StartPointY + 16 * 2, StartPointX + 16 * 4, StartPointY + 16 * 2);
	_Box12->id = 1;
	_Box12->DebugName = 12;

	_BoxList.push_back(_Box12);

	_Box13 = new BlockBox();
	_Box13->Initialize(StartPointX + 16 * 37, StartPointY + 16, StartPointX + 16 * 7, StartPointY + 16);
	_Box13->id = 1;
	_Box13->DebugName = 13;

	_BoxList.push_back(_Box13);

	_Box14 = new BlockBox();
	_Box14->Initialize(StartPointX + 16 * 37, StartPointY + 16 * 4, StartPointX + 16, StartPointY + 16 * 7);
	_Box14->id = 1;
	_Box14->DebugName = 14;

	_BoxList.push_back(_Box14);

	_Box15 = new BlockBox();
	_Box15->Initialize(StartPointX + 16 * 38, StartPointY + 16 * 4, StartPointX + 16, StartPointY + 16 * 5);
	_Box15->id = 1;
	_Box15->DebugName = 15;

	_BoxList.push_back(_Box15);

	_Box16 = new BlockBox();
	_Box16->Initialize(StartPointX + 16 * 42, StartPointY + 16 * 4, StartPointX + 16, StartPointY + 16 * 5);
	_Box16->id = 1;
	_Box16->DebugName = 16;

	_BoxList.push_back(_Box16);

	_Box17 = new BlockBox();
	_Box17->Initialize(StartPointX + 16 * 43, StartPointY + 16 * 4, StartPointX + 16, StartPointY + 16 * 7);
	_Box17->id = 1;
	_Box17->DebugName = 17;

	_BoxList.push_back(_Box17);

	_Box18 = new BlockBox();
	_Box18->Initialize(StartPointX + 16 * 74, StartPointY + 16 * 5, StartPointX + 16 * 6, StartPointY + 16);
	_Box18->id = 1;
	_Box18->DebugName = 18;

	_BoxList.push_back(_Box18);

	_Box19 = new BlockBox();
	_Box19->Initialize(StartPointX + 16 * 78, StartPointY + 16, StartPointX + 16 * 2, StartPointY + 16 * 4);
	_Box19->id = 1;
	_Box19->DebugName = 19;

	_BoxList.push_back(_Box19);

	_Box20 = new BlockBox();
	_Box20->Initialize(StartPointX + 16 * 78, StartPointY + 16 * 9, StartPointX + 16 * 2, StartPointY + 16 * 3);
	_Box20->id = 1;
	_Box20->DebugName = 20;

	_BoxList.push_back(_Box20);

#pragma endregion

	_Camera = camera;

	//Initialize Otherthing

	//Init Marumari
	_Marumari = new Marumari();
	_Marumari->SetPosition(StartPointX + 16 * 22.5, StartPointY + 16 * 4.6);
	_Marumari->Initialize();


	//Init Zoomer
	_Zoomer = new Zoomer();
	_Zoomer->SetPosition(16 * 37.5, 16 * 11.5);
	_Zoomer->Initialize();
	_Zoomer->SetType(a);
	_Zoomer->SetPointAmount(7);
	_Zoomer->SetPoint(0, 16 * 37 + 8, 16 * 12 - 8, eOn);
	_Zoomer->SetPoint(1, 16 * 38 + 8, 16 * 12 - 8, eOn);
	_Zoomer->SetPoint(2, 16 * 38 + 8, 16 * 10 - 8, eRight);
	_Zoomer->SetPoint(3, 16 * 39 + 8, 16 * 10 - 8, eOn);
	_Zoomer->SetPoint(4, 16 * 39 + 8, 16 * 4 - 8, eRight);
	_Zoomer->SetPoint(5, 16 * 36 + 8, 16 * 4 - 8, eUnder);
	_Zoomer->SetPoint(6, 16 * 36 + 8, 16 * 12 - 8, eLeft);

	_Zoomer1 = new Zoomer();
	_Zoomer1->SetPosition(16 * 43.5, 16 * 11.5);
	_Zoomer1->Initialize();
	_Zoomer1->SetType(a);
	_Zoomer1->SetPointAmount(7);
	_Zoomer1->SetPoint(0, 16 * 43 + 8, 16 * 12 - 8, eOn);
	_Zoomer1->SetPoint(1, 16 * 44 + 8, 16 * 12 - 8, eOn);
	_Zoomer1->SetPoint(2, 16 * 44 + 8, 16 * 4 - 8, eRight);
	_Zoomer1->SetPoint(3, 16 * 41 + 8, 16 * 4 - 8, eUnder);
	_Zoomer1->SetPoint(4, 16 * 41 + 8, 16 * 10 - 8, eLeft);
	_Zoomer1->SetPoint(5, 16 * 42 + 8, 16 * 10 - 8, eOn);
	_Zoomer1->SetPoint(6, 16 * 42 + 8, 16 * 12 - 8, eLeft);

	//Skree

	_Skree0 = new Skree();
	_Skree0->Initialize();
	_Skree0->SetPosition(16 * 48.5, 16 * 33.5);
	_Skree0->SetType(skree1);
	_Skree0->SetLimitPoint();
	_Skree0->vx = 0;
	_Skree0->vy = 0;
}

void Map1::GetCharacter(Character* ccc)
{
	_Character = ccc;
}

void Map1::UpdateInput()
{
	_Zoomer->Move();
	_Zoomer1->Move();
	_Skree0->Move(_Character->GetPosition().x);
}

void Map1::Update()
{
	if (IsActive())
	{
		for (std::vector<BlockBox*>::iterator it = _BoxList.begin(); it != _BoxList.end(); ++it)
		{
			(*it)->Update();
		}
	}

	// Update Khac

	_Zoomer->Update();
	_Zoomer1->Update();
	_Skree0->Update();
}

void Map1::Draw(int vx, int vy, int vw, int vh)
{
	TilesMap::Draw(vx, vy, vw, vh);

	// Draw Khac

	_Marumari->Draw(vx, vy);
	_Zoomer->Draw(vx, vy);
	_Zoomer1->Draw(vx, vy);
	_Skree0->Draw(vx, vx);
}



void Map1::DrawDebugBox(LPDIRECT3DDEVICE9 id3ddv, int vpx, int vpy)
{
	if (IsActive())
	{
		DebugDraw DebugBox;
		DebugBox.Initialize(id3ddv, vpx, vpy);

		/*for (std::vector<BlockBox*>::iterator it = _BoxList.begin(); it != _BoxList.end(); ++it)
		{
			DebugBox.DrawBox((*it)->Box->GetBoundingBox());
		}*/
	}
}