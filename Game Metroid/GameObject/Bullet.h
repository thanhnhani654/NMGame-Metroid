#pragma once
#include "GameObject.h"
#include "../Sprite.h"
#include "../SpriteManager.h"
#include "../Define.h"
#include "../Component/BoxCollider.h"
#include <vector>
#include <map>

class Bullet : public GameObject
{
private:
	Sprite* BulletSprite;

	static vector <Bullet*> _listBullet;

public:

	float limitXleft;
	float limitXright;
	float limitY;

	int lifespan;

	BoxCollider* Box;

	Bullet() { _listBullet.push_back(this); }

	~Bullet();

	static bool IsEmpty();

	static vector <Bullet*> &GetList();

	void Initialize();

	void Update();

	void SetVelocity(float ivx, float ivy);

	void Draw(int vpx, int vpy);

	void Destroy();

};