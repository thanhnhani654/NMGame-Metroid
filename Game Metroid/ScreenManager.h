#pragma once
#include "Scene\Scene.h"
#include "Scene\Scene1.h"
#include <vector>

using namespace std;

class ScreenManager
{
public:
	bool Init();

	void LoadScene();

	void AddScene(Scene* sce);

	bool ActiveScene(int index);

	void UpdateInput();

	void Update();

	void Draw();


private:
	vector <Scene*> _listscene;

	Scene* CurrentScene;
};
