#include "GateLeft.h"

void GateLeft::Initialize()
{
	id = 10;
	GateSprite = *SpriteManager::TilesList[eTiles::Tile26];
	GateSprite.Flip();


	this->width = GateSprite.GetCurrentPosition().width;
	this->height = GateSprite.GetCurrentPosition().height;

	Box = new BoxCollider();
	//Box->SetBox(position.x - (width / 2), position.y - (height / 2), width, height);
	Box->SetBox(position.x, position.y, width, height);
	Box->AttachObject(this);
	Box->Type = eType::Static;
	Box->SetTrigger(true);
}

void GateLeft::SetPosition(float x, float y)
{
	GameObject::SetPosition(x, y);

	Box->SetPosition(x, y);
}

void GateLeft::Update()
{
	Box->Update();
}

void GateLeft::Draw(int vpx, int vpy)
{
	GateSprite.SetIsMap(true);
	GateSprite.Render(position.x, position.y, vpx, vpy);
}

void GateLeft::GetMap(TilesMap* ownmap, TilesMap* nextmap)
{
	_OwnMap = ownmap;
	_NextMap = nextmap;
}

bool GateLeft::OnCollision(GameObject* object)
{
	switch (object->id)
	{
	case 0:
		_NextMap->MapActive();
		//_OwnMap->MapDeActive();
		break;

	default:
		break;
	}

	return true;
}