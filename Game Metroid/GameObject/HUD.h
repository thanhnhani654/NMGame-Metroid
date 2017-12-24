#pragma once
#include "GameObject.h"
#include "../Sprite.h"
#include "../SpriteManager.h"
#include "../Define.h"

class HUD : public GameObject
{
private:
	Sprite* energy;
	Sprite* num1;
	Sprite* num2;

public:
	bool isEn = true;;
	HUD()
	{
		energy = NULL;
		num1 = NULL;
		num2 = NULL;
	}
	void Initialize();
	void Update();
	void Draw(int vx, int vy);
	~HUD()
	{
		delete energy;
		delete num1;
		delete num2;
	}
};