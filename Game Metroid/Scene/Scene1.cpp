#include "Scene1.h"
#include "../Utility.h"

bool Scene1::Init()
{
	//Initialize Chacracter
	_Character = new Character();
	_Character->Initialize();
	_Character->SetPosition(16 * 41, 16*3, 0);// 16 * 17, 16 * 2);
	_Character->vx = 0;


	//Initialize Camera
	_Camera = new Camera();
	_Camera->Initialize();
	_Camera->SetAttachObject(_Character);
	_Camera->FollowObjectOn();
	_Camera->SetFollowX();
	_Character->GetCamera(_Camera);

	//Initialize Map

	_Map1 = new Map1();
	_Map1->Generating(_Camera);
	_Map1->GetCharacter(_Character);
	_Map1->MapActive();
	

	_Map2 = new Map2();
	_Map2->Generating(_Camera);
	//_Map2->MapActive();

	Utility::gameCamera->x = _Camera->GetPosition().x;
	Utility::gameCamera->y = _Camera->GetPosition().y;

	//Initialize Gate
	//_Gate = new Gate();
	//_Gate->Initialize();
	//_Gate->SetPosition(16 * 78, 16 * 6);
	//_Gate->GetMap(_Map1, _Map2);

	//_GateLeft = new GateLeft();
	//_GateLeft->Initialize();
	//_GateLeft->SetPosition(16 * 82, 16 * 6);
	//_GateLeft->GetMap(_Map2, _Map1);

	return true;
}

void Scene1::Update()
{
	_Map1->Update();
	_Map2->Update();
	_Character->Update();

	_Camera->Update();

	Utility::gameCamera->x = _Camera->GetPosition().x;
	Utility::gameCamera->y = _Camera->GetPosition().y;

}

void Scene1::UpdateInput()
{
	_Character->UpdateInput();
	_Map1->UpdateInput();
}

void Scene1::Draw()
{
	//_Gate->Draw(_Camera->GetPosition().x, _Camera->GetPosition().y);

	_Character->Draw(_Camera->GetPosition().x, _Camera->GetPosition().y);

	_Map1->Draw(_Camera->GetPosition().x, _Camera->GetPosition().y, _Camera->GetWidth(), _Camera->GetHieght());
	_Map1->DrawDebugBox(d3ddv, _Camera->GetPosition().x, _Camera->GetPosition().y);

	_Map2->Draw(_Camera->GetPosition().x, _Camera->GetPosition().y, _Camera->GetWidth(), _Camera->GetHieght());
	_Map2->DrawDebugBox(d3ddv, _Camera->GetPosition().x, _Camera->GetPosition().y);

	//debug.DrawBox(_Character->Box->GetBoundingBox());

}
