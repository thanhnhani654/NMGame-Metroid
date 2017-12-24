#pragma once
#include "GameObject.h"
#include "../Component/BoxCollider.h"
#include "../SpriteManager.h"
#include "../Sprite.h"
#include "../TilesMap.h"


class Gate : public GameObject
{
private:
	Sprite GateSprite;

	TilesMap* _NextMap;
	TilesMap* _OwnMap;

public:
	BoxCollider* Box;

	void Initialize();

	void SetPosition(float x, float y);

	void GetMap(TilesMap* ownmap, TilesMap* nextmap);

	void Update();

	void Draw(int vpx, int vpy);

	bool OnCollision(GameObject* object);
};