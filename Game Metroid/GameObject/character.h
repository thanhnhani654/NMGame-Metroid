#pragma once
#include "GameObject.h"
#include "../Sprite.h"
#include "../SpriteManager.h"



class Character : public GameObject
{

private:
	Sprite* CharacterSprite;


public:

	Character() { CharacterSprite = NULL; }

	void Initialize();

	void Update() override;

	void Draw(int vx, int vy) override;

	~Character()
	{
		delete CharacterSprite;
	}
};
