#pragma once
#include "GameObject.h"
#include "../Sprite.h"
#include "../SpriteManager.h"
#include "../Define.h"
#include "../Component/BoxCollider.h"

enum eBeforeState
{
	eOn,
	eRight,
	eUnder,
	eLeft,
};
enum TypeZoomer
{
	a,
	b,
	c,
	d,
};

struct PointOfZoomer
{
	int x;
	int y;
	eBeforeState beforeState;

};



class Zoomer : public GameObject
{
private:
	Sprite* ZoomerSprite;
	int MaxPoint;
	Sprite temp;

public:
	PointOfZoomer* pnt;
	BoxCollider* Box;
	TypeZoomer Type;
	int index;

	Zoomer()
	{
		ZoomerSprite = NULL;
	}

	void Initialize();

	void SetType(TypeZoomer t) { Type = t; }

	void SetPointAmount(int n)
	{
		pnt = new PointOfZoomer[n];
		MaxPoint = n;
	}

	int GetMaxPoint()
	{
		return MaxPoint;
	}

	void SetPoint(int i, int x, int y, eBeforeState t) 
	{
		pnt[i].x = x;
		pnt[i].y = y;
		pnt[i].beforeState = t;
	}

	void Move();

	void Update();

	void Draw(int vx, int vy) override;

	~Zoomer()
	{
		delete ZoomerSprite;
	}
};