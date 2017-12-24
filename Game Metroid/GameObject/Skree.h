#pragma once
#include "GameObject.h"
#include "../Sprite.h"
#include "../SpriteManager.h"
#include "../Define.h"
#include "../Component/BoxCollider.h"

enum TypeSkree
{
	skree1, skree2, skree3, skree4, skree5
};
	
class Skree : public GameObject
{
private:
	Sprite* SkreeSprite;
	Sprite temp;
	float limitpointleft;
	float limitpointright;
	bool IsGround;
public:
	TypeSkree Type;
	BoxCollider *Box;
	Skree()
	{
		SkreeSprite = NULL;
	}

	void Initialize();
	void SetType(TypeSkree t) { Type = t; }
	void SetLimitPoint()
	{
		limitpointleft = position.x - 16 * 2;
		limitpointright = position.x + 16 * 2;
	}

	bool OnCollision(GameObject* object);

	void SetGround() { IsGround = true; }

	void Move(float x);

	void Update();

	void Draw(int vx, int vy) override;

	~Skree()
	{
		delete SkreeSprite;
	}
};