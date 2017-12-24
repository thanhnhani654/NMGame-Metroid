#include "Marumari.h"

void Marumari::Initialize()
{
	MarumariSprite = nullptr;
	MarumariSprite = SpriteManager::SpriteList[eMarumari];
	MarumariSprite->SetStatus(maru_mari);
	this->vx = 0;
	this->vy = 0;

	id = 5;
	this->width = MarumariSprite->GetCurrentPosition().width;
	this->height = MarumariSprite->GetCurrentPosition().height;

	Box = new BoxCollider();
	Box->SetBox(position.x - (width / 2), position.y - (height / 2), width, height);
	Box->AttachObject(this);
	Box->Type = eType::Static;
	Box->SetTrigger(true);

}

void Marumari::Draw(int vx, int vy)
{
	if (IsUpdate)
	{
		if (MarumariSprite != NULL)
		{
			MarumariSprite->Render(position.x, position.y, vx, vy);
			MarumariSprite->Next();
		}
	}
}

void Marumari::Destroy()
{
	IsUpdate = false;
	IsCollision = false;
}

bool Marumari::OnCollision(GameObject* object)
{
	return true;
}


