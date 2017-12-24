#pragma once
#include "GameObject.h"
#include "../Sprite.h"
#include "../SpriteManager.h"
#include "../Define.h"
#include "../Component/BoxCollider.h"
#include "../CollisionWorld.h"

class Marumari : public GameObject
{
private:
	Sprite* MarumariSprite;

public:

	BoxCollider* Box;

	Marumari()
	{
		MarumariSprite = NULL;
	}

	void Initialize();

	void Draw(int vx, int vy) override;
	
	void Destroy();

	bool OnCollision(GameObject *object);

	~Marumari()
	{
		delete MarumariSprite;
	}
};