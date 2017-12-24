#pragma once
#include "GameObject.h"
#include "../Sprite.h"
#include "../SpriteManager.h"
#include "../Define.h"
#include "../Component/BoxCollider.h"

struct PointOfRipper
{
	int x;
	int y;
};

class Ripper : public GameObject
{
private:
	Sprite* RipperSprite;
	Sprite temp;

public:

	BoxCollider* Box;

	int index;

	Ripper()
	{
		RipperSprite = NULL;
	}
	
	PointOfRipper* pnt;

	void Initialize();

	void SetNextPosition(float x, float y);

	void Move();

	void Update();

	void Draw(int vx, int vy) override;

	~Ripper()
	{
		delete RipperSprite;
	}
};