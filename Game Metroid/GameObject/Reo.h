#pragma once
#include "GameObject.h"
#include "../Sprite.h"
#include "../SpriteManager.h"
#include "../Define.h"
#include "../Component/BoxCollider.h"

//struct PointRipper
//{
//	int x;
//	int y;
//};

class Reo : public GameObject
{
private:
	Sprite* ReoSprite;

public:

	BoxCollider* Box;

	//int index;

	Reo()
	{
		ReoSprite = NULL;
	}

	void Initialize();

	/*PointRipper* pnt;

	void SetPoint()
	{
		pnt = new PointRipper[2];
		pnt[0].x = 16 * 31 + 8;
		pnt[0].y = 16 * 10 - 8;
		pnt[1].x = 16 * 34 + 8;
		pnt[1].y = 16 * 10 - 8;
	}*/

	void Move(int n);

	void Update();

	void Draw(int vx, int vy) override;

	~Reo()
	{
		delete ReoSprite;
	}
};