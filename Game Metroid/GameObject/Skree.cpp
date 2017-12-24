#include "Skree.h"

void Skree::Initialize()
{
	id = 3;
	SkreeSprite = nullptr;
	SkreeSprite = &temp;
	SkreeSprite = SpriteManager::SpriteList[eSkree];

	Box = new BoxCollider();
	Box->SetBox(position.x - (width / 2), position.y - (height / 2), width, height);
	Box->AttachObject(this);
	Box->Type = eType::Dynamic;

	Box->SetTrigger(true);

}

bool Skree::OnCollision(GameObject * object)
{
	switch (object->id)
	{
	case 1:
		vy = 0;
	}
	return true;
}

void Skree::Move(float x)
{
	if (x >= limitpointleft && x <= limitpointright)
	{
		vy = -1;
		if (position.x > x)
			vx = -0.7;
		if (position.x < x)
			vx = 0.7;
	}
}

void Skree::Update()
{
	position.x += vx;
	position.y += vy;
	Box->Update();
	switch (Type)
	{
	case skree1:
		SkreeSprite->SetStatus(Animation::skree_greenyellow_down);
		break;
	case skree2:
		SkreeSprite->SetStatus(Animation::skree_green);
		break;
	case skree3:
		SkreeSprite->SetStatus(Animation::skree_blue);
		break;
	case skree4:
		SkreeSprite->SetStatus(Animation::skree_greenorange);
		break;
	case skree5:
		SkreeSprite->SetStatus(Animation::skree_freeze);
		break;
	default:
		break;
	}
}

void Skree::Draw(int vx, int vy)
{
	if (SkreeSprite != NULL)
	{
		SkreeSprite->Render(position.x, position.y, vx, vy);
		SkreeSprite->Next();
	}
}

