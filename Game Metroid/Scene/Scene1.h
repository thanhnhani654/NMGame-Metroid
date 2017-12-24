#pragma once
#include "Scene.h"
#include "../SpriteManager.h"
#include "../GameObject/Character.h"
#include "../Component/Controllable.h"
#include "../DebugBox.h"
#include "../GameObject/BlockBox.h"
#include "../Scene/Map/Map1.h"
#include "../Scene/Map/Map2.h"
#include "../GameObject/Zoomer.h"
#include "../GameObject/Skree.h"
#include "../GameObject/Bullet.h"
#include "../GameObject/Camera.h"
#include "../GameObject/Gate.h"
#include "../GameObject/GateLeft.h"

class Scene1 : public Scene
{
private:
	Character* _Character;
	BlockBox* _BlockBox;
	Map1* _Map1;
	Map2* _Map2;
	Zoomer* _Zoomer;
	Camera* _Camera;
	/*Gate* _Gate;
	GateLeft* _GateLeft;*/
	
public:
	bool Init();
	void Update();
	void UpdateInput();
	void Draw();
	int test = 0;

	//debug
	DebugDraw debug;
};