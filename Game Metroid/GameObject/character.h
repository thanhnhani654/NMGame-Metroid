#pragma once
#include "GameObject.h"
#include "../Sprite.h"
#include "../SpriteManager.h"
#include "../Component/Controllable.h"
#include "../Define.h"



class Character : public GameObject
{

private:
	Sprite* CharacterSprite;

	Controllable* Controller;


public:

	Character() { CharacterSprite = NULL; }

	void Initialize();

	void Update() override;

	void UpdateInput() override;

	void Draw(int vx, int vy) override;

	void Moving();

	~Character()
	{
		delete CharacterSprite;
	}
};
