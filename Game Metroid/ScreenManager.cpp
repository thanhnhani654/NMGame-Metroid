#include "ScreenManager.h"

bool ScreenManager::Init()
{
	if (!_listscene.empty())
	{
		_listscene.clear();
	}
	CurrentScene = NULL;

	return true;
}

void ScreenManager::LoadScene()
{
	Scene1* scene1;
	scene1 = new Scene1();
	AddScene(scene1);
}

void ScreenManager::AddScene(Scene* sce)
{
	_listscene.push_back(sce);
}

bool ScreenManager::ActiveScene(int index)
{
	if (_listscene.size() < index)
	{
		return false;
	}
	CurrentScene = _listscene.at(index);

	CurrentScene->Init();

	return true;
}

void ScreenManager::UpdateInput()
{
	if (CurrentScene == NULL)
	{
		MessageBox(NULL, TEXT("NULL"), TEXT("NULL"), NULL);
		return;
	}
	CurrentScene->UpdateInput();
}

void ScreenManager::Update()
{
	if (CurrentScene == NULL)
		return;
	CurrentScene->Update();
}

void ScreenManager::Draw()
{
	if (CurrentScene == NULL)
		return;
	CurrentScene->Draw();
}