#pragma once
#include "Scene.h"
#include "../SpriteManager.h"
#include "../GameObject/Character.h"
class Scene1 : public Scene
{
private:
	Character* _Character;
public:
	bool Init();
	void Update();
	void UpdateInput();
	void Draw();
};