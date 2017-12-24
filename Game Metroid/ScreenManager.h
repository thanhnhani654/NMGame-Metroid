#pragma once
#include "Scene\Scene.h"
#include "Scene\Scene1.h"
#include "Define.h"
#include <vector>

using namespace std;

class ScreenManager
{
public:
	bool Init(LPDIRECT3DDEVICE9 id3ddv);

	void LoadScene();

	void AddScene(Scene* sce);

	bool ActiveScene(int index);

	void UpdateInput();

	void Update();

	void Draw();

	LPDIRECT3DDEVICE9 d3ddv;

private:
	vector <Scene*> _listscene;

	Scene* CurrentScene;
};
